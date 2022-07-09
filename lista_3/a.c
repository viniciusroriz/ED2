#include <stdio.h>
#include <stdlib.h>

static void intercala2 (int p, int q, int r, int* v){
    int i, j, *w;
    w = malloc((r-p) * sizeof(int));

    for (i = p; i < q; ++i) w[i-p] = v[i];
    for (j = q; j < r; ++j) w[r-p+q-j-1] = v[j];
   
    i = 0; 
    j = r-p-1;

    for (int k = p; k < r; ++k){
        if (w[i] <= w[j]) 
            v[k] = w[i++];
        else 
            v[k] = w[j--];
    }
    free (w);
}

void mergesort(int p, int r, int* v){
    if (p < r-1) {               
        int q = (p + r)/2;          
        mergesort(p, q, v);        
        mergesort(q, r, v);        
        intercala2(p, q, r, v);     
    }
}

void printaVetor(int* vetor, int n){
    printf("\n%d", vetor[0]);

    for(int i=1; i < n; i++){
        printf(" %d", vetor[i]);
    }
    
    printf("\n");
}

int main(){
    int n1, n2;
    int v1[200000];
    
    //for(int i=0; i<4; i++){
        scanf("%d", &n1); // tamanho do vetor 1
        
        for(int j=0; j < n1; j++){ // le n1 numeros
            scanf("%d", &v1[j]);
        }

        scanf("%d", &n2); // tamanho do vetor 2
        
        for(int j=n1; j < n2+n1; j++){ // le n2 numeros
            scanf("%d", &v1[j]);
        }

        intercala2(0, n1, n2+n1, v1);

    //}

    printaVetor(v1, n1+n2);

    return 0;
}