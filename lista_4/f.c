#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct{
  int codigo;
  int qualidade;
}semente;

int less(Item *a, Item *b){
  if(*a<*b) return 1;
  else return 0;
}

int lesseq(Item *a, Item *b){
  if(*a<=*b) return 1;
  else return 0;
}

void exch(semente *a,int l, int r){
  semente temp;
  temp = a[r];
  a[r] = a[l];
  a[l] = temp;
}

static int separa(semente *v, int l, int r){ //função static equilave a private em relação a OO
  Item *c = malloc(2*sizeof(Item));
  c[0] = v[r].qualidade; // 1,
  c[1] = v[r].codigo; // 1,
  semente temp;
  Item j=l ; // 0
  for(int i=l; i <r ; i++){
    if(lesseq(&v[i].qualidade,&c[0])){
      if(v[i].qualidade==c[0]){
        if(v[i].codigo<c[1]){
          exch(v,i,j);
          j++;
        }
      }else{
        exch(v,i,j);
        j++;
      }
    }
  }
  free(c);
  exch(v,r,j);
  return j;
}
void eec(int i, semente *v, int l, int r){

  if(less(&v[l].codigo,&v[r].codigo)){
    exch(v,r,l);
  }
  if(less(&v[(r+l)/2].codigo,&v[l].codigo)){
    exch(v,((r+l)/2),l);
  }
  if(less(&v[r].codigo,&v[l].codigo)){
    exch(v,l,r);
  }
  Item j = separa(v,l,r);
  if(j==i) return;
  if(j<i) {
    eec(i,v,j+1,r);
  }else{
    eec(i,v,l,j-1);
  }
}
static void mergeAB(int p, int q, int r, semente *v){
  semente *w;
  w = malloc ((r-p) * sizeof (semente));
  int i = p, j = q;
  int k = 0;

  while (i < q && j < r) {
    if (v[i].codigo <= v[j].codigo)  {
      w[k]= v[i];
      i++; k++;
    }else  {
      w[k] = v[j];
      j++; k++;
    }
  }
  while (i < q)  {
    w[k] = v[i];
    i++; k++;
  }
  while (j < r)  {
    w[k] = v[j];
    j++; k++;

  }
  for (i = p; i < r; ++i)  {
    v[i]= w[i-p];
  }
  free (w);
}
void mergesort (int p, int r, semente *v){
   if (p < r-1) {                 // 1
      int q = (p + r)/2;          // 2
      mergesort (p, q, v);        // 3
      mergesort (q, r, v);        // 4
      mergeAB (p, q, r, v);     // 5
   }
}
int main(int argc, char const *argv[]) {
  semente *s = malloc(sizeof(semente));
  int qtd, i = 0;
  scanf("%d",&qtd );
  while(scanf("%d%d",&s[i].codigo, &s[i].qualidade)==2){
    i++;
    s = realloc (s, (i+1)*sizeof(semente) );
  }

  eec(qtd, s, 0 , i-1);
  mergesort(0,qtd,s);
  for(int j =0 ; j< qtd ; j++){
    printf("%d %d\n",s[j].codigo,s[j].qualidade);
  }
  free(s);
  return 0;
}