#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
    int valor;
    struct pilha *prox;
}pilha;

pilha *criaPilha() {
    pilha *p = malloc(sizeof(pilha));
    p->prox = NULL;

    return p;
}

void push(int valor, pilha *kbc) {
    pilha *novo = malloc(sizeof(pilha));
    novo->valor = valor;
    novo->prox = kbc->prox;
    kbc->prox = novo;
}

int pop(pilha *kbc) {
   
    pilha *topo = kbc->prox;
    int salve = topo->valor;
    kbc->prox = topo->prox;
    
    free(topo);

    return salve;
}

int main() {
    int *vetor;
    int num, n=2, i=0, sum=0, qtd=0, limit;
    
    vetor = malloc(sizeof(int));
    
    scanf("%d", &num);

    while(num != 0) {
        vetor[i++] = num;
        vetor = realloc(vetor, sizeof(int)*n++);
        scanf("%d", &num);
    }

    scanf("%d", &limit);

    pilha *p = criaPilha();

    for(int j=0; j<i; j++) {
        if((vetor[j]+sum) > limit) {
            push(vetor[j], p);
            qtd++;
            sum = 0;
        } else {
            sum += vetor[j];
        }
    }

    for(int j=0; j<qtd; j++) {
        printf("%d\n", pop(p));
    }
    
    return 0;
}