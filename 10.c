#include <stdio.h>
#include <math.h>

int isPrime(int n){
    int i = 3;
    while (i <= sqrt((double) n)){
        if (n % i == 0) return 0;
        i += 2;
    }
    
    return 1;
}

int main(){
    long sum;
    int i;

    sum = 5;

    for (i = 5; i < 2000000; i += 6){
        if (isPrime(i)){
            sum += i;
    /*        printf("%d\n", i);*/
        }
        if (isPrime(i+2)){
            sum += (i+2);
            /*printf("%d\n", (i+2));*/
        }
    }
    
    printf("%lu", sum);

    return 0;
}
