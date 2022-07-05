#include <stdio.h>
#include <stdlib.h>

int checaNaoRepete(int valor, int *vetor, int n) {
    for(int j=0; j<n; j++) {
        if(valor == vetor[j]) {
            return 0;
        } 
    }

    return 1;
}

int main () {
    int n=0, valor=0, presentes=0, capacidade=2;
    int *vetor = malloc(sizeof(int)*capacidade);

    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        if(presentes == capacidade) {
            capacidade *= 2;
            vetor = realloc(vetor, sizeof(int)*capacidade);
        }

        scanf("%d", &valor);

        if(checaNaoRepete(valor, vetor, presentes)) {
            vetor[presentes] = valor;
            presentes++;
        }
    }
    printf("%d\n", presentes);

    return 0;
}