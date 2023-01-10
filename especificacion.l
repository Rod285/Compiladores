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
"Int" {return(258);}
"Float" {return(259);}
"Char" {return(260);}
"Main" {return(261);}
"If" {return(262);}
"Else" {return(263);}
"While" {return(264);}
"Do" {return(265);}
"Return" {return(266);}
"For" {return(267);}
'\n' {return(268);}
";" {return(269);}
"(" {return(270);}
")" {return(271);}
"{" {return(272);}
"}" {return(273);}
">=" {return(274);}
">" {return(275);}
"<=" {return(276);}
"<" {return(277);}
"=" {return(278);}
"==" {return(279);}
"!=" {return(280);}
"+" {return(281);}
"-" {return(282);}
"*" {return(283);}
"/" {return(284);}
{l}({l}|{d})* {ap_id = Maneja_Id(Tabla, yytext);
		    return(285);}
{d}+ {Valor_num = atoi(yytext);
		    return(286);}
\"(\\.|[^"\\])*\" {return(287);}
"," {return(288);}
%%
int yywrap(){
    return (1);
}