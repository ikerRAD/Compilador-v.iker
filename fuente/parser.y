%define parse.error verbose

%{
   #include <stdio.h>
   #include <iostream>
   #include <vector>
   #include <string>
   using namespace std; 

   extern int yylex();
   extern int yylineno;
   extern char *yytext;
   void yyerror (const char *msg) {
     printf("line %d: %s at '%s'\n", yylineno, msg, yytext) ;
   }

   #include "Codigo.hpp"
   #include "Exp.hpp"
   #include "TablaSimbolos.hpp"
   #include "PilaTablaSimbolos.hpp"
   #include <sstream>

   expresionstruct makecomparison(std::string &s1, const std::string &s2, std::string &s3) ;
   expresionstruct makearithmetic(std::string &s1, std::string &s2, std::string &s3) ;
   vector<int> *unir(vector<int> lis1, vector<int> lis2);
   vector<string> *unir2(vector<string> lis1, vector<string> lis2);
   sentenciastruct makecontinue();
   void imprimir_errores();
   Codigo codigo;
   PilaTablaSimbolos pila;
   string procActual;
   vector<int> errores;
   vector<string> msgs;
   int numErrores = 0;


%}

/* 
   qué atributos tienen los tokens 
*/
%union {
    string *str ;
    vector<string> *list ;
    expresionstruct *expr ;
    sentenciastruct *sent ;
    int number ;
    vector<int> *numlist;
    casestruct *cses;
    ctestruct *constant;
    lexprstruct *lexpr;
}

/* 
   declaración de tokens. Esto debe coincidir con tokens.l 
*/
%token <str> RPROGRAM RBEGIN RENDPROGRAM RDEF RMAIN RLET RIN RIF RELSE RWHILE RBREAK RFOREVER RCONTINUE RPRINTLN RREAD RINT RFLOAT RELSEIF RSWITCH RCASE RDEFAULT RFOR

%token <str> TABRIRLLAVE TCERRARLLAVE TABRIRPAREN TCERRARPAREN TEQ TDOSPT TSEMIC TAMP TCOMA TPTPT

%token <str> OMULT OSUM OREST ODIV CEQ CLT CGT CLE CGE CNE OOR ONOT OAND

%token <str>  TIDENTIFIER TDOUBLE TINTEGER


%type <str> programa
%type <str> bloque_ppl
%type <str> decl_bl
%type <str> declaraciones
%type <list> lista_de_ident resto_lista_id
%type <str> tipo
%type <str> decl_de_subprogs
%type <str> decl_de_subprograma
%type <str> argumentos
%type <str> lista_de_param
%type <str> clase_par
%type <str> resto_lis_de_param
%type <sent> bloque lista_de_sentencias sentencia parte_else
%type <str> variable
%type <expr> expresion
%type <number> M
%type <cses> cases r_cases
%type <numlist> N
%type <constant> cte
%type <lexpr> lista_expresiones resto_lista_expr

%start programa

%left OOR
%left OAND
%left ONOT
%nonassoc CEQ CGT CGE CLT CLE CNE
%left OSUM OREST
%left OMULT ODIV

%%

programa : RDEF RMAIN TABRIRPAREN TCERRARPAREN TDOSPT { 
		codigo.anadirInstruccion("goto 11;");
		codigo.anadirInstruccion("write \"Error, el salto del bucle for debe ser distinto de 0\";");
		codigo.anadirInstruccion("writeln;");
		codigo.anadirInstruccion("goto");
		codigo.anadirInstruccion("write \"Error, el bucle tipo for es infinito\";");
		codigo.anadirInstruccion("writeln;");
		codigo.anadirInstruccion("goto");
		codigo.anadirInstruccion("write \"Error, división entre 0. Resultado indefinido\";");
		codigo.anadirInstruccion("writeln;");
		codigo.anadirInstruccion("goto");
		codigo.anadirInstruccion("proc main;"); 
		TablaSimbolos st; pila.empilar(st);
	   } 
	   bloque_ppl
           { 
		pila.desempilar();
		if (numErrores > 0){
		   imprimir_errores(); 
		}else{
		vector<int> tmp; tmp.push_back(4);
		tmp.push_back(7);
		tmp.push_back(10);
		codigo.completarInstrucciones(tmp, codigo.obtenRef());
		codigo.anadirInstruccion("halt;" ) ;
             	codigo.escribir();
		}
	   }
         ;

bloque_ppl : decl_bl TABRIRLLAVE
        decl_de_subprogs
        lista_de_sentencias
        TCERRARLLAVE {
		if(!$4->exit.empty()) {
		  stringstream refer1;
		  refer1 << "" << $4->exit.size();
		  errores.push_back(2); 
		  numErrores++; 
		  msgs.push_back(refer1.str());
		}
		if(!$4->conti.empty()) {
		  stringstream refer2;
		  refer2 << "" << $4->conti.size();
		  errores.push_back(3);
		  numErrores++;
		  msgs.push_back(refer2.str());
		}
		delete $4;
	}
;

bloque : TABRIRLLAVE
        lista_de_sentencias
        TCERRARLLAVE
        {
                $$ = $2;
        }
;

decl_bl : /* empty */
	| RLET declaraciones RIN
;

declaraciones : declaraciones TSEMIC lista_de_ident TDOSPT tipo { 
	for(vector<string>::iterator it = $3->begin(); it != $3->end(); it++){
	   if (!pila.tope().existeId(*it)) pila.tope().anadirVariable(*it, *$5);
	   else {
	     errores.push_back(1);
	     numErrores++; 
	     msgs.push_back(*it);
	   }
	}
	codigo.anadirDeclaraciones(*$3,*$5);
  	delete $3;
  	delete $5;
	}

        | lista_de_ident TDOSPT tipo { 
	for(vector<string>::iterator it = $1->begin(); it != $1->end(); it++){
	   if (!pila.tope().existeId(*it)) pila.tope().anadirVariable(*it, *$3);
	   else {
	     errores.push_back(1);
	     numErrores++; 
	     msgs.push_back(*it);
	   }
	}
	codigo.anadirDeclaraciones(*$1,*$3);
        delete $1;
        delete $3;
	}
;

lista_de_ident : TIDENTIFIER resto_lista_id {$$ = $2;
                                             $$->insert($$->begin(),*$1);}
;

resto_lista_id : /* empty */ {$$ = new vector<string>;}
	| TCOMA TIDENTIFIER resto_lista_id {$$ = $3;
                                            $$->insert($$->begin(),*$2);}
;

tipo : RINT {*$$ = "int";}
     | RFLOAT {*$$ = "real";}
;

decl_de_subprogs : /* empty */
	|decl_de_subprograma decl_de_subprogs
;

decl_de_subprograma : RDEF TIDENTIFIER { 
		procActual = *$2;
		if(!pila.tope().existeId(*$2)){
		   pila.tope().anadirProcedimiento(*$2);
		}else{
		   errores.push_back(1);
	     	   numErrores++; 
	     	   msgs.push_back(*$2);
		}
		TablaSimbolos st;
		pila.empilar(st);
		codigo.anadirInstruccion("proc " + *$2 + ";"); 
	} argumentos TDOSPT bloque_ppl { 
		pila.desempilar();
		codigo.anadirInstruccion("endproc " + *$2 + ";"); 
	}
;

argumentos : /* empty */
	|TABRIRPAREN lista_de_param TCERRARPAREN
;

lista_de_param : lista_de_ident TDOSPT clase_par tipo {
		for(vector<string>::iterator id = $1->begin(); id != $1->end(); id++){
		    if(!pila.tope().existeId(*id)){
			pila.anadirParametro(procActual, *id, *$3,  *$4);
		    }else{
			errores.push_back(1);
	     		numErrores++; 
	     		msgs.push_back(*id);
		    }
		}
		codigo.anadirParametros(*$1,*$3,*$4);
                delete $1;
                delete $3;
                delete $4;
	} resto_lis_de_param
;

clase_par : /* empty */ {*$$ = "val";}
	|TAMP {*$$ = "ref";}
;
resto_lis_de_param : /* empty */ 
	|TSEMIC lista_de_ident TDOSPT clase_par tipo {
		for(vector<string>::iterator id = $2->begin(); id != $2->end(); id++){
		    if(!pila.tope().existeId(*id)){
			pila.anadirParametro(procActual, *id, *$4,  *$5);
		    }else{
			errores.push_back(1);
	     		numErrores++; 
	     		msgs.push_back(*id);
		    }
		}
		codigo.anadirParametros(*$2,*$4,*$5);
                delete $2;
                delete $4;
                delete $5;
	} resto_lis_de_param
;

lista_de_sentencias : /* empty */ {$$ = new sentenciastruct;}
	|sentencia lista_de_sentencias {$$ = new sentenciastruct;
                                        $$->exit = *unir($1->exit,$2->exit);
                                        $$->conti = *unir($1->conti,$2->conti);
                                        delete $1;
                                        delete $2;}
;

sentencia : variable TEQ expresion TSEMIC
        {
        $$ = new sentenciastruct; 
	if(!pila.existeId(*$1)){
	    errores.push_back(4);
	    numErrores++; 
	    msgs.push_back(*$1);
	}else if(pila.obtenerTipo(*$1).compare($3->tipo) != 0){
	    errores.push_back(5);
	    numErrores++; 
	    msgs.push_back(pila.obtenerTipo(*$1));
	}else
            codigo.anadirInstruccion(*$1 + " := " + $3->str + ";"); 
	delete $3;
        }

        | RIF expresion TDOSPT M bloque M
        {
        $$ = new sentenciastruct;
	if($2->tipo != "bool"){
	    errores.push_back(6);
	    numErrores++; 
	    msgs.push_back($2->tipo);
	}
	$$ = $5;
        codigo.completarInstrucciones($2->trues,$4);
        codigo.completarInstrucciones($2->falses,$6);
	delete $2;
        }

        | RWHILE M expresion TDOSPT M bloque M 
        {
	if($3->tipo != "bool"){
	    errores.push_back(6);
	    numErrores++; 
	    msgs.push_back($3->tipo);
	}
        codigo.anadirInstruccion("goto");
        vector<int> *tmp1 = new vector<int>; 
	tmp1->push_back($7) ;
    	codigo.completarInstrucciones(*tmp1, $2) ;
        }
        RELSE TDOSPT bloque M
        {
        $$ = new sentenciastruct;
        codigo.completarInstrucciones($3->trues,$5);
        codigo.completarInstrucciones($3->falses,$7 + 1);
        codigo.completarInstrucciones($6->exit,$7 + 1);
        codigo.completarInstrucciones($6->conti,$2);
        codigo.completarInstrucciones($11->exit,$12);                  
        codigo.completarInstrucciones($11->conti,$2);
	delete $3;
	delete $6;
	delete $11;
        }

        | RFOREVER TDOSPT M bloque M
        {
        $$ = new sentenciastruct;
        codigo.anadirInstruccion("goto");
        vector<int> *tmp1 = new vector<int>; 
	tmp1->push_back($5) ;
    	codigo.completarInstrucciones(*tmp1, $3) ;
        codigo.completarInstrucciones($4->exit, $5 + 1);
        $$->conti = $4->conti;
        }

	| RBREAK TSEMIC { $$ = new sentenciastruct;
	$$->exit.push_back(codigo.obtenRef());
	codigo.anadirInstruccion("goto");
	}

        | RBREAK RIF expresion M TSEMIC
        {
	if($3->tipo != "bool"){
	    errores.push_back(6);
	    numErrores++;
	    msgs.push_back($3->tipo);
	}
        $$ = new sentenciastruct;
        codigo.completarInstrucciones($3->falses, $4);
        $$->exit = $3->trues;
        }

        | RCONTINUE TSEMIC
        {
        $$ = new sentenciastruct;
	*$$ = makecontinue();
        }

        | RREAD TABRIRPAREN variable TCERRARPAREN TSEMIC
        {
	if(!pila.existeId(*$3)){
	    errores.push_back(4);
	    numErrores++; 
	    msgs.push_back(*$3);
	}else
   	    codigo.anadirInstruccion("read " + *$3 + ";");
        $$ = new sentenciastruct;
        }

        | RPRINTLN TABRIRPAREN expresion  TCERRARPAREN TSEMIC
        {
        $$ = new sentenciastruct;
	if($3->tipo == "bool"){
	    errores.push_back(8);
	    numErrores++; 
	    msgs.push_back("");
	}else{
        codigo.anadirInstruccion( "write " + $3->str + ";");
        codigo.anadirInstruccion( "writeln;");
	}
	delete $3;
        }

	| RIF expresion TDOSPT M bloque N M parte_else M {
	$$ = new sentenciastruct;
	if($2->tipo != "bool"){
	    errores.push_back(6);
	    numErrores++; 
	    msgs.push_back($2->tipo);
	}
	$$->exit = *unir($5->exit, $8->exit);
	$$->conti = *unir($5->conti, $8->conti);
	codigo.completarInstrucciones(*$6, $9);
	codigo.completarInstrucciones($2->falses, $7);
	codigo.completarInstrucciones($2->trues, $4);
	delete $6;
	delete $2;
	delete $5;
	delete $8;
	}

	| RFOR variable RIN expresion TPTPT expresion TPTPT expresion TDOSPT {
	if(pila.tope().existeId(*$2)){
	    errores.push_back(1);
	    numErrores++; 
	    msgs.push_back(*$2);
	}else{
	    pila.tope().anadirVariable(*$2, "int");
	    if($4->tipo != "int" || $6->tipo != "int" || $8->tipo != "int"){
		errores.push_back(7);
	    	numErrores++; 
	    	msgs.push_back("");
	    }
	}
	codigo.anadirInstruccion("if " + $8->str + " = 0 goto 2;");
	stringstream help1;
	help1 << "" << codigo.obtenRef() + 2;
	codigo.anadirInstruccion("if " + $8->str + " > 0 goto " + help1.str() +";");
	help1.str("");
	help1 << "" << codigo.obtenRef() + 3;
	codigo.anadirInstruccion("goto "+ help1.str() +";");
	codigo.anadirInstruccion("if "+ $4->str +" > "+ $6->str +" goto 5;");
	help1.str("");
	help1 << "" << codigo.obtenRef() + 2;
	codigo.anadirInstruccion("goto "+ help1.str() +";");
	codigo.anadirInstruccion("if "+ $4->str +" < "+ $6->str +" goto 5;");

	codigo.anadirInstruccion("int "+ *$2 +";");
	codigo.anadirInstruccion(*$2 +" := "+ $4->str +";");

	stringstream refer;
	refer << "" << codigo.obtenRef() + 2;
	codigo.anadirInstruccion("if "+ $8->str +" > 0 goto " + refer.str()+";");

	stringstream refer1;
	refer1 << "" << codigo.obtenRef() + 5;
	codigo.anadirInstruccion("goto " + refer1.str()+";");
	
	stringstream refer2;
	refer2 << "" << codigo.obtenRef() + 2;
	codigo.anadirInstruccion("if "+ *$2 +" >= "+ $4->str +" goto " + refer2.str()+";");
	codigo.anadirInstruccion("goto");

	stringstream refer3;
	refer3 << "" << codigo.obtenRef() + 6;
	codigo.anadirInstruccion("if "+ *$2 +" <= "+ $6->str +" goto " + refer3.str()+";");
	codigo.anadirInstruccion("goto");

	stringstream refer4;
	refer4 << "" << codigo.obtenRef() + 2;
	codigo.anadirInstruccion("if "+ *$2 +" >= "+ $6->str +" goto " + refer4.str()+";");
	codigo.anadirInstruccion("goto");

	stringstream refer5;
	refer5 << "" << codigo.obtenRef() + 2;
	codigo.anadirInstruccion("if "+ *$2 +" <= "+ $4->str +" goto " + refer5.str()+";");
	codigo.anadirInstruccion("goto");
	} M bloque M {
	$$ = new sentenciastruct;
	pila.tope().borrarId(*$2);
	stringstream eme;
	eme << "" << $11 -10;
	codigo.anadirInstruccion(*$2 +" := "+ *$2 +" + " + $8->str +";");
	codigo.anadirInstruccion("goto "+ eme.str() +";");
	codigo.completarInstrucciones($12->conti, $13);
	codigo.completarInstrucciones($12->exit, $13 + 2);
	vector<int> tmp;
	tmp.push_back($11 -1);
	tmp.push_back($11 -3);
	tmp.push_back($11 -5);
	tmp.push_back($11 -7);
	codigo.completarInstrucciones(tmp, $13 + 2);
	delete $12;
	delete $2;
	delete $4;
	delete $6;
	delete $8;
	}

	| RSWITCH expresion TDOSPT TABRIRLLAVE cases M TCERRARLLAVE { 
	if($2->tipo == "bool"){
	     errores.push_back(8);
	     numErrores++; 
	     msgs.push_back("");
	}else{
	     for(vector<string>::iterator tipe = $5->tipes.begin(); tipe != $5->tipes.end(); tipe++){
		if(tipe->compare($2->tipo) != 0){
		   errores.push_back(9);
	     	   numErrores++; 
	     	   msgs.push_back($2->tipo);
		}
	     }
	}
	$$ = new sentenciastruct;
	codigo.completarInstrucciones($5->exit, $6);
	$$->conti = $5->conti;
	codigo.completarSwitch($5->gotos, $2->str);
	delete $2;
	}

	| TIDENTIFIER TABRIRPAREN lista_expresiones TCERRARPAREN TSEMIC {
	$$ = new sentenciastruct;
	if(!pila.existeId(*$1)){
	    errores.push_back(4);
	    numErrores++; 
	    msgs.push_back(*$1);
	}else if((int)$3->exprs.size() != pila.numArgsProcedimiento(*$1)){
	    errores.push_back(10);
	    numErrores++; 
	    msgs.push_back(*$1);
	}else{
	    pair<string,string> param;
	    for(int i = 0; i < pila.numArgsProcedimiento(*$1); i++){
		param = pila.obtenerTiposParametro(*$1, i);
		if($3->tipes[i].compare(param.second) != 0){
		    errores.push_back(5);
	    	    numErrores++; 
	    	    msgs.push_back(param.second);
		}else if(param.first == "ref" && $3->vars[i] == 0){
		    errores.push_back(11);
	    	    numErrores++; 
	    	    msgs.push_back("");
		}else codigo.anadirInstruccion("param_"+ param.first +"_"+ $3->exprs[i] +";");
	    }
	    codigo.anadirInstruccion("call "+ *$1 +";");
	}
	delete $3;
	}
;


lista_expresiones:  /*empty */{
		$$ = new lexprstruct;
	}

	| expresion resto_lista_expr{
		$$ = new lexprstruct;
		vector<string> e, t; e.push_back($1->str); t.push_back($1->tipo);
		vector<int> v; v.push_back($1->esVar);
		$$->vars = *unir(v, $2->vars);
		$$->exprs = *unir2(e, $2->exprs);
		$$->tipes = *unir2(t, $2->tipes);
		delete $1;
		delete $2;
	}
;

resto_lista_expr:  /*empty */{
		$$ = new lexprstruct;
	}

	| TCOMA expresion resto_lista_expr{
		$$ = new lexprstruct;
		vector<string> e, t; e.push_back($2->str); t.push_back($2->tipo);
		vector<int> v; v.push_back($2->esVar);
		$$->vars = *unir(v, $3->vars);
		$$->exprs = *unir2(e, $3->exprs);
		$$->tipes = *unir2(t, $3->tipes);
		delete $3;
		delete $2;
	}
;

cte:	TINTEGER	{$$ = new ctestruct;
			$$->tipo = "int";
			$$->str = *$1;}

	| TDOUBLE	{$$ = new ctestruct;
			$$->tipo = "real";
			$$->str = *$1;}
;

cases:	RDEFAULT TDOSPT lista_de_sentencias TSEMIC { $$ = new casestruct;
	$$->exit = $3->exit;
	$$->conti = $3->conti;
	}

	|RCASE cte TDOSPT M {
	codigo.anadirInstruccion("if " + $2->str + " = ");
	codigo.anadirInstruccion("goto");
	} lista_de_sentencias {
	codigo.anadirInstruccion("goto");
	} M TSEMIC r_cases {
	$$ = new casestruct;
	vector<string> tmptipes; tmptipes.push_back($2->tipo);
	$$->tipes = *unir2(tmptipes, $10->tipes);
	$$->gotos = $10->gotos;
	$$->gotos.push_back($4);
	vector<int> tmp; tmp.push_back($4 + 1);
	codigo.completarInstrucciones(tmp, $8);
	$$->exit = *unir($6->exit, $10->exit);
	vector<int> tmp1; tmp1.push_back($8 - 1);
	codigo.completarInstrucciones(tmp1, $10->ini);
	$$->conti = *unir($6->conti, $10->conti);
	delete $6;
	delete $2;
	}
;

r_cases: /* empty */ { $$ = new casestruct; $$->ini = codigo.obtenRef();}

	| RDEFAULT TDOSPT M lista_de_sentencias TSEMIC { $$ = new casestruct;
	$$->exit = $4->exit;
	$$->conti = $4->conti;
	$$->ini = $3;
	}
	
	| RCASE cte TDOSPT M {
	codigo.anadirInstruccion("if " + $2->str + " = ");
	codigo.anadirInstruccion("goto");
	} lista_de_sentencias {
	codigo.anadirInstruccion("goto");
	} M TSEMIC r_cases {
	$$ = new casestruct;
	vector<string> tmptipes; tmptipes.push_back($2->tipo);
	$$->tipes = *unir2(tmptipes, $10->tipes);
	$$->ini = $4 + 2;
	$$->gotos = $10->gotos;
	$$->gotos.push_back($4);
	vector<int> tmp; tmp.push_back($4 + 1);
	codigo.completarInstrucciones(tmp, $8);
	$$->exit = *unir($6->exit, $10->exit);
	vector<int> tmp1; tmp1.push_back($8 - 1);
	codigo.completarInstrucciones(tmp1, $10->ini);
	$$->conti = *unir($6->conti, $10->conti);
	delete $2;
	delete $6;
	}
;


parte_else: RELSEIF expresion TDOSPT M bloque N M parte_else M {
	$$ = new sentenciastruct;
	if($2->tipo != "bool"){
		errores.push_back(6);
	    	numErrores++; 
	    	msgs.push_back($2->tipo);
	}
	$$->exit = *unir($5->exit, $8->exit);
	$$->conti = *unir($5->conti, $8->conti);
	codigo.completarInstrucciones(*$6, $9);
	codigo.completarInstrucciones($2->falses, $7);
	codigo.completarInstrucciones($2->trues, $4);
	delete $6;
	delete $2;
	delete $5;
	delete $8;
	}

	| RELSE TDOSPT bloque {
	$$ = new sentenciastruct;
	$$->exit = $3->exit;
	$$->conti = $3->conti;
	}

	| RELSEIF expresion TDOSPT M bloque M {
	$$ = new sentenciastruct;
	if($2->tipo != "bool"){
		errores.push_back(6);
	    	numErrores++; 
cout<<"6"<<endl;
	    	msgs.push_back($2->tipo);
	}
	$$->exit = $5->exit;
	$$->conti = $5->conti;
	codigo.completarInstrucciones($2->falses, $4);
	codigo.completarInstrucciones($2->trues, $6);
	delete $2;
	}
;

variable : TIDENTIFIER {$$ = $1;}
;

expresion : expresion CEQ expresion
        { 
        $$ = new expresionstruct;
	if($1->tipo == "bool" || $3->tipo == "bool"){
	    errores.push_back(8);
	    numErrores++; 
	    msgs.push_back("");
	    $$->tipo = "error";
	    $$->esVar = 0; 
	}else{
	    *$$ = makecomparison($1->str,"=",$3->str) ; 
	}
	delete $1; delete $3;
        }
        | expresion  CGT   expresion 
        { 
        $$ = new expresionstruct;
	if($1->tipo == "bool" || $3->tipo == "bool"){
	    errores.push_back(8);
	    numErrores++; 
	    msgs.push_back("");
	    $$->tipo = "error";
	    $$->esVar = 0; 
	}else{
	    *$$ = makecomparison($1->str,">",$3->str) ; 
	}
	delete $1; delete $3;
        }
        | expresion  CLT   expresion
        { 
        $$ = new expresionstruct;
	if($1->tipo == "bool" || $3->tipo == "bool"){
	    errores.push_back(8);
	    numErrores++; 
	    msgs.push_back("");
    	    $$->tipo = "error";
	    $$->esVar = 0; 
	}else{
	    *$$ = makecomparison($1->str,"<",$3->str) ; 
	}
	delete $1; delete $3;
        }
        | expresion   CGE  expresion
        { 
        $$ = new expresionstruct;
	if($1->tipo == "bool" || $3->tipo == "bool"){
	    errores.push_back(8);
	    numErrores++; 
	    msgs.push_back("");
    	    $$->tipo = "error";
	    $$->esVar = 0; 
	}else{
	    *$$ = makecomparison($1->str,">=",$3->str) ; 
	} 
	delete $1; delete $3;
        }
        | expresion   CLE  expresion
        { 
        $$ = new expresionstruct;
	if($1->tipo == "bool" || $3->tipo == "bool"){
	    errores.push_back(8);
	    numErrores++; 
	    msgs.push_back("");
    	    $$->tipo = "error";
	    $$->esVar = 0; 
	}else{
	    *$$ = makecomparison($1->str,"<=",$3->str) ; 
	}
	delete $1; delete $3;
        }
        | expresion   CNE  expresion
        { 
        $$ = new expresionstruct;
	if($1->tipo == "bool" || $3->tipo == "bool"){
	    errores.push_back(8);
	    numErrores++; 
	    msgs.push_back("");
	    $$->tipo = "error";
	    $$->esVar = 0; 
	}else{
	    *$$ = makecomparison($1->str,"/=",$3->str) ; 
	}
	delete $1; delete $3;
        }
	|expresion OOR M expresion
	{
	$$ = new expresionstruct;
	expresionstruct tmp;
	codigo.completarInstrucciones($1->falses, $3);
	tmp.falses = $4->falses;
	tmp.trues = *unir($1->trues,$4->trues);
	tmp.tipo = "bool";
	if($1->tipo != "bool" || $4->tipo != "bool"){
	    errores.push_back(6);
	    numErrores++; 
	    msgs.push_back("error");
	    tmp.tipo == "error";
	}
	tmp.esVar = 0;
	*$$ = tmp;
	}
	|expresion OAND M expresion
	{
	$$ = new expresionstruct;
	expresionstruct tmp;
	codigo.completarInstrucciones($1->trues, $3);
	tmp.trues = $4->trues;
	tmp.falses = *unir($1->falses,$4->falses);
	tmp.tipo = "bool";
	if($1->tipo != "bool" || $4->tipo != "bool"){
	    errores.push_back(6);
	    msgs.push_back("error");
	    tmp.tipo == "error";
	}
	tmp.esVar = 0;
	*$$ = tmp;
	}
	|ONOT expresion
	{
	$$ = new expresionstruct;
	expresionstruct tmp;
	tmp.trues = $2->falses;
	tmp.falses = $2->trues;
	tmp.tipo = "bool";
	if($2->tipo != "bool"){
	    errores.push_back(6);
	    numErrores++; 
	    msgs.push_back($2->tipo);
	    tmp.tipo == "error";
	}
	tmp.esVar = 0;
	*$$ = tmp;
	}
        | expresion  OSUM   expresion
        {
        $$ = new expresionstruct;
	*$$ = makearithmetic($1->str,*$2,$3->str) ;
	if($1->tipo == "error" || $3->tipo == "error"){
	    $$->tipo == "error";
	}else if ($1->tipo == "bool" || $3->tipo == "bool"){
	    errores.push_back(8);
	    numErrores++; 
	    msgs.push_back("");
	    $$->tipo == "error";
	}else if ($1->tipo.compare($3->tipo) != 0){
	    $$->tipo = "real";
	}else $$->tipo = $1->tipo;
	$$->esVar = 0;
	delete $3;
        }
        | expresion   OREST  expresion
        {
        $$ = new expresionstruct;
	*$$ = makearithmetic($1->str,*$2,$3->str) ;
	if($1->tipo == "error" || $3->tipo == "error"){
	    $$->tipo == "error";
	}else if ($1->tipo == "bool" || $3->tipo == "bool"){
	    errores.push_back(8);
	    numErrores++; 
	    msgs.push_back("");
	    $$->tipo == "error";
	}else if ($1->tipo.compare($3->tipo) != 0){
	    $$->tipo = "real";
	}else $$->tipo = $1->tipo;
	$$->esVar = 0;
	delete $3;
        }
        | expresion   OMULT  expresion
        {
        $$ = new expresionstruct;
	*$$ = makearithmetic($1->str,*$2,$3->str) ;
	if($1->tipo == "error" || $3->tipo == "error"){
	    $$->tipo == "error";
	}else if ($1->tipo == "bool" || $3->tipo == "bool"){
	    errores.push_back(8);
	    numErrores++; 
	    msgs.push_back("");
	    $$->tipo == "error";
	}else if ($1->tipo.compare($3->tipo) != 0){
	    $$->tipo = "real";
	}else $$->tipo = $1->tipo;
	$$->esVar = 0;
	delete $3;
        }
        | expresion   ODIV  expresion
        {
        $$ = new expresionstruct;
	codigo.anadirInstruccion("if "+ $3->str +" = 0 goto 8;");
	*$$ = makearithmetic($1->str,*$2,$3->str) ;
	if($1->tipo == "error" || $3->tipo == "error"){
	    $$->tipo == "error";
	}else if ($1->tipo == "bool" || $3->tipo == "bool"){
	    errores.push_back(8);
	    numErrores++; 
	    msgs.push_back("");
	    $$->tipo == "error";
	}else if ($1->tipo.compare($3->tipo) != 0){
	    $$->tipo = "real";
	}else $$->tipo = $1->tipo;
	$$->esVar = 0;
	delete $3;
        }     
        | variable { 
		$$ = new expresionstruct; 
		if(!pila.existeId(*$1)){
		    errores.push_back(4);
	    	    numErrores++; 
	    	    msgs.push_back(*$1);
		    $$->tipo = "error";
		}else $$->tipo = pila.obtenerTipo(*$1);
		$$->str = *$1; 
		$$->esVar = 1; 
	}
        | TINTEGER { $$ = new expresionstruct; $$->tipo = "int"; $$->esVar = 0;  $$->str = *$1; }
        | TDOUBLE { $$ = new expresionstruct; $$->tipo = "real"; $$->esVar = 0; $$->str = *$1; }
        | TABRIRPAREN expresion TCERRARPAREN {$$ = $2; $$->esVar = 0;}
;

M:  { $$ = codigo.obtenRef() ; }
;

N:  { $$ = new vector<int>;
      $$->push_back(codigo.obtenRef());
      codigo.anadirInstruccion("goto");}
;
%%

expresionstruct makecomparison(std::string &s1, const std::string &s2, std::string &s3) {
  expresionstruct tmp ; 
  tmp.trues.push_back(codigo.obtenRef()) ;
  tmp.falses.push_back(codigo.obtenRef()+1) ;
  tmp.tipo = "bool";
  tmp.esVar = 0; 
  codigo.anadirInstruccion("if " + s1 + s2 + s3 + " goto") ;
  codigo.anadirInstruccion("goto") ;
  return tmp ;
}


expresionstruct makearithmetic(std::string &s1, std::string &s2, std::string &s3) {
  expresionstruct tmp ; 
  tmp.str = codigo.nuevoId() ;
  codigo.anadirInstruccion(tmp.str + ":=" + s1 + s2 + s3 + ";") ;     
  return tmp ;
}

sentenciastruct makecontinue() {
  sentenciastruct tmp ; 
  tmp.conti.push_back(codigo.obtenRef());
  codigo.anadirInstruccion("goto") ;     
  return tmp ;
}

vector<int> *unir(vector<int> lis1, vector<int> lis2){
        vector<int> *enteros = new vector<int>;

        for (auto it = lis1.begin(); it != lis1.end(); it++){
                enteros->push_back(*it);
        }

        for (auto it = lis2.begin(); it != lis2.end(); it++){
                enteros->push_back(*it);
        }
        return enteros;
}

vector<string> *unir2(vector<string> lis1, vector<string> lis2){
        vector<string> *strs = new vector<string>;

        for (auto it = lis1.begin(); it != lis1.end(); it++){
                strs->push_back(*it);
        }

        for (auto it = lis2.begin(); it != lis2.end(); it++){
                strs->push_back(*it);
        }
        return strs;
}

void imprimir_errores(){
	for(int i = 0; i < numErrores; i++){
	switch(errores[i])
	{
		case 1:
		cout<<"Error: Id '"+msgs[i]+"' ya está declarado"<<endl;
		break;
		case 2:
		cout<<"Error: "+msgs[i]+" breaks inútiles"<<endl;
		break;
		case 3:
		cout<<"Error: "+msgs[i]+" continues inútiles"<<endl;
		break;
		case 4:
		cout<<"Error: Id '"+msgs[i]+"' no está declarado"<<endl;
		break;
		case 5:
		cout<<"Error: Asinación con tipo erroneo, se espera "+msgs[i]<<endl;
		break;
		case 6:
		cout<<"Error: Se espera expresión booleana, '"+msgs[i]+"' recibido"<<endl;
		break;
		case 7:
		cout<<"Error: Expresión entera requerida"<<endl;
		break;
		case 8:
		cout<<"Error: Se requiere una expresión real o entera"<<endl;
		break;
		case 9:
		cout<<"Error: Algunas constantes no cuadran con la expresión de tipo "+msgs[i]<<endl;
		break;
		case 10:
		cout<<"Error: Llamada a '"+msgs[i]+"' no ha recibido el número de parámetros correcto"<<endl;
		break;
		case 11:
		cout<<"Error: Se requiere una variable como parámetro"<<endl;
		break;
		default:
		cout<<"Error desconocido"<<endl;
		break;
	}
	}
}









