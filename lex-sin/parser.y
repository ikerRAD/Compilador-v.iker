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

%}

/* 
   qué atributos tienen los tokens 
*/
%union {
    string *str ; 
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
%type <str> bloque
%type <str> decl_bl
%type <str> declaraciones
%type <str> lista_de_ident
%type <str> resto_lista_id
%type <str> tipo
%type <str> decl_de_subprogs
%type <str> decl_de_subprograma
%type <str> argumentos
%type <str> lista_de_param
%type <str> clase_par
%type <str> resto_lis_de_param
%type <str> lista_de_sentencias
%type <str> sentencia
%type <str> variable
%type <str> expresion

%start programa
%left OSUM OREST
%nonassoc CEQ CGT CGE CLT CLE CNE
%left OMULT ODIV
%right TASSIG

%%

programa : RDEF RMAIN TABRIRPAREN TCERRARPAREN TDOSPT 
	bloque_ppl
         ;

bloque_ppl : decl_bl TABRIRLLAVE
        decl_de_subprogs
        lista_de_sentencias
        TCERRARLLAVE
;

bloque : TABRIRLLAVE
        lista_de_sentencias
        TCERRARLLAVE
;

decl_bl : /* empty */
	| RLET declaraciones RIN
;

declaraciones : declaraciones TSEMIC lista_de_ident TDOSPT tipo
        | lista_de_ident TDOSPT tipo
;

lista_de_ident : TIDENTIFIER resto_lista_id;

resto_lista_id : /* empty */
	| TCOMA TIDENTIFIER resto_lista_id
;

tipo : RINT | RFLOAT;

decl_de_subprogs : /* empty */
	|decl_de_subprograma decl_de_subprogs
;

decl_de_subprograma : RDEF TIDENTIFIER argumentos TDOSPT bloque_ppl;

argumentos : /* empty */
	|TABRIRPAREN lista_de_param TCERRARPAREN
;

lista_de_param : lista_de_ident TDOSPT clase_par tipo resto_lis_de_param
;

clase_par : /* empty */
	|TAMP;

resto_lis_de_param : /* empty */
	|TSEMIC lista_de_ident TDOSPT clase_par tipo resto_lis_de_param
;

lista_de_sentencias : /* empty */
	|sentencia lista_de_sentencias
;

sentencia : variable TEQ expresion TSEMIC
        | RIF expresion TDOSPT bloque
        | RWHILE expresion TDOSPT bloque RELSE TDOSPT bloque
        | RFOREVER TDOSPT bloque
        | RBREAK RIF expresion TSEMIC
        | RCONTINUE TSEMIC
        | RREAD TABRIRPAREN variable TCERRARPAREN TSEMIC
        | RPRINTLN TABRIRPAREN expresion  TCERRARPAREN TSEMIC
;


variable : TIDENTIFIER;

expresion : expresion CEQ expresion
        | expresion  CGT   expresion 
        | expresion  CLT   expresion
        | expresion   CGE  expresion
        | expresion   CLE  expresion
        | expresion   CNE  expresion
        | expresion  OSUM   expresion
        | expresion   OREST  expresion
        | expresion   OMULT  expresion
        | expresion   ODIV  expresion       
        | TIDENTIFIER
        | TINTEGER
        | TDOUBLE
        | TABRIRPAREN expresion TCERRARPAREN
;
