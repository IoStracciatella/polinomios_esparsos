#ifndef POLINOMIO_H
#define POLINOMIO_H

typedef struct polinomio POLINOMIO;

void DEF(char nome[32], int k);

void SOMA(char A[32], char B[32], char R[32]);

void PROD(char A[32], char B[32], char R[32]);

void ADD(char A[32], int c, int g);

void ESCALA(char A[32], int c);

int COEF(char A[32], int g);

void REMOVE(char A[32], int g);

void REMOVEMENOR(char A[32]);

int GRAU(char A[32]);

void IMPRIME(char A[32]);

void IMPRIMEINV(char A[32]);

void LIBERA(char A[32]);

void FIM();


#endif