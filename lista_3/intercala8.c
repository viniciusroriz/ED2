#include <stdio.h>
#include <stdlib.h>

int* intercala2(int* v1, int l1, int r1, int* v2, int l2, int r2){
    int t1 = (r1-l1 +1); //tamanho de 1
    int t2 = (r2-l2 +1); // tamanho de 2

    int *v3 = malloc(sizeof(int)*(t1 + t2));
    int l3 = 0;
    int r3 = (t1+t2-1);

    int i1 = l1, i2 = l2, i3 = 0;

    while(i1 <= r1 && i2 <= r2){
        if(v1[i1] <= v2[i2]){
            v3[i3++] = v1[i1++];
        }
        else 
            v3[i3++] = v2[i2++]; 
    }

    while(i1 <= r1)
        v3[i3++] = v1[i1++];
    while(i2 <= r2)
        v3[i3++] = v2[i2++];

    free(v1);
    free(v2);
    
    return v3;
}

int* intercala4(int* v1, int l1, int r1, int* v2, int l2, int r2, 
int* v3, int l3, int r3, int* v4, int l4, int r4){
    
    int *v_aux1, *v_aux2;
    int t1 = r1 + r2 + 1; 
    int t2 = r3 + r4 + 1;

    v_aux1 = intercala2(v1, l1, r1, v2, l2, r2);
    v_aux2 = intercala2(v3, l3, r3, v4, l4, r4);

    return intercala2(v_aux1, l1, t1, v_aux2, l3, t2);

}

int* intercala8(int* v1, int l1, int r1, int* v2, int l2, int r2, 
int* v3, int l3, int r3, int* v4, int l4, int r4, 
int* v5, int l5, int r5, int* v6, int l6, int r6, 
int* v7, int l7, int r7, int* v8, int l8, int r8){

    int *v_aux1, *v_aux2;
    int t1 = r1 + r2 + r3 + r4 + 3;
    int t2 = r5 + r6 + r7 + r8 + 3; 

    v_aux1 = intercala4(v1, l1, r1, v2, l2, r2, v3, l3, r3, v4, l4, r4);
    v_aux2 = intercala4(v5, l5, r5, v6, l6, r6, v7, l7, r7, v8, l8, r8);

    return intercala2(v_aux1, l1, t1, v_aux2, l5, t2);
}

void printaVetor(int* vetor, int n){
    printf("\n%d", vetor[0]);

    for(int i=1; i < n; i++){
        printf(" %d", vetor[i]);
    }
    
    printf("\n");
}

int main(){
    int n1, n2, n3, n4, n5, n6, n7, n8;
    int v1[100000], v2[100000], v3[100000], v4[100000], v5[100000], v6[100000], v7[100000], v8[100000];
    int *v;
    
    scanf("%d", &n1); // tamanho do vetor 1
    
    for(int j=0; j < n1; j++){ 
        scanf("%d", &v1[j]);
    }

    scanf("%d", &n2); // tamanho do vetor 2
    
    for(int j=0; j < n2; j++){ 
        scanf("%d", &v2[j]);
    }

    scanf("%d", &n3); // tamanho do vetor 3
    
    for(int j=0; j < n3; j++){ 
        scanf("%d", &v3[j]);
    }

    scanf("%d", &n4); // tamanho do vetor 4
    
    for(int j=0; j < n4; j++){ 
        scanf("%d", &v4[j]);
    }

    scanf("%d", &n5); // tamanho do vetor 5
    
    for(int j=0; j < n5; j++){ 
        scanf("%d", &v5[j]);
    }

    scanf("%d", &n6); // tamanho do vetor 6
    
    for(int j=0; j < n6; j++){ 
        scanf("%d", &v6[j]);
    }

    scanf("%d", &n7); // tamanho do vetor 7
    
    for(int j=0; j < n7; j++){ 
        scanf("%d", &v7[j]);
    }

    scanf("%d", &n8); // tamanho do vetor 8
    
    for(int j=0; j < n8; j++){ 
        scanf("%d", &v8[j]);
    }

    v = intercala8( v1, 0, n1-1, v2, 0, n2-1, v3, 0, n3-1, v4, 0, n4-1, v5, 0, n5-1, v6, 0, n6-1, v7, 0, n7-1, v8, 0, n8-1);
    
    //v = intercala4( v1, 0, n1-1, v2, 0, n2-1, v3, 0, n3-1, v4, 0, n4-1);
    //v = intercala2(v1, 0, n1-1, v2, 0, n2-1);
    //printaVetor(v, n1+n2+n3+n4);

    printaVetor(v, n8+n7+n6+n5+n4+n3+n2+n1);

    return 0;
}