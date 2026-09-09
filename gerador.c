#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QTD_C 5       //50,000
#define MAX_G 2000        //2,000
#define MAX_C 200      //500,000
#define QTD_ESC 5     //20,000


void imprime_cg(int v[]){
    for (int i = 0;i < QTD_C;i++){
        int c = rand()%MAX_C;

        int j = 0;
        while (j < i){
            if (c == v[j]){
                c = rand()%MAX_C;
                j = 0;
            }
            else{
                j++;
            }
        }
        v[i] = c;

        int g = (rand()%MAX_G)-(MAX_G/2);
        printf("%d %d\n", c, g);
    }
}

int main(){

    srand(time(NULL));
        int v[QTD_C];
    printf("DEF A %d\n", QTD_C);

    imprime_cg(v);

    for (int i = 0; i < QTD_ESC; i++){
        int c = (rand()%10)-5;
        if (c >= 0){
            c = 1;
        }
        else{
            c = -1;
        }
        printf("ESCALA A %d\n", c);
    }
    printf("IMPRIME A\n");
    printf("GRAU A\n");
    printf("DEF B %d\n", QTD_C);

    imprime_cg(v);

    //printf("SOMA A B R\n");

    return 0;
}