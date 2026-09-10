#include <stdio.h>
#include <stdlib.h>

typedef struct teste TESTE;

struct teste{
    char *nome;
    int *prox;
};

int main(){
    TESTE *p = (TESTE *)malloc(sizeof(TESTE));
    char *nomed = (char *)malloc(sizeof(char)*32);
    nomed = "DOWDJWIODW";
    TESTE *v[23];
    v[3]->nome = "chau";
    printf("%s\n", v[3]->nome);

    printf("%s", nomed);


    return 0;
}

/*
        while(auxa != NULL || auxb != NULL){
            if (auxr == NULL){
                //create a new node
                if (auxa == NULL){
                    auxr = ADD(r->nome,auxb->c,auxb->g);
                    auxb = auxb->proximo;
                    printf("dede\n");
                }
                else if (auxb == NULL){
                    auxr = ADD(r->nome,auxa->c,auxa->g);
                    auxa = auxa->proximo;
                    printf("dede\n");
                }
                else{
                    if (auxa->g > auxb->g){
                        auxr = ADD(r->nome,auxa->c,auxa->g);
                        auxa = auxa->proximo;
                    }
                    else if (auxa->g < auxb->g){
                        auxr = ADD(r->nome,auxb->c,auxb->g);
                        auxb = auxb->proximo;
                        printf("dududu\n");
                    }
                    else if (auxa->g == auxb->g){
                        auxr = ADD(r->nome,auxa->c+auxb->c,auxa->g);
                        auxa = auxa->proximo;
                        auxb = auxb->proximo;
                        printf("vdvdvd\n");
                    }
                }
                
            }
            else{
                //replace c and g with whatever c and g you have
                if (auxa == NULL){
                    auxr->c = auxb->c;
                    auxr->g = auxb->g;
                    auxb = auxb->proximo;
                }
                else if (auxb == NULL){
                    auxr->c = auxa->c;
                    auxr->g = auxa->g;
                    auxa = auxa->proximo;
                }
                else{
                    if (auxa->g > auxb->g){
                        auxr->c = auxa->c;
                        auxr->g = auxa->g;
                        auxa = auxa->proximo;
                    }
                    else if (auxa->g < auxb->g){
                        auxr->c = auxb->c;
                        auxr->g = auxb->g;
                        auxb = auxb->proximo;
                    }
                    else if (auxa->g == auxb->g){
                        auxr->c = auxa->c+auxb->c;
                        auxr->g = auxa->g;
                        auxa = auxa->proximo;
                        auxb = auxb->proximo;
                    }
                }
            }
            auxr = auxr->proximo;
        }
DEF primpol 6
2 3
4 1 
199 29
3 48
81 2
3 49
DEF segpol 4
1 20
3 41
292 12
48 124
SOMA primpol segpol terpol
LIBERA primpol
*/