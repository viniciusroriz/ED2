#include <stdio.h>
#include <stdlib.h>

typedef int Item;

void printaVetor(int* vetor, int n){
    printf("\n%d", vetor[0]);

    for(int i=1; i < n; i++){
        printf(" %d", vetor[i]);
    }
    
    printf("\n");
}

void insertionsort(Item *v, int l, int r){
    Item key;
    int j;
    int size = r-l;

    for(int i=l+1; i<=r; i++){
        key = v[i];
        j = i-1;
        
        while(j >= 0 && v[j] > key){
            v[j+1] = v[j];
            j = j-1;
        }
        v[j + 1] = key;   
    }
} 

int main(void){
    int v[10] = {3,8,4,5,9,7,2,6,10,1};

    insertionsort(v, 0, 9);
    printaVetor(v, 10);

    return 0;
}