#include <stdio.h>

int isPrime(long);

int main(){
    long curr = (600851475143/3 % 2 == 0) ? 600851475143/3 - 1:600851475143/3;
    
    while (curr > 2){
        if (!(600851475143 % curr) && isPrime(curr)){
            printf("%lu", curr);
            return 0;
        }
        curr -= 2;
    }

    return 1;
}

int isPrime(long num){
    int i = 2;

    while (i <= num/2){
        if (!(num % i)) return 1;
        i++;
    }

    return 0;
}
