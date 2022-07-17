#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct traducao{
    char jap[81];
	char pt[81];
}traducao;

void busca(traducao *trad, char *x, int tam){
	for(int i=0; i<tam; i++){
		if(strcmp(trad[i].jap, x) == 0){
			printf("%s ",trad[i].pt);
			return;
		}
	}
	printf("%s ",x);
    // printf("str pesquisada === %s\n", x);
    // printf("str encontrada === %s\n", trad[0].jap);
    // printf("strcmp(x, trad[0].jap) === %d\n", strcmp(x, trad[0].jap));
}

char *zera(){
    char *novo;
    novo = malloc(81 * sizeof(char));
    return novo;
}

int main(void){
    int t; // num de instancias
    int m; // qtd palavras no dicionario
    int n; // num de linhas na letra da musica
    int j=0, cont=0;
    char letra[81];
	char *buffer = zera();
    traducao *trd;

    scanf("%d", &t);

    for(int i=0; i<t; i++){
        scanf("%d %d", &m, &n);
        trd = malloc(sizeof(traducao)*m);

        for(int l=0; l<m; l++){
            scanf(" %s", trd[l].jap);
            scanf(" %[^\n]s", trd[l].pt);
        }
        
        for(int l=0; l<n; l++){
            scanf(" %[^\n]", letra);
                
            for(int k=0; k<=strlen(letra); k++){
                if(letra[k]==' ' || k == strlen(letra)){
                    busca(trd, buffer, m);
                    buffer = zera();
                    j=0;
                }else
                    buffer[j++] = letra[k];
            }
            printf("\n");
        }

        j=0;
        buffer = zera();
        free(trd);
    }

	return 0;
}
