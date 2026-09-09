#include <stdio.h>
#include <stdlib.h>

typedef struct teste TESTE;

struct teste{
    char *nome;
    int *prox;
};

int main(){
    TESTE *p = (TESTE *)malloc(sizeof(TESTE));
    char nomed[32] = "POMEEEEEE";

    p->nome = nomed;

    printf("%s", ((TESTE *)p->nome)->nome);

    return 0;
}