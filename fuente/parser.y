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

   expresionstruct makecomparison(std::string &s1, std::string &s2, std::string &s3) ;
   expresionstruct makearithmetic(std::string &s1, std::string &s2, std::string &s3) ;
   vector<int> *unir(vector<int> lis1, vector<int> lis2);
   vector<string> *unir2(vector<string> lis1, vector<string> lis2);
   sentenciastruct makecontinue();
   Codigo codigo;


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
%type <str> variable cte
%type <expr> expresion
%type <number> M
%type <cses> cases r_cases
%type <numlist> N

%start programa

%left OOR
%left OAND
%left ONOT
%nonassoc CEQ CGT CGE CLT CLE CNE
%left OSUM OREST
%left OMULT ODIV

%%

programa : RDEF RMAIN { codigo.anadirInstruccion("proc main;"); } 
           TABRIRPAREN TCERRARPAREN TDOSPT 
	   bloque_ppl
           { codigo.anadirInstruccion("halt;" ) ;
             codigo.escribir();}
         ;

bloque_ppl : decl_bl TABRIRLLAVE
        decl_de_subprogs
        lista_de_sentencias
        TCERRARLLAVE
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

declaraciones : declaraciones TSEMIC lista_de_ident TDOSPT tipo { codigo.anadirDeclaraciones(*$3,*$5);
  delete $3;
  delete $5;}

        | lista_de_ident TDOSPT tipo { codigo.anadirDeclaraciones(*$1,*$3);
                                       delete $1;
                                       delete $3;}
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

decl_de_subprograma : RDEF TIDENTIFIER { codigo.anadirInstruccion("proc " + *$2 + ";"); }
                      argumentos TDOSPT bloque_ppl { codigo.anadirInstruccion("endproc " + *$2 + ";"); }
;

argumentos : /* empty */
	|TABRIRPAREN lista_de_param TCERRARPAREN
;

lista_de_param : lista_de_ident TDOSPT clase_par tipo {codigo.anadirParametros(*$1,*$3,*$4);
                                                       delete $1;
                                                       delete $3;
                                                       delete $4;} 
                 resto_lis_de_param
;

clase_par : /* empty */ {*$$ = "val";}
	|TAMP {*$$ = "ref";}
;
resto_lis_de_param : /* empty */ 
	|TSEMIC lista_de_ident TDOSPT clase_par tipo {codigo.anadirParametros(*$2,*$4,*$5);
                                                       delete $2;
                                                       delete $4;
                                                       delete $5;}
         resto_lis_de_param
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
        codigo.anadirInstruccion(*$1 + " := " + $3->str + ";"); 
	delete $3;
        }

        | RIF expresion TDOSPT M bloque M
        {
        $$ = new sentenciastruct;
	$$ = $5;
        codigo.completarInstrucciones($2->trues,$4);
        codigo.completarInstrucciones($2->falses,$6);
	delete $2;
        }

        | RWHILE M expresion TDOSPT M bloque M 
        {
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
        $$ = new sentenciastruct;
        codigo.anadirInstruccion("read " + *$3 + ";");
        }

        | RPRINTLN TABRIRPAREN expresion  TCERRARPAREN TSEMIC
        {
        $$ = new sentenciastruct;
        codigo.anadirInstruccion( "write " + $3->str + ";");
        codigo.anadirInstruccion( "writeln;");
	delete $3;
        }

	| RIF expresion TDOSPT M bloque N M parte_else M {
	$$ = new sentenciastruct;
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

	stringstream eme;
	eme << "" << $11 -11;
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

	| RSWITCH expresion TDOSPT TABRIRLLAVE cases M TCERRARLLAVE { $$ = new sentenciastruct;
	codigo.completarInstrucciones($5->exit, $6);
	$$->conti = $5->conti;
	codigo.completarSwitch($5->gotos, $2->str);
	}
;


cte:	TINTEGER	{$$ = $1;}

	| TDOUBLE	{$$ = $1;}
;

cases:	RDEFAULT TDOSPT lista_de_sentencias TSEMIC { $$ = new casestruct;
	$$->exit = $3->exit;
	$$->conti = $3->conti;
	}

	|RCASE cte TDOSPT M {
	codigo.anadirInstruccion("if "+ *$2 +" == ");
	codigo.anadirInstruccion("goto");
	} lista_de_sentencias {
	codigo.anadirInstruccion("goto");
	} M TSEMIC r_cases {
	$$ = new casestruct;
	$$->gotos = $10->gotos;
	$$->gotos.push_back($4);
	vector<int> tmp; tmp.push_back($4 + 1);
	codigo.completarInstrucciones(tmp, $8);
	$$->exit = *unir($6->exit, $10->exit);
	vector<int> tmp1; tmp1.push_back($8 - 1);
	codigo.completarInstrucciones(tmp1, $10->ini);
	$$->conti = *unir($6->conti, $10->conti);
	}
;

r_cases: /* empty */ { $$ = new casestruct; $$->ini = codigo.obtenRef();}

	| RDEFAULT TDOSPT M lista_de_sentencias TSEMIC { $$ = new casestruct;
	$$->exit = $4->exit;
	$$->conti = $4->conti;
	$$->ini = $3;
	}
	
	| RCASE cte TDOSPT M {
	codigo.anadirInstruccion("if "+ *$2 +" == ");
	codigo.anadirInstruccion("goto");
	} lista_de_sentencias {
	codigo.anadirInstruccion("goto");
	} M TSEMIC r_cases {
	$$ = new casestruct;
	$$->ini = $4 + 2;
	$$->gotos = $10->gotos;
	$$->gotos.push_back($4);
	vector<int> tmp; tmp.push_back($4 + 1);
	codigo.completarInstrucciones(tmp, $8);
	$$->exit = *unir($6->exit, $10->exit);
	vector<int> tmp1; tmp1.push_back($8 - 1);
	codigo.completarInstrucciones(tmp1, $10->ini);
	$$->conti = *unir($6->conti, $10->conti);
	}
;


parte_else: RELSEIF expresion TDOSPT M bloque N M parte_else M {
	$$ = new sentenciastruct;
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
	*$$ = makecomparison($1->str,*$2,$3->str) ; 
	delete $1; delete $3;
        }
        | expresion  CGT   expresion 
        { 
        $$ = new expresionstruct;
	*$$ = makecomparison($1->str,*$2,$3->str) ; 
	delete $1; delete $3;
        }
        | expresion  CLT   expresion
        { 
        $$ = new expresionstruct;
	*$$ = makecomparison($1->str,*$2,$3->str) ; 
	delete $1; delete $3;
        }
        | expresion   CGE  expresion
        { 
        $$ = new expresionstruct;
	*$$ = makecomparison($1->str,*$2,$3->str) ; 
	delete $1; delete $3;
        }
        | expresion   CLE  expresion
        { 
        $$ = new expresionstruct;
	*$$ = makecomparison($1->str,*$2,$3->str) ; 
	delete $1; delete $3;
        }
        | expresion   CNE  expresion
        { 
        $$ = new expresionstruct;
	*$$ = makecomparison($1->str,*$2,$3->str) ; 
	delete $1; delete $3;
        }
	|expresion OOR M expresion
	{
	$$ = new expresionstruct;
	expresionstruct tmp;
	codigo.completarInstrucciones($1->falses, $3);
	tmp.falses = $4->falses;
	tmp.trues = *unir($1->trues,$4->trues);
	*$$ = tmp;
	}
	|expresion OAND M expresion
	{
	$$ = new expresionstruct;
	expresionstruct tmp;
	codigo.completarInstrucciones($1->trues, $3);
	tmp.trues = $4->trues;
	tmp.falses = *unir($1->falses,$4->falses);
	*$$ = tmp;
	}
	|ONOT expresion
	{
	$$ = new expresionstruct;
	expresionstruct tmp;
	tmp.trues = $2->falses;
	tmp.falses = $2->trues;
	*$$ = tmp;
	}
        | expresion  OSUM   expresion
        {
        $$ = new expresionstruct;
	*$$ = makearithmetic($1->str,*$2,$3->str) ;
	delete $1; delete $3;
        }
        | expresion   OREST  expresion
        {
        $$ = new expresionstruct;
	*$$ = makearithmetic($1->str,*$2,$3->str) ;
	delete $1; delete $3;
        }
        | expresion   OMULT  expresion
        {
        $$ = new expresionstruct;
	*$$ = makearithmetic($1->str,*$2,$3->str) ;
	delete $1; delete $3;
        }
        | expresion   ODIV  expresion
        {
        $$ = new expresionstruct;
	*$$ = makearithmetic($1->str,*$2,$3->str) ;
	delete $1; delete $3;
        }     
        | TIDENTIFIER { $$ = new expresionstruct; $$->str = *$1; }
        | TINTEGER { $$ = new expresionstruct; $$->str = *$1; }
        | TDOUBLE { $$ = new expresionstruct; $$->str = *$1; }
        | TABRIRPAREN expresion TCERRARPAREN {$$ = $2;}
;

M:  { $$ = codigo.obtenRef() ; }
;

N:  { $$ = new vector<int>;
      $$->push_back(codigo.obtenRef());
      codigo.anadirInstruccion("goto");}
;
%%

expresionstruct makecomparison(std::string &s1, std::string &s2, std::string &s3) {
  expresionstruct tmp ; 
  tmp.trues.push_back(codigo.obtenRef()) ;
  tmp.falses.push_back(codigo.obtenRef()+1) ;
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
