#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "polinomio.h"

int main(){
    char c[12];
    int fim = 0;

    while (fim == 0){
        scanf("%s", c);
        if (strcmp(c,"DEF") == 0){
            char nome[32];
            int k;
            scanf("%s", nome);
            scanf("%d", &k);
            DEF(nome,k);
        }
        else if(strcmp(c, "SOMA") == 0){
            char R[32];
            char A[32];
            char B[32];
            scanf("%s %s %s", A, B, R);
            SOMA(A,B,R);
        }
        else if(strcmp(c, "PROD") == 0){
            char R[32];
            char A[32];
            char B[32];
            scanf("%s %s %s", A, B, R);
            PROD(A,B,R);
        }
        else if(strcmp(c, "ADD") == 0){
            char A[32];
            int c, g;
            scanf("%s %d %d", A, &c, &g);
            ADD(A,c,g);
        }
        else if(strcmp(c, "ESCALA") == 0){
            char A[32];
            int c;
            scanf("%s %d", A, &c);
            ESCALA(A,c);
        }
        else if(strcmp(c, "COEF") == 0){
            char A[32];
            int g;
            scanf("%s %d", A, &g);
            COEF(A,g);
        }
        else if(strcmp(c, "REMOVE") == 0){
            char A[32];
            int g;
            scanf("%s %d", A, &g);
            REMOVE(A,g);
        }
        else if(strcmp(c, "REMOVEMENOR") == 0){
            char A[32];
            scanf("%s", A);
            REMOVEMENOR(A);
        }
        else if(strcmp(c, "GRAU") == 0){
            char A[32];
            scanf("%s", A);
            GRAU(A);
        }
        else if(strcmp(c, "IMPRIME") == 0){
            char A[32];
            scanf("%s", A);
            IMPRIME(A);
        }
        else if(strcmp(c, "IMPRIMVEINV") == 0){
            char A[32];
            scanf("%s", A);
            IMPRIMEINV(A);
        }
        else if(strcmp(c, "LIBERA") == 0){
            char A[32];
            scanf("%s", A);
            LIBERA(A);
        }
        else if(strcmp(c,"FIM") == 0){
            fim = 1;
            break;
        }
        else{
            printf("Digite algo certo!\n");
        }
            
    }

    return 0;
}