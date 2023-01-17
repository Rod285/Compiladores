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

struct Reg TablaGlobal[100];

struct Reg TablaLocal[100];

int NumIdentificadores = 0;

struct Reg* Inserta(struct Reg Tabla[100], char Id[50]);

struct Reg* Busca(struct Reg Tabla[100], char Id[50]);

int Maneja_Id(/*struct Reg Tabla[100],*/ char Id[50]);

int declaracion;

int EsGlobal = 1;

int main(){
    int token;
    yyin = fopen("ArchivoPrueba.txt", "r");
    yyparse();
}

int yyerror(char *cad){
    printf("Error: %s <%s>\n", cad, yytext);
    return 0;
}

struct Reg* Inserta(struct Reg Tabla[100], char Id[50]){

    if(NumIdentificadores < 100){
        strcpy(Tabla[NumIdentificadores].Nombre, Id);
        NumIdentificadores++;
        return &Tabla[NumIdentificadores];
    }
    else{
        return(NULL);
    }
}

struct Reg* Busca(struct Reg Tabla[100], char Id[50]){
    int indice;
    for(indice = 0; indice < NumIdentificadores; indice++){
        if(strcmp(Tabla[indice].Nombre, Id) == 0){
            return &Tabla[indice];
        }
    }
}

int Maneja_Id(char Id[50]){
    if(declaracion == 1){
        if(EsGlobal == 1){
            ap_id = Busca(TablaGlobal, Id);
            if(ap_id == NULL){
                Inserta(TablaGlobal, Id);
            }else{
                printf("ERROR, Variable redeclarada");
            }
        }else{
            ap_id = Busca(TablaLocal, Id);
            if(ap_id == NULL){
                ap_id = Inserta(TablaLocal, Id);
            }else{
                printf("ERROR, Variable redeclarada");
            }
        }
    }else{
        if(EsGlobal == 1){
            ap_id = Busca(TablaGlobal, Id);
            if(ap_id == NULL){
                printf("ERROR Variable Global no declarada");
                ap_id = Inserta(TablaGlobal, Id);
            }
        }else{
            ap_id = Busca(TablaLocal, Id);
            if(ap_id == NULL){
                printf("ERROR, Variable local no declarada");
                ap_id = Inserta(TablaLocal, Id);
            }
        }
    }
}