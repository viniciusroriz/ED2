#include <stdio.h>
#include <stdlib.h>

typedef int Item;
#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { Item t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

void printaVetor(int* vetor, int n){
    printf("\n%d", vetor[0]);

    for(int i=1; i < n; i++){
        printf(" %d", vetor[i]);
    }
    
    printf("\n");
}

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

int* intercala2(int* v1, int l1, int r1, int* v2, int l2, int r2){
    int t1 = (r1-l1 +1); //tamanho de 1
    int t2 = (r2-l2 +1); // tamanho de 2

    int *v3 = malloc(sizeof(int)*(t1 + t2));
    int l3 = 0;
    int r3 = (t1+t2-1);

    int i1 = l1, i2 = l2, i3 = 0;

    while(i1 <= r1 && i2 <= r2){
        if(v1[i1] <= v2[i2]){
            v3[i3++] = v1[i1++];
        }
        else 
            v3[i3++] = v2[i2++]; 
    }

    while(i1 <= r1)
        v3[i3++] = v1[i1++];
    while(i2 <= r2)
        v3[i3++] = v2[i2++];

    return v3;
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

        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;
  
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return buscaB(arr, l, mid - 1, x);
  
        // Else the element can only be present
        // in right subarray
        return buscaB(arr, mid + 1, r, x);
    }
  
    return -1;
}

int main(){
    int n, num, aux=0, tam=0, tam2=0;
    int v[100000], *soma, *v2;

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
    printf("=== vetor inicial: ");
    printaVetor(v, tam);

    // ------------- numeros malucos ordenados

    if(tam%2 != 0){
        v[tam++] = 1000000000;
    }
    
    soma = somaNum(v, tam);
    tam2 = tam/2;
    printf("=== soma: ");
    printaVetor(soma, tam2);


    // ------------- numeros malucos somados
    aux = 0;

    for(int i=0; i<tam2; i++){ // checa se num repete
        for(int j=0; j<tam; j++){
            if(soma[i] == v[j]){
                for (int k=i; k<tam2; k++) {  
                    soma[k] = soma[k+1];
                }
                tam2--;
                break;
            }
        }
    }

    v2 = intercala2(v, 0, tam-1, soma, 0, tam2-1);

    // ------------- numeros malucos somados reinseridos

    tam = tam+tam2;
    free(soma);

    int i=0;

    while(i <= tam){
        printf("%d\n", v2[i]);
        i += 4;
    }

    printf("Elementos: %d\n", tam);

    return 0;
}