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

void quickSelect(int *v, int l, int r, int x){
    int j = separa(v, l, r);

    if (j == x)
        return;
    if (j < x)
        quickSelect(v, j + 1, r, x);
    else
        quickSelect(v, l, j - 1, x);
}