#include <stdio.h>
#include <stdlib.h>

#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { Item t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

typedef struct Item{
    int valor;
    int antiga_pos;
}item;

int buscaB(item arr[], int l, int r, int x){
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (arr[mid].valor == x)
            return arr[mid].antiga_pos;
        if (arr[mid].valor > x)
            return buscaB(arr, l, mid - 1, x);

        return buscaB(arr, mid + 1, r, x);
    }
  
    return -1;
}

void merge(item *v, int l, int meio, int r){
    item *temp = malloc(sizeof(item)*(r-l+1));
    int i = l, j = meio+1, k=0;

    while(lesseq(i,meio) && lesseq(j,r)){
        if(lesseq(v[i].valor, v[j].valor)){
            temp[k].antiga_pos = v[i].antiga_pos;
            temp[k++].valor = v[i++].valor;

        }else{
            temp[k].antiga_pos = v[j].antiga_pos;
            temp[k++].valor = v[j++].valor;
        }
    }

    while(lesseq(i,meio)){
        temp[k].antiga_pos = v[i].antiga_pos;
        temp[k++].valor = v[i++].valor;
    }
    while(lesseq(j,r)){
        temp[k].antiga_pos = v[j].antiga_pos;
        temp[k++].valor = v[j++].valor;
    }

    k = 0;
    for(i=l; i<=r; i++){
        v[i].antiga_pos = temp[k].antiga_pos;
        v[i].valor = temp[k++].valor;
    }

    free(temp);
}

void mergesort(item *v, int l, int r){
    if(l>=r) return;
    int meio = (l+r)/2;
    mergesort(v, l, meio);
    mergesort(v, meio+1, r);
    merge(v, l, meio, r);
}

void printaVetor(item* vetor, int n){
    printf("\n%d", vetor[0].valor);

    for(int i=1; i < n; i++){
        printf(" %d", vetor[i].valor);
    }
    
    printf("\n\n");
}

int main(){
    int n, m, busca;
    item v[100000];

    scanf("%d", &n);
    scanf("%d", &m);

    for(int i=0; i<n; i++){
        scanf("%d", &v[i].valor);
        v[i].antiga_pos = i;
    }

    //printf("=== vetor desordenado:");
    //printaVetor(v, n);
    mergesort(v, 0, n-1);
    //printf("=== vetor ordenado:");
    //printaVetor(v, n);

    for(int i=0; i<m; i++){
        scanf("%d", &busca);
        printf("%d\n", buscaB(v, 0, n-1, busca));
    }

    return 0;
}