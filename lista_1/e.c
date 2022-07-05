#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Pilha {
    char *dado;
    struct Pilha *prox;
}pilha;

pilha *criapilha() {
    pilha *p = malloc(sizeof(pilha));
    p->prox = NULL;
    return p;
}

void push(char *dado, pilha *kbc) {
    pilha *novo = malloc(sizeof(pilha));
    novo->dado = dado;
    novo->prox = kbc->prox;
    kbc->prox = novo;
}

char* pop(pilha *kbc) {
    if (kbc->prox == NULL ) {
        return NULL;
    }

    pilha *topo = kbc->prox;
    char *salve = topo->dado;
    kbc->prox = topo->prox;
    
    free(topo);

    return salve; 
}

int main(void) {
    char *data;
    char *comando;
    char *destino;

    pilha *pilja = criapilha();

    comando = malloc(sizeof(char)*10);
    data = malloc(sizeof(char)*101);

    while(scanf("%s%[^\n]%*c", comando, data) != EOF) {
        if (strcmp("inserir", comando) == 0) {
            push(data, pilja);
        } else {
            char *retorno = pop(pilja);
            if (retorno != NULL){
                printf("%s\n", retorno);
                free(retorno);
            } else {
                printf("NULL\n");
            }
        }
        data = malloc(sizeof(char)*101);
    }

    return 0;
}

