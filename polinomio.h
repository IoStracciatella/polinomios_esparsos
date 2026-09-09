#ifndef POLINOMIO_H
#define POLINOMIO_H

#define TAM_MAX 512
#define TRUE 1
#define FALSE 0
#define boolean int

typedef struct polinomio POLINOMIO;

void DEF(char nome[32], int k);

void SOMA(char A[32], char B[32], char R[32]);

void PROD(char A[32], char B[32], char R[32]);

boolean ADD(char A[32], int c, int g);

boolean ESCALA(char A[32], int c);

int COEF(char A[32], int g);

boolean REMOVE(char A[32], int g);

boolean REMOVEMENOR(char A[32]);

int GRAU(char A[32]);

void IMPRIME(char A[32]);

void IMPRIMEINV(char A[32]);

void LIBERA(char A[32]);

void FIM();


#endif