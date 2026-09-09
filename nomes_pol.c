#include <stdio.h>
#include "nomes_pol.h"
#include "polinomio.h"


struct nompol{
    POLINOMIO *polinomio[TAM_MAX];
    int inicio, fim;
};

NOMPOL *criar(){
    NOMPOL *p = (NOMPOL *)malloc(sizeof(NOMPOL));
    return p;
}

POLINOMIO *busca(char *A){

}