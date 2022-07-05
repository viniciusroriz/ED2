#include <stdio.h>
#include <stdlib.h>

typedef struct Dict{
    int code;
    char* key;
}dict;

void swap(dict* xp, dict* yp){
    dict temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(dict* v, int n){
    int menor;
    
    for(int i=0; i<n-1; i++){
        menor = i;
        for(int j=i+1; j<n; j++){
            if(v[j].code < v[menor].code)
                menor = j;
        }
        swap(&v[menor], &v[i]);
    }
}

int buscaInstrucoes(dict* cod, int x, int l, int r){
    if(r >= l){
        int mid = l + (r-l)/2;
        
        if(cod[mid].code == x)
            return mid;
        
        if(cod[mid].code > x)
            return buscaInstrucoes(cod, x, l, mid-1);
        
        return buscaInstrucoes(cod, x, mid+1, r);
    }

    return -1;
}

void printDictArray(dict *v, int size){
    int i;

    for (i=0; i < size; i++)
        printf("%d %s\n", v[i].code, v[i].key);
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
    int tamanho = 0, limite = 50, n, indice=0;
    int* vetor = malloc(sizeof(int)*limite);

    scanf("%d", &n);
    dict* cmd = malloc(sizeof(dict)*n);
   
    for(int i=0; i<n; i++){
        cmd[i].key = malloc(sizeof(char)*15);
        scanf("%d %s", &cmd[i].code, cmd[i].key);
    }

    while(scanf("%d", &vetor[tamanho]) != EOF){
        if(++tamanho == limite){
            limite *= 2;
            vetor = realloc(vetor, sizeof(int)*limite);
        }
    }
    
    selectionSort(cmd, n);
    
    for(int i=0; i<tamanho; i++){
        indice = buscaInstrucoes(cmd, vetor[i], 0, n-1);
        if(indice == -1)
            printf("undefined\n");
        else
            printf("%s\n", cmd[indice].key);
    }
    
    return 0;
}