#include <stdlib.h>
#include <stdio.h>

int calc(int);

int main(){
    int i;
    int sum = calc(3);
    sum += calc(5);
    printf("%d\n", sum);
    sum -= calc(15);
    printf("%d", sum);

    return 0;
}

int calc(int n){
    int largest = 999/n*n;
    int number = largest/n;
    printf("%d\n", largest);
    printf("%d\n", number);
    return (largest + n)*number/2;
}
