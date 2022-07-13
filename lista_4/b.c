#include <stdio.h>
#include <stdlib.h>

typedef int Item;
#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { Item t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

int separa(Item *v, int l, int r){
    // Ordena um unico elemento (pivot), garantindo que todos os elementos
    // maiores que ele ficam a sua direita e os menores, a esquerda.
    
    Item pivot = v[r];
    int j=l;

    for(int k=l; k<r; k++){
        if(lesseq(v[k],pivot)){
            exch(v[k], v[j]);
            j++;
        }
    }
    exch(v[j], v[r]);

    return j;
}

void quicksortm3(Item *v, int l, int r){
    if(lesseq(r,l)) return;
    
    int meio = (l+r)/2;
    cmpexch(v[meio],v[r]);
    cmpexch(v[l],v[meio]);
    cmpexch(v[r],v[meio]);

    int j = separa(v,l,r);
    quicksortm3(v,l,j-1);
    quicksortm3(v,j+1,r);
}

void printaVetor(int* vetor, int n){
    printf("\n%d", vetor[0]);

    for(int i=1; i < n; i++){
        printf(" %d", vetor[i]);
    }
    
    printf("\n");
}

int main(void){
    int v[100000], n;

    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &v[i]);
    
    quicksortm3(v, 0, n-1);
    printaVetor(v, n);

    return 0;
}