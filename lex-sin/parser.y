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
}

/* 
   declaración de tokens. Esto debe coincidir con tokens.l 
*/
%token <str> RPROGRAM RBEGIN RENDPROGRAM RDEF RMAIN RLET RIN RIF RELSE RWHILE RBREAK RFOREVER RCONTINUE RPRINTLN RREAD RINT RFLOAT

%token <str> TABRIRLLAVE TCERRARLLAVE TABRIRPAREN TCERRARPAREN TEQ TDOSPT TSEMIC TAMP TCOMA

%token <str> OMULT OSUM OREST ODIV CEQ CLT CGT CLE CGE CNE

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
%type <sent> bloque lista_de_sentencias sentencia
%type <str> variable
%type <expr> expresion
%type <number> M

%start programa


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
                $$->exit = $2->exit;
                $$->conti = $2->conti;
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
	$$->exit = $5->exit;
	$$->conti = $5->conti;
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
        }
        | RFOREVER TDOSPT M bloque M
        {
        $$ = new sentenciastruct;
        codigo.anadirInstruccion("goto");
        vector<int> tmp1 ; tmp1.push_back($3) ;
    	codigo.completarInstrucciones(tmp1, $5) ;
        codigo.completarInstrucciones($4->exit, $5 + 1);
        $$->conti = $4->conti;
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
	vector<int> tmp;
	tmp.push_back(codigo.obtenRef());
	$$->conti = tmp;
        codigo.anadirInstruccion("goto"); 
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

vector<int> *unir(vector<int> lis1, vector<int> lis2){
        vector<int> *enteros = new vector<int>;

        for (auto it = lis1.begin(); it != lis1.end(); it++){
                enteros->insert(enteros->begin(),*it);
        }

        for (auto it = lis2.begin(); it != lis2.end(); it++){
                enteros->insert(enteros->begin(),*it);
        }

        return enteros;
}
