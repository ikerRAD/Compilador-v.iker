%option yylineno 
%option nounput

%{
 #include <string>
 #include <iostream>
 #include <vector>
 using namespace std ;
 #include "Exp.hpp"
 #include "parser.hpp" 
 using namespace std;

 #define TOKEN(t) yylval.str = new string(yytext, yyleng) ; return t 

 extern "C" int yywrap() { return(1) ; }  

%}

%%
#[^\n#]*\n                                            ;
'''('?'?[^'#])*'?'?'''                                ;
program                                     TOKEN(RPROGRAM) ;
comienzo                                    TOKEN(RBEGIN) ;
fin                                         TOKEN(RENDPROGRAM) ;
def                                         TOKEN(RDEF);
main                                        TOKEN(RMAIN);
let                                         TOKEN(RLET);
in                                          TOKEN(RIN);
if                                          TOKEN(RIF);
else                                        TOKEN(RELSE);
while                                       TOKEN(RWHILE);
break                                       TOKEN(RBREAK);            
forever                                     TOKEN(RFOREVER);
continue                                    TOKEN(RCONTINUE);
println                                     TOKEN(RPRINTLN);
read                                        TOKEN(RREAD);
integer                                     TOKEN(RINT);
float                                       TOKEN(RFLOAT);

"{"                                         TOKEN(TABRIRLLAVE);
"}"                                         TOKEN(TCERRARLLAVE);
"("                                         TOKEN(TABRIRPAREN);
")"                                         TOKEN(TCERRARPAREN);
"="                                         TOKEN(TEQ);
":"                                         TOKEN(TDOSPT);
";"                                         TOKEN(TSEMIC);
"&"                                         TOKEN(TAMP);
","                                         TOKEN(TCOMA);


[ \t\n]                                             ;

"*"                                         TOKEN(OMULT);
"+"                                         TOKEN(OSUM); 
"-"                                         TOKEN(OREST); 
"/"                                         TOKEN(ODIV);
"=="                                        TOKEN(CEQ);
"<"                                         TOKEN(CLT);
">"                                         TOKEN(CGT);
"<="                                        TOKEN(CLE);
">="                                        TOKEN(CGE);
"/="                                        TOKEN(CNE);

[a-zA-Z](_?[a-zA-Z0-9])*                    TOKEN(TIDENTIFIER) ; 
[0-9]+\.[0-9]+([eE][\-\+]?[0-9]+)?          TOKEN(TDOUBLE);
[0-9]+                                      TOKEN(TINTEGER); 

.                       { cout << "Token desconocido: " << yytext << endl; yyterminate();}
%%

