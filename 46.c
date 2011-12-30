#include <stdio.h>

int SIZE = 0;
unsigned long primes[1000000] = {0};

int isPrime(unsigned long n){
    unsigned int i;

    for (i = 0; primes[i]*primes[i] <= n; i++){
        if (!(n % primes[i])) return 0;
    }

    return 1;
}

int main(){
    char found;
    int i, j;
    unsigned long n, sum;

    primes[0] = 2;
    SIZE++;

    n = 3;

    while (1){
        if (!isPrime(n)){
            found = 0;
            for (i = 0; i < SIZE; i++){
                j = 1;
                while ((sum = (primes[i] + ((j*j)<<1))) <= n){
                    if (sum == n){
                        found = 1;
                        break;
                    }

                    j++;
                }
            }

            if (!found){
                printf("%lu\n", n);
                return 0;
            }
        }

        else{
            primes[SIZE] = n;
            SIZE++;
        }

        n += 2;
    }

    return -1;
}
