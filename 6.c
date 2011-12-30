#include <stdio.h>

int main(){
    long sum = 0, i, j;

    for (i = 100; i > 0; i--){
        for (j = i-1; j > 0; j--){
            sum += i*j;
        }
    }

    sum <<= 1;

    printf("%lu", sum);

    return 0;
}
