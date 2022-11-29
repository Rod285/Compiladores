%{
    #include "registro.h"
    int Valor_num = 0;
    int ap_id = 0;
    extern struct Reg Tabla[100]; 
    extern int Maneja_Id(struct Reg Tabla[100], char Id[50]);  
%}
l [a-zA-z]
d [0-9]
int yywrap();
%%
"int"		{return(1);}
"float" 	{return(2);}
"char"  	{return(3);}
"main"  	{return(4);}
"if"    	{return(5);}
"else"  	{return(6);}
"while" 	{return(7);}
"do" 		{return(8);}
"return"   	{return(9);}
"for" 		{return(10);}
"\n"   		{return(11);}
";" 		{return(12);}
"("   		{return(13);}
")" 		{return(14);}
"{"   		{return(15);}
"}" 		{return(16);}
">="		{return(17);}
">"		{return(18);}
"<="		{return(19);}
"<"		{return(20);}
"="		{return(21);}
"=="		{return(22);}
"!="		{return(23);}
"+"		{return(24);}
"-"		{return(25);}
"*"		{return(26);}
"/"		{return(27);}
{l}({l}|{d})*	{ap_id = Maneja_Id(Tabla, yytext);
		    return(28);}
{d}+		{Valor_num = atoi(yytext);
		    return(29);}
\"(\\.|[^"\\])*\"	{return(30);}
%%
int yywrap(){
    return (1);
}
