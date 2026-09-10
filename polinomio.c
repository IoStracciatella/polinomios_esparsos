#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
static POLINOMIO *nompol[TAM_MAX];
static int fim = 0;


POLINOMIO *DEF(char nome[32], int k){
    POLINOMIO *p = (POLINOMIO *)malloc(sizeof(POLINOMIO));
    p->nome = nome;
    p->inicio = NULL;
    nompol[fim] = p;
    fim++;

    for (int i=0; i < k; i++){
        long long c;
        int g;
        scanf("%lld %d", &c, &g);
        ADD(p->nome,c,g);
    }
    return p;
    //printf("DEFINICAO FEITA\n");
}

boolean SOMA(char A[32], char B[32], char R[32]){
    POLINOMIO *a = NULL;
    POLINOMIO *b = NULL;
    POLINOMIO *r = NULL;
    int i = 0;

    while(a == NULL || b == NULL){
        if (strcmp(nompol[i]->nome,A) == 0){
            a = nompol[i];
        }
        else if (strcmp(nompol[i]->nome,B) == 0){
            b = nompol[i];
        }
        else if (strcmp(nompol[i]->nome,R) == 0){
            r = nompol[i];
        }

        if (i == fim-2){
            break;
        }
        i++;
    }

    if (r == NULL){
        r = DEF(R, 0);
    }
    else if(r != a && r != b){
        LIBERA(R);
        r = DEF(R,0);
        free(R);
    }

    if (a != NULL && b != NULL){
        TERMO *aux[2];
        TERMO *auxr = r->inicio;

        aux[0] = a->inicio;
        aux[1] = b->inicio;

        if (a == r){
            while (aux[1] != NULL){
                ADD(a->nome,aux[1]->c,aux[1]->g);
                aux[1] = aux[1]->proximo;
            }
            return TRUE;
        }
        else if (b == r){
            while (aux[0] != NULL){
                ADD(a->nome,aux[0]->c,aux[0]->g);
                aux[0] = aux[0]->proximo;
            }
            return TRUE;
        }

        for (int i=0;i<2;i++){
            while(aux[i] != NULL){
                ADD(r->nome,aux[i]->c,aux[i]->g);
                aux[i] = aux[i]->proximo;
            }
        }
        return TRUE;
    }


}

//falta
void PROD(char A[32], char B[32], char R[32]){
    printf("%s %s %s\n", A, B, R);
    //free R se ja existir
}

TERMO *ADD(char A[32], long long c, int g){
    POLINOMIO *p = NULL;
    int i = 0;
    while(p == NULL){
        if (strcmp(nompol[i]->nome,A) == 0){
            p = nompol[i];
        }
        if (i == fim-2){
            break;
        }
        i++;
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
                return aux;
            }
        }
        if (aux == p->inicio){
            TERMO *pnovo = (TERMO *)malloc(sizeof(TERMO));
            pnovo->proximo = p->inicio;
            p->inicio = pnovo;
            pnovo->c = c;
            pnovo->g = g;
            //printf("ADICAO FEITA\n");
            return pnovo;
        }
        else{
            TERMO *pnovo = (TERMO *)malloc(sizeof(TERMO));
            pnovo->proximo = aux;
            aux2->proximo = pnovo;
            pnovo->c = c;
            pnovo->g = g;
            //printf("ADICAO FEITA\n");
            return pnovo;
        }
    }
    else{
        //printf("ADICAO NAO FEITA\n");
        return FALSE;
    }
}

boolean ESCALA(char A[32], long long c){
    POLINOMIO *p = NULL;
    int i = 0;
    while(p == NULL){
        if (strcmp(nompol[i]->nome,A) == 0){
            p = nompol[i];
        }
        if (i == fim-2){
            break;
        }
        i++;
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
    int i = 0;
    while(p == NULL){
        if (strcmp(nompol[i]->nome,A) == 0){
            p = nompol[i];
        }
        if (i == fim-2){
            break;
        }
        i++;
    }
    if (p != NULL && p->inicio != NULL){
        TERMO *aux = p->inicio;
        while (aux->g >= g){
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

boolean REMOVE(char A[32], int g){
    POLINOMIO *p = NULL;
    int i = 0;
    while(p == NULL){
        if (strcmp(nompol[i]->nome,A) == 0){
            p = nompol[i];
        }
        if (i == fim-2){
            break;
        }
        i++;
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
    int i = 0;
    while(p == NULL){
        if (strcmp(nompol[i]->nome,A) == 0){
            p = nompol[i];
            break;
        }
        if (i == fim-2){
            break;
        }
        i++;
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
    int i = 0;
    while(p == NULL){
        if (strcmp(nompol[i]->nome,A) == 0){
            p = nompol[i];
        }
        if (i == fim-2){
            break;
        }
        i++;

    }
    if (p != NULL && p->inicio != NULL){
        printf("%d\n", p->inicio->g);
        return p->inicio->g;
    }
}

void IMPRIME(char A[32]){
    POLINOMIO *p = NULL;
    int i = 0;
    while(p == NULL){
        if (strcmp(nompol[i]->nome,A) == 0){
            p = nompol[i];
        }
        if (i == fim-2){
            break;
        }
        i++;
    }

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
    int i = 0;
    while(p == NULL){
        if (strcmp(nompol[i]->nome,A) == 0){
            p = nompol[i];
            break;
        }
        if (i == fim-1){
            break;
        }
        i++;
    }

    if (p != NULL){
        while(p->inicio != NULL){
            REMOVEMENOR(A);
        }
        free(p->nome);
        p->nome = NULL;
        free(p->inicio);
        free(p);
        p = NULL;
    }

    for (int j=i;j<fim-1;j++){
        nompol[j] = nompol[j+1];
    }
    nompol[fim-1] = NULL;
    fim--;

}

void FIM(){
    
}
