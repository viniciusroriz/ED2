#include <stdio.h>
#include <stdlib.h>

void swap(int* xp, int* yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int* v, int n){
    int menor;
    
    for(int i=0; i<n-1; i++){
        menor = i;
        for(int j=i+1; j<n; j++){
            if(v[j] < v[menor])
                menor = j;
        }
        swap(&v[menor], &v[i]);
    }
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

    selectionSort(vetor, tamanho);
    printArray(vetor, tamanho);

    return 0;
}