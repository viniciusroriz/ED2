#include <stdio.h>
#include <stdlib.h>

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

int* somaNum(Item *v, int n){
    Item *soma = malloc(sizeof(Item)*(n/2));
    int cont=0, i=1;
    
    while(less(cont,n/2)){
        soma[cont++] = v[i] + v[i-1];
        i += 2;
    }

    return soma;
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

int buscaB(int arr[], int l, int r, int x){
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;
  
        if (arr[mid] > x)
            return buscaB(arr, l, mid - 1, x);
  
        return buscaB(arr, mid + 1, r, x);
    }
  
    return -1;
}

int main(){
    int n, num, aux=0, tam=0, tam2=0;
    int v[100000], *soma;

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &num);

        for(int j=0; j<=i; j++){
            if(num == v[j])
                aux = 1;
        } 
        
        if(aux == 0){
            v[i] = num;
            tam++;
        }
        aux = 0;
    }

    // ------------- numeros malucos lidos

    mergesort(v,0,tam-1);

    // ------------- numeros malucos ordenados

    if(tam%2 != 0){
        v[tam++] = 1000000000;
    }
    
    soma = somaNum(v, tam);
    tam2 = tam/2;

    // ------------- numeros malucos somados

    for(int i=0; i<tam2; i++){ // checa se num repete
        if(buscaB(v, 0, tam-1, soma[i]) == -1){
            v[tam++] = soma[i];
        }
    }

    free(soma);
    insertionSort(v, tam);

    // ------------- numeros malucos somados reinseridos

    int i=0;

    while(i <= tam){
        printf("%d\n", v[i]);
        i += 4;
    }

    printf("Elementos: %d\n", tam);

    return 0;
}