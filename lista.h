#ifndef LISTA_H
#define LISTA_H

#define boolean int
#define TRUE 1
#define FALSE 0
#define TAM_MAX 512

typedef struct lista LISTA;

LISTA *criar_lista();
boolean inserir(char *A, char *c, LISTA *lista);
boolean busca(char *A, char *c, LISTA *lista);
boolean busca_tripla(char *A, char *B, char *R, char *c, LISTA *lista);
void teste(LISTA *lista);
void fim(char *c, LISTA *lista);

#endif