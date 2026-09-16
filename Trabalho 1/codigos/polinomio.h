#ifndef POLINOMIO_H
#define POLINOMIO_H

#define boolean int
#define TRUE 1
#define FALSE 0

typedef struct polinomio POLINOMIO;
typedef struct termo TERMO;

POLINOMIO *DEF(POLINOMIO *p, int k);

boolean SOMA(POLINOMIO *a, POLINOMIO *b, POLINOMIO *r);

boolean PROD(POLINOMIO *a, POLINOMIO *b, POLINOMIO *r);

boolean ADD(POLINOMIO *a, long long c, int g);

boolean ESCALA(POLINOMIO *a, long long c);

int COEF(POLINOMIO *a, int g);

boolean REMOVE(POLINOMIO *a, int g);

boolean REMOVEMENOR(POLINOMIO *a);

int GRAU(POLINOMIO *a);

void IMPRIME(POLINOMIO *a);

void IMPRIMEINV(POLINOMIO *a);

void LIBERA(POLINOMIO *a);

#endif 