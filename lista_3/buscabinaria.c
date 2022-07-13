#include <stdio.h>
#include <stdlib.h>

int buscaB(int arr[], int l, int r, int x){
    if (r >= l) {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;
  
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return buscaB(arr, l, mid - 1, x);
  
        // Else the element can only be present
        // in right subarray
        return buscaB(arr, mid + 1, r, x);
    }
  
    return l;
}

int main(){
    int n, m, busca;
    int v[100000];

    scanf("%d", &n);
    scanf("%d", &m);

    for(int i=0; i<n; i++){
        scanf("%d", &v[i]);
    }

    for(int i=0; i<m; i++){
        scanf("%d", &busca);
        printf("%d\n", buscaB(v, 0, n-1, busca));
    }

    return 0;
}