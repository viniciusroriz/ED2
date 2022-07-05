#include <stdio.h>
#include <stdlib.h>

void swap(int* xp, int* yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void printArray(int *v, int size)
{
    int i;

    printf("%d", v[0]);
    for (i=1; i < size; i++)
        printf(" %d", v[i]);
    printf("\n");
}

int main(){
    int tamanho = 0, limite = 50;
    int *vetor = malloc(sizeof(int)*limite);

    while(scanf("%d", &vetor[tamanho]) != EOF){
        if(++tamanho == limite){
            limite *= 2;
            vetor = realloc(vetor, sizeof(int)*limite);
        }
    }

    printArray(vetor, tamanho);
    
    return 0;
}