#include <stdio.h>

int main() {
    int n = 0, sum = 0, a = 0;

    scanf("%d",&n);

    for(int i=0; i < n; i++) {
        scanf("%d", &a);
        sum += a;
    }
    
    printf("%d\n", sum);
    return 0;
}