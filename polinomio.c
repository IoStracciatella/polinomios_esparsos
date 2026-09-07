#include <stdio.h>
#include "polinomio.h"

struct elem{
    int c;
    int g;
};

typedef struct elem ELEM;


struct polinomio{
    ELEM elem[TAM_MAX];
    int proximo;
};

void DEF(char nome[32], int k){
    printf("%s %d\n", nome, k);
}

void SOMA(char A[32], char B[32], char R[32]){
    printf("%s %s %s\n", A, B, R);
}

void PROD(char A[32], char B[32], char R[32]){
    printf("%s %s %s\n", A, B, R);
}

void ADD(char A[32], int c, int g){
    printf("%s %d %d\n", A, c, g);
}

void ESCALA(char A[32], int c){
    printf("%s %d\n", A, c);
}

int COEF(char A[32], int g){
    printf("%s %d\n", A, g);
}

void REMOVE(char A[32], int g){
    printf("%s %d\n", A, g);
}

void REMOVEMENOR(char A[32]){
    printf("%s\n", A);
}

int GRAU(char A[32]){
    printf("%s\n", A);
}

void IMPRIME(char A[32]){
    printf("%s\n", A);
}

void IMPRIMEINV(char A[32]){
    printf("%s\n", A);
}

void LIBERA(char A[32]){
    printf("%s\n", A);
}

void FIM(){
    
}
