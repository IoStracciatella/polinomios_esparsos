#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "polinomio.h"

struct termo{
    long long c;
    int g;
    TERMO *proximo;
};

struct polinomio{
    char *nome;
    TERMO *inicio;
};


POLINOMIO *DEF(POLINOMIO *p, int k){
    for (int i=0; i < k; i++){
        long long c;
        int g;
        scanf("%lld %d", &c, &g);
        ADD(p,c,g);
    }
    return p;
    //printf("DEFINICAO FEITA\n");
}

boolean SOMA(POLINOMIO *a, POLINOMIO *b, POLINOMIO *r){

    if (a != NULL && b != NULL){
        TERMO *aux[2];
        TERMO *auxr = r->inicio;

        aux[0] = a->inicio;
        aux[1] = b->inicio;

        if (a == r){
            while (aux[1] != NULL){
                ADD(a,aux[1]->c,aux[1]->g);
                aux[1] = aux[1]->proximo;
            }
            return TRUE;
        }
        else if (b == r){
            while (aux[0] != NULL){
                ADD(b,aux[0]->c,aux[0]->g);
                aux[0] = aux[0]->proximo;
            }
            return TRUE;
        }

        for (int i=0;i<2;i++){
            while(aux[i] != NULL){
                ADD(r,aux[i]->c,aux[i]->g);
                aux[i] = aux[i]->proximo;
            }
        }
        return TRUE;
    }
}

//falta
void PROD(POLINOMIO *a, POLINOMIO *b, POLINOMIO *r){
    //free R se ja existir
}

boolean ADD(POLINOMIO *p, long long c, int g){

    if (p != NULL && c != 0){
        TERMO *aux = p->inicio;
        TERMO *aux2 = NULL;
        while (aux != NULL && aux->g > g){
            aux2 = aux;
            aux = aux->proximo;
        }
        if (aux != NULL){
            if (aux->g == g){
                if (aux->c == -c){
                    REMOVE(p, aux->g);
                }
                else{
                    aux->c = aux->c + c;
                }
                return TRUE;
                //return aux;
            }
        }
        if (aux == p->inicio){
            TERMO *pnovo = (TERMO *)malloc(sizeof(TERMO));
            pnovo->proximo = p->inicio;
            p->inicio = pnovo;
            pnovo->c = c;
            pnovo->g = g;
            //printf("ADICAO FEITA\n");
            return TRUE;
            //return pnovo;
        }
        else{
            TERMO *pnovo = (TERMO *)malloc(sizeof(TERMO));
            pnovo->proximo = aux;
            aux2->proximo = pnovo;
            pnovo->c = c;
            pnovo->g = g;
            return TRUE;
            //printf("ADICAO FEITA\n");
            //return pnovo;
        }
    }
    else{
        //printf("ADICAO NAO FEITA\n");
        return FALSE;
    }
}

boolean ESCALA(POLINOMIO *p, long long c){

    if (p != NULL && p->inicio != NULL){
        TERMO *aux = p->inicio;
        while(aux != NULL){
            aux->c *= c;
            aux = aux->proximo;
        }
        return TRUE;
    }
    else{
        return FALSE;
    }
}

int COEF(POLINOMIO *p, int g){

    if (p != NULL && p->inicio != NULL){
        TERMO *aux = p->inicio;
        while (aux != NULL && aux->g >= g){
            if (aux->g == g){
                printf("%lld\n", aux->c);
                return aux->c;
            }
            else{
                aux = aux->proximo;
            }
            
        }
        return FALSE;
    }
}

boolean REMOVE(POLINOMIO *p, int g){

    if (p != NULL && p->inicio != NULL){
        TERMO *aux = p->inicio;
        TERMO *aux2 = NULL;

        while (aux != NULL && aux->g > g){
            aux2 = aux;
            aux = aux->proximo;
        }
        
        if (aux != NULL && aux->g == g){
            if (aux == p->inicio){
                p->inicio = aux->proximo;
            }
            else{
                aux2->proximo = aux->proximo;
            }
            aux->proximo = NULL;
            free(aux);
            return TRUE;
        }
        else{
            return FALSE;
        }
    }
}

boolean REMOVEMENOR(POLINOMIO *p){

    if (p != NULL && p->inicio != NULL){
        TERMO *aux = p->inicio;
        TERMO *aux2 = NULL;
        while (aux->proximo != NULL){
            aux2 = aux;
            aux = aux->proximo;
        }
        if (aux2 != NULL){
            aux2->proximo = NULL;
        }
        else{
            p->inicio = NULL;
        }
        free(aux);
        return TRUE;
    }
    return FALSE;
}

int GRAU(POLINOMIO *p){

    if (p != NULL && p->inicio != NULL){
        printf("%d\n", p->inicio->g);
        return p->inicio->g;
    }
}

void IMPRIME(POLINOMIO *p){

    if (p != NULL){
        if (p->inicio != NULL){
            TERMO *aux = p->inicio;
            while(aux->proximo != NULL){
                printf("%lld*x^%d ", aux->c, aux->g);
                aux = aux->proximo;
            }
            printf("%lld*x^%d\n", aux->c,aux->g);
        }
        else{
            printf("0\n");
        }
    }
}

//falta
void IMPRIMEINV(POLINOMIO *p){

}


void LIBERA(POLINOMIO *p){

    if (p != NULL){
        while(p->inicio != NULL){
            REMOVE(p,p->inicio->g);
        }
        free(p->nome);
        p->nome = NULL;
        free(p);
        p = NULL;
    }

}

