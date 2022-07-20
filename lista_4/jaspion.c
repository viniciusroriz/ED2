#include <stdio.h>
#include <string.h>

#define Key(A) (A.jpn)
#define less(A, B) (strcmp(Key(A), Key(B)) < 0)
#define exch(A,B) { Item t; t = A; A = B; B = t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

// selection sort eh o melhor para ordenar lista encadeaca

typedef struct Item {   
    char jpn[81];
    char ptbr[81];
}Item;

Item dicionario[1000000];

int separa(Item *V, int l, int r)
{
  int i = l-1, j = r; Item v = V[r];
  
  for(;;)
  {
    while(less(V[++i], v));

    while(less(v, V[--j])) 
        if(j==l) 
            break;
    
    if(i>=j) 
        break;
    
    exch(V[i],V[j]);
  }
  
  exch(V[i],V[r])
  
  return i;
}

void quicksortM3(Item *V,int l, int r)
{
    if (r<=l) return;

    cmpexch(V[(l+r)/2],V[r]);
    cmpexch(V[l],V[(l+r)/2]);
    cmpexch(V[r],V[(l+r)/2]);

    int j = separa(V, l, r);
    
    quicksortM3(V, l, j-1);
    quicksortM3(V, j+1, r);
}

int buscabinaria(Item *dicionario, int l, int r, char *b) 
{ 
   while (l <= r) 
   {
    int meio =  l + (r - l) / 2;

    if(strcmp(dicionario[meio].jpn, b) == 0)
    {
        return meio;
    }
    if(strcmp(dicionario[meio].jpn, b) < 0)
        l = meio + 1;
    else
        r = meio - 1;
   }
   
   return -1;
}

void traduz()
{
    int M, N;
    scanf("%d %d", &M, &N);

    for (int i = 0; i < M; i++)
    {
        scanf(" %[^\n]", dicionario[i].jpn);
        scanf(" %[^\n]", dicionario[i].ptbr);
    }
    
   quicksortM3(dicionario, 0, M -1);

   for (int i = 0; i < N; i++)
   {
        char b[81], p;
        while (scanf(" %s%c", b, &p) == 2)
        {
            int j = buscabinaria(dicionario, 0, M - 1, b);

            if (j < 0)
                printf("%s ", b);
            else    
                printf("%s", dicionario[j].ptbr);

            printf("%c", p);

            if (p == '\n')
            { 
                break;
            }
        }
   }
}

int main(void)
{
    int T;

    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        traduz();
        printf("\n");
    }
}