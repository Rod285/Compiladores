%token Int
%token Float
%token Char
%token Main
%token If
%token Else
%token While
%token Do
%token Return
%token For
%token salin      //\n
%token pq	      //;
%token parab	//(
%token parci	//)
%token llab 	//{
%token llci 	//}
%token mayig	//>=
%token myr	      //>
%token menig	//<=
%token mnr  	//<
%token igl	      //=
%token iglog	//==
%token dfrnt	//!= 
%token smr  	//+
%token rstr       //-
%token mltpl	//*
%token dvsn 	//'/'	
%token ID
%token num
%token cade
%token q          //,
%start PROGRAM
%%
PROGRAM : DECLS MAIN;
DECLS :
      | DECLS DECL;
DECL : Int LISTA_ID pq;
LISTA_ID : ID
         | LISTA_ID q ID;
MAIN : Main parab parci llab DECLS INS llci;
INS : ID igl EXP pq;
EXP : ID smr ID;