typedef int Item;

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