typedef int Item;
#define exch(A,B) { Item t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (B < A) exch(A,B); }

int separa(Item *v, int l, int r){
    Item c = v[r];
    int j = l;

    for (int k = l; k < r; k++){
        if(v[k] < c){
            exch(v[j], v[k]);
            j++;
        }
    }

    exch(v[j], v[r]);

    return j;
}

static void quicksortM3(Item *V,int l, int r){
    if (r-l<=32) return;

    exch(V[(l+r)/2],V[r-1]);
    cmpexch(V[l],V[r-1]);
    cmpexch(V[l],V[r]);
    cmpexch(V[r-1],V[r]);


    int j=separa(V,l+1,r-1);
    quicksortM3(V,l,j-1);
    quicksortM3(V,j+1,r);
}

static void insertionsort(Item *v, int l, int r){
    Item key;
    int j;

    for(int i=l+1; i<=r; i++){
        key = v[i];
        j = i-1;
        
        while(j >= 0 && v[j] > key){
            v[j+1] = v[j];
            j = j-1;
        }
        v[j + 1] = key;   
    }
} 

void quicksortM3insertion(Item *V,int l,int r){
    quicksortM3(V,l,r);
    insertionsort(V,l,r);
}