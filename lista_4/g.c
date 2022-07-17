#include <stdio.h>
#include <stdlib.h>

typedef int Item;
#define exch(A,B) { Item t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (B < A) exch(A,B); }

void printaVetor(int* vetor, int n){
    printf("\n%d", vetor[0]);

    for(int i=1; i < n; i++){
        printf(" %d", vetor[i]);
    }
    
    printf("\n");
}

int separa(Item *v, int l, int r){
    Item c = v[r];
    int j = l;

    for (int k = l; k < r; k++){
        if(v[k] < c){
            exch(v[j], v[k]);
            j++;
        }
    }

    exch(v[j], v[r]);

    return j;
}

void quickSelect(int *v, int l, int r, int x){
    int j = separa(v, l, r);

    if (j == x)
        return;
    if (j < x)
        quickSelect(v, j+1, r, x);
    else
        quickSelect(v, l, j-1, x);
}

static void quicksortM3(Item *V,int l, int r){
    if (r-l<=32) return;

    exch(V[(l+r)/2],V[r-1]);
    cmpexch(V[l],V[r-1]);
    cmpexch(V[l],V[r]);
    cmpexch(V[r-1],V[r]);


    int j=separa(V,l+1,r-1);
    quicksortM3(V,l,j-1);
    quicksortM3(V,j+1,r);
}

static void insertionsort(Item *v, int l, int r){
    Item key;
    int j;

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

void quicksortm3insertion(Item *V,int l,int r){
    quicksortM3(V,l,r);
    insertionsort(V,l,r);
}

int main(void){
    int x, n, p, inicio, fim, aux=0;

    scanf("%d", &n); // qtd produtos
    scanf("%d", &p); // pag apresentada 
    scanf("%d", &x); // qtd por pagina

    inicio = p*x; 
    fim = inicio + x;

    if(fim > (n-1)){
        fim = n-1;
        aux = 1;
    }

    Item *itens = malloc(sizeof(Item)*n);

    for(int i=0; i<n; i++){
        scanf("%d", &itens[i]);
    }

    quickSelect(itens, 0, n-1, inicio);
    quickSelect(itens, inicio+1, n-1, fim);
    quicksortm3insertion(itens, inicio, fim);

    for(int i=inicio; i<fim+aux; i++){
        printf("%d\n", itens[i]);
    }

    free(itens);
    return 0;
}