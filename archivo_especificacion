%token int
%token float
%token char
%token main
%token if
%token else
%token while
%token do
%token return
%token for
%token sl	//\n
%token ';'	//;
%token '('	//(
%token ')'	//pc
%token '{'	//{
%token '}'	//}
%token Mi	//>=
%token '>'	//>
%token mi	//<=
%token '<'	//<
%token '='	//=
%token il	//==
%token dif	//!= 
%token '+'	//+
%token '-'  //-
%token '*'	//*
%token '/'	//'/'	
%token id
%token num
%token cad
%token 'q'	//,
%start PROGRAM
%%
PROGRAM : DECLS MAIN;
DECLS :
      | DECLS DECL;
DECL : int LISTA_ID ';';
LISTA_ID : id
         | LISTA_ID ',' id;
MAIN : main '(' ')' '{' DECLS INS '}';
INS : id '=' EXP ';';
EXP : id '+' id;