#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    int n;
    char palavra[100];

    scanf("%d", &n);

    int *qtdLetras;
    qtdLetras = malloc(sizeof(int)*n);

    for(int i=0; i < n; i++) {
        scanf("%s", palavra);
        for(int j=0; j < strlen(palavra); j++) {
            if(isdigit(palavra[j])) {
                qtdLetras[i] += ((int)palavra[j] - 48);
            }
        }
    }

    for(int i=0; i < n; i++) {
        printf("%d\n", qtdLetras[i]);
    }

    return 0;
}