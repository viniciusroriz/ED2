#include <stdio.h>

int main() {
    int a = 0;
    int b = 0, sum = 0;

    b = scanf("%d", &a);

    while(b != EOF){
        sum += 1;
        b = scanf("%d", &a);
    }

    printf("%d\n", sum);
    return 0;
}