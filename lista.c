#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "polinomio.h"

struct lista{
    POLINOMIO *nompol[TAM_MAX];
    int final;
    int rem_index;
};

struct polinomio{
    char *nome;
    TERMO *inicio;
};


void busca_func(char *c, POLINOMIO *a, POLINOMIO *b, POLINOMIO *r){
    if (strcmp(c,"DEF") == 0){
        int k;
        scanf("%d", &k);
        DEF(a,k);
    }
    else if(strcmp(c, "SOMA") == 0){
        SOMA(a, b, r);
    }
    else if(strcmp(c, "PROD") == 0){
        PROD(a, b, r);
    }
    else if(strcmp(c, "ADD") == 0){
        long long c;
        int g;
        scanf("%lld %d", &c, &g);
        ADD(a,c,g);
    }
    else if(strcmp(c, "ESCALA") == 0){
        long long c;
        scanf("%lld", &c);
        ESCALA(a,c);
    }
    else if(strcmp(c, "COEF") == 0){
        int g;
        scanf("%d", &g);
        COEF(a,g);
    }
    else if(strcmp(c, "REMOVE") == 0){
        int g;
        scanf("%d", &g);
        REMOVE(a,g);
    }
    else if(strcmp(c, "REMOVEMENOR") == 0){
        REMOVEMENOR(a);
    }
    else if(strcmp(c, "GRAU") == 0){
        GRAU(a);
    }
    else if(strcmp(c, "IMPRIME") == 0){
        IMPRIME(a);
    }
    else if(strcmp(c, "IMPRIMEINV") == 0){
        IMPRIMEINV(a);
    }
    else if(strcmp(c, "LIBERA") == 0){
        LIBERA(a);
    }
}


boolean criar_polinomio(char *A, char *c, LISTA *lista){
    if (lista != NULL){
        POLINOMIO *p;
        p = busca(A, lista);
        if (p != NULL){
            rem_lista(p, lista);
        }
        add_lista(A, lista);
        busca_func(c, lista->nompol[lista->final-1], NULL, NULL);
        return TRUE;
    }
}

boolean busca_tripla(char *A, char *B, char *R, char *c, LISTA *lista){
    if (lista != NULL){
        POLINOMIO *a = NULL;
        POLINOMIO *b = NULL;
        POLINOMIO *r = NULL;
        int i = 0;
        while(a == NULL || b == NULL || r == NULL){
            if (i == lista->final){
                break;
            }
            if (strcmp(lista->nompol[i]->nome,A) == 0){
                a = lista->nompol[i];
            }
            if (strcmp(lista->nompol[i]->nome,B) == 0){
                b = lista->nompol[i];
            }
            if (strcmp(lista->nompol[i]->nome,R) == 0){
                r = lista->nompol[i];
                lista->rem_index = i;
            }
            i++;
        }
        if (a != NULL && b != NULL){
            if (lista->final < TAM_MAX){
                if (r == NULL){
                    add_lista(R, lista);

                    r = lista->nompol[lista->final-1];
                }
                else if(r != a && r != b){
                    rem_lista(r, lista);
                    add_lista(R, lista);

                    r = lista->nompol[lista->final-1];
                }
                else{
                    free(R);
                }
            }
            busca_func(c, a, b, r);
            return TRUE;
        }
        else{
            free(R);
        }
        return FALSE;
    }
}


void busca_opera(char *A, char *c, LISTA *lista){
    POLINOMIO *p;
    p = busca(A, lista);
    busca_func(c, p , NULL, NULL);
}

void libera(char *A, LISTA *lista){
    POLINOMIO *p;
    p = busca(A, lista);
    rem_lista(p, lista);
}

void fim(char *c, LISTA *lista){
    if (lista != NULL){
        while (lista->final > 0){
            libera(lista->nompol[lista->final-1]->nome, lista);
        }
        free(lista);
    }
}



LISTA *criar_lista(){
    LISTA *p = (LISTA *)malloc(sizeof(LISTA));
    p->final = 0;
    p->rem_index = 0;
    return p;
}

void add_lista(char *A, LISTA *lista){
    POLINOMIO *p = (POLINOMIO *)malloc(sizeof(POLINOMIO));
    lista->nompol[lista->final] = p;

    lista->nompol[lista->final]->nome = A;
    lista->nompol[lista->final]->inicio = NULL;
    lista->final++;
}

POLINOMIO *busca(char *A, LISTA *lista){
    if (lista != NULL){
        POLINOMIO *p = NULL;
        int i = 0;
        while(p == NULL){
            if (i == lista->final){
                break;
            }
            if (strcmp(lista->nompol[i]->nome,A) == 0){
                p = lista->nompol[i];
                lista->rem_index = i;
                break;
            }
            i++;
        }
        return p;
    }
}

void rem_lista(POLINOMIO *p, LISTA *lista){
    LIBERA(p);
    for (int j=lista->rem_index;j<lista->final-1;j++){
        lista->nompol[j] = lista->nompol[j+1];
    }
    lista->nompol[lista->final-1] = NULL;
    if (lista->final > 0){
        lista->final--;
    }
}


void teste(LISTA *lista){
        printf("final: %d\nrem_index: %d\n", lista->final, lista->rem_index);
        for (int i=0; i<lista->final;i++){
            printf("%s ", lista->nompol[i]->nome);
        }
        printf("\n"); 
}