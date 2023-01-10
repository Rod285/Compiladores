#include <stdio.h>
#include <stdlib.h>
extern int yyerror(char* cad);
#include <string.h>
#include "registro.h"
#include "lex.yy.c"
#include "y2.tab.c"

//FILE *yyin = NULL;

/*struct Reg {
char Nombre[50];
int tipo;
};*/ 

struct Reg Tabla[100];

int NumIdentificadores = 0;

int Maneja_Id(struct Reg Tabla[100], char Id[50]);

int Busca(struct Reg Tabla[100], char Id[50]);

int main(){
    int token;
    yyin = fopen("ArchivoPrueba.txt", "r");
    yyparse();
/*    while(token=yylex()){
	    printf("El token encontrado es %d\n", token);
    }
*/
}

int yyerror(char *cad){
    printf("Error: %s <%s>\n", cad, yytext);
    return 0;
}

int Maneja_Id(struct Reg Tabla[100], char Id[50]){

    if(NumIdentificadores < 100){
        strcpy(Tabla[NumIdentificadores].Nombre, Id);
        NumIdentificadores++;
        return(1);
    }
    else{
        return(-1);
    }
}

int Busca(struct Reg Tabla[100], char Id[50]){
    int indice;
    for(indice = 0; indice < NumIdentificadores; indice++){
        if(strcmp(Tabla[indice].Nombre, Id) == 0){
            return indice;
        }
    }
}
