#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "polinomio.h"


typedef struct termo TERMO;
struct termo{
    int c;
    int g;
    TERMO *proximo;
};

struct polinomio{
    char *nome;
    TERMO *inicio;
};
static POLINOMIO *nompol[TAM_MAX];
static int fim = 0;


void DEF(char nome[32], int k){
    POLINOMIO *p = (POLINOMIO *)malloc(sizeof(POLINOMIO));
    p->nome = nome;
    p->inicio = NULL;
    nompol[fim] = p;
    fim++;

    for (int i=0; i < k; i++){
        int c, g;
        scanf("%d %d", &c, &g);
        ADD(p->nome,c,g);
    }
    //printf("DEFINICAO FEITA\n");
}

void SOMA(char A[32], char B[32], char R[32]){
    printf("%s %s %s\n", A, B, R);
}

void PROD(char A[32], char B[32], char R[32]){
    printf("%s %s %s\n", A, B, R);
}

boolean ADD(char A[32], int c, int g){
    POLINOMIO *p = NULL;
    for (int i = 0;i<fim;i++){
        if (strcmp(nompol[i]->nome,A) == 0){
            p = nompol[i];
        }
    }
    if (p != NULL){
        TERMO *aux = p->inicio;
        TERMO *aux2 = NULL;
        while (aux != NULL && aux->g > g){
            aux2 = aux;
            aux = aux->proximo;
        }

        if (aux != NULL){
            if (aux->g == g){
                aux->c += c;
                return TRUE;
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
        }
        else{
            TERMO *pnovo = (TERMO *)malloc(sizeof(TERMO));
            pnovo->proximo = aux;
            aux2->proximo = pnovo;
            pnovo->c = c;
            pnovo->g = g;
            //printf("ADICAO FEITA\n");
        }
        return TRUE;
    }
    else{
        //printf("ADICAO NAO FEITA\n");
        return FALSE;
    }
}

boolean ESCALA(char A[32], int c){
    POLINOMIO *p = NULL;
    for (int i = 0;i<fim;i++){
        if (strcmp(nompol[i]->nome,A) == 0){
            p = nompol[i];
        }
    }
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

int COEF(char A[32], int g){
    POLINOMIO *p = NULL;
    for (int i = 0;i<fim;i++){
        if (strcmp(nompol[i]->nome,A) == 0){
            p = nompol[i];
        }
    }
    if (p != NULL && p->inicio != NULL){
        TERMO *aux = p->inicio;
        while (aux->g >= g){
            if (aux->g == g){
                printf("%d\n", aux->c);
                return aux->c;
            }
            else{
                aux = aux->proximo;
            }
        }
        return FALSE;
    }
}

boolean REMOVE(char A[32], int g){
    POLINOMIO *p = NULL;
    for (int i = 0;i<fim;i++){
        if (strcmp(nompol[i]->nome,A) == 0){
            p = nompol[i];
        }
    }
    if (p != NULL && p->inicio != NULL){
        TERMO *aux = p->inicio;
        TERMO *aux2 = NULL;

        while (aux->g > g && aux != NULL){
            aux2 = aux;
            aux = aux->proximo;
        }
        if (aux->g == g){
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

boolean REMOVEMENOR(char A[32]){
    POLINOMIO *p = NULL;
    for (int i = 0;i<fim;i++){
        if (strcmp(nompol[i]->nome,A) == 0){
            p = nompol[i];
        }
    }
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

int GRAU(char A[32]){
    POLINOMIO *p = NULL;
    for (int i = 0;i<fim;i++){
        if (strcmp(nompol[i]->nome,A) == 0){
            p = nompol[i];
        }
    }
    if (p != NULL && p->inicio != NULL){
        printf("%d\n", p->inicio->g);
        return p->inicio->g;
    }
}

void IMPRIME(char A[32]){
    POLINOMIO *p = NULL;
    for (int i = 0;i<fim;i++){
        if (strcmp(nompol[i]->nome,A) == 0){
            p = nompol[i];
        }
    }
    if (p != NULL){
        if (p->inicio != NULL){
            TERMO *aux = p->inicio;
            while(aux->proximo != NULL){
                printf("%d*x^%d ", aux->c, aux->g);
                aux = aux->proximo;
            }
            printf("%d*x^%d\n", aux->c,aux->g);
        }
        else{
            printf("0\n");
        }
    }
}

void IMPRIMEINV(char A[32]){
    POLINOMIO *p = NULL;

    for (int i = 0;i<fim;i++){
        printf("%s", nompol[i]->nome);

        if (strcmp(nompol[i]->nome,A) == 0){
            p = nompol[i];
        }
    }
}


void LIBERA(char A[32]){
    POLINOMIO *p = NULL;
    for (int i = 0;i<fim;i++){
        if (strcmp(nompol[i]->nome,A) == 0){
            p = nompol[i];
        }
    }
}

void FIM(){
    
}
