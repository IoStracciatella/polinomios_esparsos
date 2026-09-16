#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "polinomio.h"


//Casos testes pra essa operacao
//Qual o BIG O dessa operacao?
//Como ela foi implementada

//Em geral, as operacoes possuem ordem n de complexidade,
//apenas PROD e IMPRIMEINV possuem ordem n^2
//GRAU foi o mais rapido com ordem 1

//A ordenacao se mostrou bem util para a facilidade de 
//implementacao, alem de uma ajuda sem precedentes em
//IMPRIME, IMPRIMEINV, GRAU, ADD, COEF, REMOVE, REMOVEMENOR ainda que
//os 4 ultimos ganhem beneficios apenas em "casos medios"
//Ainda assim, a ordenacao nao traz apenas beneficios, em IMPRIMEINV
//e REMOVEMENOR, precisamos percorrer todo o polinomio! Ainda assim,
//acredito que se nao houvesse ordenacao ainda seria necessario
//percorrer o polinomio inteiro (para checar o menor grau com certeza!)

//Acredito que a maior desvantagem dessa estrutura eh o quanto de 
//memoria ela necessita. Criamos diversos TERMOS com muitas variaveis 
//dentro deles; estamos constantemente alocando dinamicamente; e em 
//REMOVE, REMOVEMENOR, LIBERA, precisamos nos preocupar com free e 
//memory leak
//Ainda assim, em testes de grande porte (gerador), o uso de memoria 
//nao passa de 2MB, o que hoje em dia nao eh uma grande quantidade de 
//memoria ram nem pro pior computadora

struct termo{
    long long c;
    int g;
    TERMO *proximo;
};

struct polinomio{
    char *nome;
    TERMO *inicio;
};


//O(n)

//so faz um monte de ADD em sequencia
POLINOMIO *DEF(POLINOMIO *p, int k){
    for (int i=0; i < k; i++){
        long long c;
        int g;
        if (scanf("%lld %d", &c, &g) == 2){
            ADD(p,c,g);
        }
        else{
            printf("ERRO AO LER COEFICIENTE E GRAU\n");
        }
    }
    return p;
    //printf("DEFINICAO FEITA\n");
}

//O(n)  (talvez seria 2n)

//se a == r (ou b == r), entao ele simplesmente faz ADD
//dos termos de b em a, e o ADD cuida do resto
//se r nao eh igual a a ou b, entao ele ADD todos os termos
//de a em r, e depois b em r.
boolean SOMA(POLINOMIO *a, POLINOMIO *b, POLINOMIO *r){

    TERMO *aux[2];

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

//PROD B B B  Pra ver se cria um "polinomio auxiliar" bem
//PROD A B B  Pra testar se substitui bem
//PROD A B R  O normal

//O(n^2)

//Pega um TERMO de a/b, multiplica por todos de b/a e 
//coloca em outro polinomio vazio
//Para casos que a == r ou b == r, usa um polinomio auxiliar
//que, ao fim do processo de cima, troca de lugar os ponteiros
//de "inicio" com r. Depois libera p pra nao ter memory leak
boolean PROD(POLINOMIO *a, POLINOMIO *b, POLINOMIO *r){
    POLINOMIO *p = (POLINOMIO *)malloc(sizeof(POLINOMIO));
    TERMO *auxr;
    TERMO *aux[2];

    p->inicio = NULL;
    p->nome = NULL;
    aux[0] = a->inicio;
    aux[1] = b->inicio;

    while(aux[0] != NULL){
        while (aux[1] != NULL){
            if (b == r || a == r){
                ADD(p,aux[0]->c*aux[1]->c,aux[0]->g+aux[1]->g);
            }
            else{
                ADD(r, aux[0]->c*aux[1]->c,aux[0]->g+aux[1]->g);
            }
            aux[1] = aux[1]->proximo;
        }
        aux[0] = aux[0]->proximo;
        aux[1] = b->inicio;
    }
    if (b == r || a == r){
        auxr = p->inicio;
        p->inicio = r->inicio;
        r->inicio = auxr;
    }
    LIBERA(p);

    return TRUE;
}

//ADD A 2 3  O normal
//ADD A 0 4  Pra ver se faz alguma coisa quando c = 0
//DEF A 1 -3 4 ADD A 3 4  Pra ver se elimina o termo

//O(n)   (talvez o caso medio seria menor)

//Como o polinomio esta em ordem decrescente de grau
//O ADD procura ate achar um termo com g menor ou igual
//que o g dado (todos os outros sao maiores que o g dado!)
//Verifica se aux != NULL, pq se for igual a NULL, da 
//segmentation fault ao tentar acessar o que seria aux->g,
//ou aux->c
//Depois, verifica para os casos em que g dado eh diferente
//de qualquer outro g do polinomio, e separa em quando aux
//ta no inicio, e quando ele ta no meio ou fim
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
            }
        }
        TERMO *pnovo = (TERMO *)malloc(sizeof(TERMO));

        if (aux == p->inicio){
            pnovo->proximo = p->inicio;
            p->inicio = pnovo;
            //printf("ADICAO FEITA\n");
        }
        else{
            pnovo->proximo = aux;
            aux2->proximo = pnovo;
            //printf("ADICAO FEITA\n");
        }
        pnovo->c = c;
        pnovo->g = g;
        return TRUE;
    }
    else{
        //printf("ADICAO NAO FEITA\n");
        return FALSE;
    }
}


//ESCALA A 0  Pra ver se zera o polinomio

//O(n)

//Passa por todos os termos e multiplica pelo
//c dado
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

//COEF A 3 (nao tem grau 3)  Pra ver se faz algo 
//ou se da segmentation fault, e se printa 0

//O(n)   (talvez no caso medio seja menor)

//a ordem do while parece importar para nao dar
//segmentation fault
//Como eh ordenado, so vai ate quando o g dado 
//for maior q o g do TERMO
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
        printf("0\n");
        return FALSE;
    }
    else{
        return FALSE;
    }
}

//REMOVE A 4 (nao tem grau 4)  Pra ver se faz algo ou 
//se da segmentation fault

//O(n)   (talvez no caso medio seja menor)

//Procura por um TERMO com g igual ao g dado
//Para se chegar no fim ou se g dado for maior que g
//do TERMO (ordenado)
//Com as condicoes do if, separa em dois casos: inicio 
//e meio/fim. A unica diferenca eh que dois nos vao se 
//conectar.
//ao fim, da free no ponteiro que aponta pro TERMO pra
//nao dar memory leak
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
    else{
        return FALSE;
    }
}

//REMOVEMENOR A (A eh vazio)  Pra ver se faz algo  

//O(n)   (talvez seja n-1)

//Percorre ate o fim do polinomio (ordenado)
//aux2 != NULL eh nos casos em que o polinomio tem 
//1 ou mais termos, pq ai ele percorre alguma coisa
//apos encontrar o menor TERMO, aux->proximo ja
//vai ser NULL (eh o ultimo TERMO!)
//free no aux pra evitar memory leak
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

//GRAU A (A eh vazio)  Pra ver se faz algo e 
//se printa -1

//O(1)   (UvU)

//O PODER DA ORDENACAO DESCRESCENTE DE GRAU
//simplesmente printa o primeiro TERMO do 
//polinomio
int GRAU(POLINOMIO *p){
    if (p != NULL){
        if (p->inicio != NULL){
            printf("%d\n", p->inicio->g);
            return p->inicio->g;
        }
        else{
            printf("-1\n");
            return -1;
        }
    }
    else{
        return FALSE;
    }
}

//DEF A 0 LIBERA A IMPRIME A  Pra ver se deleta certo 
//e se acontece algo ao imprimir algo inexistente

//O(n)

//Percorre todo o polinomio, printando ao longo do 
//caminho, porque eh ordenado
//o ultimo eh printado a parte, porque nao precisa 
//de " ", mas precisa de "\n"
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

//sem

//O(n^2)  (talvez seria (n^2)/2)

//Vai ate o fim do polinomio e printa o ultimo
//e penultimo termo
//depois, faz aux voltar ao inicio do polinomio
//e o manda ir ate o TERMO exatament antes de
//aux2, e entao printa esse termo
//Dai, aux2 vira aux, ou seja, volta um termo
//e aux volta ao inicio
//Esse processo continua ate aux2 estar no inicio
void IMPRIMEINV(POLINOMIO *p){
    TERMO *aux = p->inicio;
    TERMO *aux2 = NULL;

    while(aux->proximo != NULL){
        aux2 = aux;
        aux = aux->proximo;
    }
    printf("%lld*x^%d ", aux->c,aux->g);
    printf("%lld*x^%d ", aux2->c,aux2->g);
    while(aux2 != p->inicio){
        aux = p->inicio;
        while(aux->proximo != aux2){
            aux = aux->proximo;
        }
        printf("%lld*x^%d ", aux->c,aux->g);
        aux2 = aux;
    }
    printf("\n");
}

//ADD A 0 LIBERA A teste  Pra ver se A foi deletado
//(ter ajuda do valgrind)

//O(n)

//Deleta o primeiro TERMO do polinomio ate 
//nao ter mais nenhum (p->inicio = NULL)
//Da free no nome, pois ele foi alocado 
//dinamicamente no main.c
//Da free em p, porque tambem foi alocado
//dinamicamente no lista.c|add_lista()
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

