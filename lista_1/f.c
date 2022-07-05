#include <stdio.h>

int contaSete(long int num, int aux) {
    long int digito = num%10;
    long int resto = num/10;

    if(digito == 7) {
        aux += 1;
    }

    if(resto < 10) {
        if(resto==7)
            aux += 1;
        return aux;
    } else {
        return contaSete(resto, aux);
    }
}

int main() {
    long int num; 
    int aux=0;
    scanf("%ld", &num);

    aux = contaSete(num, aux);
    printf("%d\n", aux);
    
    return 0;
}