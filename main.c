#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "registro.h"
#include "lex.yy.c"
#include "archivo_especificacion.tab.c"

//FILE *yyin = NULL;

/*struct Reg {
char Nombre[50];
int tipo;
};*/ 

struct Reg Tabla[100];

int NumIdentificadores = 0;

int Maneja_Id(struct Reg Tabla[100], char Id[50]);

int Busca(struct Reg Tabla[100], char Id[50]);

extern int yyerror(char *cad);

int main(){
    int token;
    yyin = fopen("ArchivoPrueba.txt", "r");
    yyparse();
    while(token=yylex()){
	printf("El token encontrado es %d\n", token);
    }
}

int yyerror(char *cad){
    printf("Error: %s", cad);
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
