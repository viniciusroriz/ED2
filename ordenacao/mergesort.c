#include <stdio.h>
#include <stdlib.h>

// ----------------------------------------- macros
typedef int Item;
#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { Item t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

void merge(Item *v, int l, int meio, int r){
    Item *temp = malloc(sizeof(Item)*(r-l+1));
    int i=l; // controle de progresso na primeira metade
    int j=meio+1; // controle de progresso na segunda metade
    int k=0; // controle de progresso no vetor temp

    while(lesseq(i,meio) && lesseq(j,r)){
        if(lesseq(v[i],v[j]))
            temp[k++] = v[i++];
        else
            temp[k++] = v[j++];
    }

    while(lesseq(i,meio))
        temp[k++] = v[i++];
    while(lesseq(j,r))
        temp[k++] = v[j++];
    
    k=0;
    for(i=l; i<=r; i++){
        v[i] = temp[k++];
    }

    free(temp);
}

void mergesort(Item *v, int l, int r){
    if(l>=r) return;

    int meio = (l+r)/2;
    
    mergesort(v, l, meio);
    mergesort(v, meio+1, r);
    merge(v, l, meio, r);
}