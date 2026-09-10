#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "polinomio.h"

struct lista{
    POLINOMIO *nompol[TAM_MAX];
    int final;
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

LISTA *criar_lista(){
    LISTA *p = (LISTA *)malloc(sizeof(LISTA));
    p->final = 0;
    return p;
}

boolean inserir(char *A, char *c, LISTA *lista){
    if (lista != NULL){
        POLINOMIO *p = (POLINOMIO *)malloc(sizeof(POLINOMIO));
        lista->nompol[lista->final] = p;

        lista->nompol[lista->final]->nome = A;
        lista->nompol[lista->final]->inicio = NULL;

        busca_func(c, lista->nompol[lista->final], NULL, NULL);
        lista->final++;
        return TRUE;
    }
}

boolean busca(char *A, char *c, LISTA *lista){
    if (lista != NULL){
        POLINOMIO *p = NULL;
        int i = 0;
        while(p == NULL){
            if (i == lista->final){
                break;
            }
            if (strcmp(lista->nompol[i]->nome,A) == 0){
                p = lista->nompol[i];
                break;
            }
            i++;
        }
        if (strcmp(c,"LIBERA") == 0){
            busca_func(c, p, NULL, NULL);
            for (int j=i;j<lista->final-1;j++){
                lista->nompol[j] = lista->nompol[j+1];
            }
            lista->nompol[lista->final-1] = NULL;
            if (lista->final > 0){
                lista->final--;
            }
        }
        else{
            busca_func(c, p, NULL, NULL);
        }
        return TRUE;
    }
}

boolean busca_tripla(char *A, char *B, char *R, char *c, LISTA *lista){
    if (lista != NULL){
        POLINOMIO *a = NULL;
        POLINOMIO *b = NULL;
        POLINOMIO *r = NULL;
        int i = 0;
        while(a == NULL || b == NULL){
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
            }
            i++;
        }

        if (lista->final < TAM_MAX){
            if (r == NULL){
                POLINOMIO *p = (POLINOMIO *)malloc(sizeof(POLINOMIO));
                lista->nompol[lista->final] = p;

                lista->nompol[lista->final]->nome = R;
                lista->nompol[lista->final]->inicio = NULL;
                lista->final++;
                r = lista->nompol[lista->final-1];
            }
            else if(r != a && r != b){
                LIBERA(r);
                POLINOMIO *p = (POLINOMIO *)malloc(sizeof(POLINOMIO));
                lista->nompol[lista->final] = p;

                lista->nompol[lista->final]->nome = R;
                lista->nompol[lista->final]->inicio = NULL;
                lista->final++;
                free(R);
                r = lista->nompol[lista->final-1];
            }
        }
        busca_func(c, a, b, r);
        return TRUE;
    }
}

void teste(LISTA *lista){
        printf("final: %d\n", lista->final);
        for (int i=0; i<lista->final;i++){
            printf("%s ", lista->nompol[i]->nome);
        }
        printf("\n"); 
}


void fim(char *c, LISTA *lista){
    if (lista != NULL){
        while (lista->final > 0){
            busca(lista->nompol[lista->final-1]->nome, "LIBERA", lista);
            printf("%d\n", lista->final);
        }
    }
}
