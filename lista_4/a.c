#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Frase{
    char c;
    int indice;
    int qnt;
}frase;

typedef frase Item;
#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))

void merge(Item *v, int l, int meio, int r){
    Item *temp = malloc(sizeof(Item)*(r-l+1));
    int i=l; // controle de progresso na primeira metade
    int j=meio+1; // controle de progresso na segunda metade
    int k=0; // controle de progresso no vetor temp

    while(lesseq(i,meio) && lesseq(j,r)){
        if(less(v[i].qnt,v[j].qnt))
            temp[k++] = v[i++];
        else if(v[i].qnt == v[j].qnt){
            if(v[i].indice > v[j].indice)
                temp[k++] = v[i++];
            else
                temp[k++] = v[j++];
        }else
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

void printaStr(char* vetor, int n){
    printf("\n");
    for(int i=0; i < n; i++)
        printf("%c", vetor[i]);
    printf("\n");
}

int main(){
    char str[100001];
    frase *conjuntos;
    int qtd_conjuntos = 1, j = 0;

    scanf("%s", str);
    int tam = strlen(str);

    for(int i=1; i<tam; i++){
        if(str[i] != str[i-1])
            qtd_conjuntos++;
    }

    conjuntos = malloc(sizeof(frase)*qtd_conjuntos);

    conjuntos[j].c = str[0];
	conjuntos[j].indice = 0;
	conjuntos[j].qnt=1;

    for(int i=1; i<tam; i++){
        if(str[i] != str[i-1]){
			j++;
			conjuntos[j].c = str[i];
			conjuntos[j].indice = i;
			conjuntos[j].qnt=1;
		}else{
			conjuntos[j].qnt++;
		}
    }

    mergesort(conjuntos, 0, qtd_conjuntos-1);

    for(int i=qtd_conjuntos-1; i>=0; i--)
		printf("%d %c %d\n", conjuntos[i].qnt, conjuntos[i].c, conjuntos[i].indice);
		
	free(conjuntos);
    
    return 0;
}