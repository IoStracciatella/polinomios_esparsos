#ifndef LISTA_H
#define LISTA_H

#define boolean int
#define TRUE 1
#define FALSE 0
#define TAM_MAX 512

typedef struct lista LISTA;
typedef struct polinomio POLINOMIO;

boolean criar_polinomio(char *A, char *c, LISTA *lista);
boolean busca_tripla(char *A, char *B, char *R, char *c, LISTA *lista);
void busca_opera(char *A, char *c, LISTA *lista);
void libera(char *A, LISTA *lista);
void fim(char *c, LISTA *lista);

LISTA *criar_lista();
void add_lista(char *A, LISTA *lista);
POLINOMIO *busca(char *A, LISTA *lista);
void rem_lista(POLINOMIO *p, LISTA *lista);
void teste(LISTA *lista);

#endif