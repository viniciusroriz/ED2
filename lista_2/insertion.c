#include <stdio.h>
#include <stdlib.h>

void printArray(int *v, int size)
{
    int i;

    printf("%d", v[0]);
    for (i=1; i < size; i++)
        printf(" %d", v[i]);
    printf("\n");
}

void insertionSort(int *v, int size){
    int key, j;

    for(int i=1; i<size; i++){
        key = v[i];
        j = i-1;
        
        while(j >= 0 && v[j] > key){
            v[j+1] = v[j];
            j = j-1;
        }
        v[j + 1] = key;   
    }
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

    insertionSort(vetor, tamanho);
    printArray(vetor, tamanho);
    
    return 0;
}