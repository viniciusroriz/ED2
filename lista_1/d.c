#include <stdio.h>

int main() {
    int perguntas = 0, qtd_triagens = 0;
    int b = 0, sum = 0;

    char resposta[3];

    b = scanf("%s", resposta);
    
    if(*resposta == 's'){
        sum += 1;
    }

    while(b != EOF){
        perguntas += 1;

        if (perguntas == 10){
            if(sum >= 2){
                qtd_triagens += 1;
            }
            sum = 0;
            perguntas = 0;
        }
            
        b = scanf("%s", resposta);

        if(*resposta == 's'){
            sum += 1;
        }
    }

    printf("%d\n", qtd_triagens);
    return 0;
}