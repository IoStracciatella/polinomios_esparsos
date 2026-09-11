#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"


int main(){
    char c[12];
    int fimloop = 0;

    LISTA *lista = criar_lista();

    while (fimloop == 0){
        scanf("%s", c);
        if (strcmp(c,"DEF") == 0){
            char *A = (char *)malloc(sizeof(char)*32);
            scanf("%s", A);
            criar_polinomio(A, c, lista);
        }
        else if(strcmp(c, "SOMA") == 0 || strcmp(c, "PROD") == 0){
            char *R = (char *)malloc(sizeof(char)*32);
            char A[32];
            char B[32];
            scanf("%s %s %s", A, B, R);
            busca_tripla(A, B, R, c, lista);
        }
        else if(strcmp(c, "ADD") == 0 || strcmp(c, "ESCALA") == 0 || strcmp(c, "COEF") == 0 || strcmp(c, "REMOVE") == 0 || strcmp(c, "REMOVEMENOR") == 0 || strcmp(c, "GRAU") == 0 || strcmp(c, "IMPRIME") == 0 || strcmp(c, "IMPRIMEINV") == 0){
            char A[32];
            scanf("%s", A);
            busca_opera(A, c, lista);
        }
        else if (strcmp(c, "LIBERA") == 0){
            char A[32];
            scanf("%s", A);
            libera(A, lista);
        }
        else if (strcmp(c,"FIM") == 0){
            fim(c, lista);
            fimloop = 1;
        }
        else if (strcmp(c,"teste") == 0){
            teste(lista);
            //fimloop = 1;
        }
        else{
            printf("Digite algo certo!\n");
        }
            
    }

    return 0;
}