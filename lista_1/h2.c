#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno {
    char nome[21];
    int acertos;
}alunos;

alunos troca(alunos reprovado, alunos novo) {
    reprovado.acertos = novo.acertos;
    strcpy(reprovado.nome, novo.nome);

    return reprovado;
}

alunos compara(alunos aluno, alunos reprovado) {
    if(aluno.acertos < reprovado.acertos) {
        reprovado = troca(reprovado, aluno);
    } else if(aluno.acertos == reprovado.acertos && strcmp(aluno.nome, reprovado.nome) > 0) {
        reprovado = troca(reprovado, aluno);
    }
    return reprovado;
}

int main() {
    int qtd_alunos, result=0, aux=0;
    alunos *reprovado;
    alunos *aluno;

    reprovado = malloc(sizeof(alunos));
    aluno = malloc(sizeof(alunos));

    while(scanf("%d", &qtd_alunos) != EOF){
        aluno = realloc(aluno, sizeof(alunos)*qtd_alunos);
        reprovado = realloc(reprovado, sizeof(alunos)*(aux+1));

        reprovado[aux].acertos = 10;

        for(int i=0; i<qtd_alunos; i++) {
            scanf("%s %d", aluno[i].nome, &aluno[i].acertos);
            reprovado[aux] = compara(aluno[i], reprovado[aux]);
        }
        
        aux++;
    }

    for(int i=1; i<=aux; i++) {
        printf("Instancia %d\n%s\n", i, reprovado[i-1].nome);
        printf("\n");
    }

    return 0;
}