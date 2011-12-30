#include <stdio.h>
#include <stdlib.h>

int primes[1000] = {0};
int size = 0;

void genPrimes(){
    int n, i;
    char stillPrime;

    primes[0] = 2;
    size++;

    for (n = 3; n < 1000; n += 2){
        stillPrime = 1;
        for (i = 0; primes[i]*primes[i] < n && stillPrime; i++){
            if (!(n % primes[i])) stillPrime = 0;
        }
        if (stillPrime){
            primes[size] = n;
            size++;
        }
    }
}    

int intComp(const void *key, const void *curr){
    return (*(int *)key - *(int *)curr);
}

int isPrime(long int n){
    int i;

    if (n < 1) return 0;

    if (n <= 1000) 
        return bsearch(&n, primes, size, sizeof(int), intComp) != NULL;
    
    for (i = 0; primes[i]*primes[i] <= n; i++){
        if (!(n % primes[i])) return 0;
    }

    return 1;
}

int isPrime1(long int n){
    int i;

    if (n < 2) return 0;
    if (n == 2 ) reutrn 1;
    if (!(n % 2)) return 0;

    for (i = 3; i*i <= n; i += 2){
        if (!(n % i)) return 0;
    }

    return 1;
}

int calcConsecutive(int b, int a){
    int n, count = 0;
    long funcOut;

    for (n = 0; n < b; n++){
        funcOut = (n*n + n*a + b);
        if (funcOut > 1000000){
            printf("Too Big, b = %d, a = %d, n = %d, "
                    "funcOut = %lu.\n", b, a, n, funcOut);
            return -1;
        }
        if (isPrime(funcOut)) count++;
        else return count;
    }

    return count;
}

int main(){
    int b, a, maxConsecutive = 0, currConsecutive, currB = 41, currA = 1, i;

    b = 43;

    genPrimes();

    i = ((int *)bsearch(&b, primes, size, sizeof(int), intComp) - primes);

    for (; i < size; i++){
        b = primes[i];
        for (a = -b + 2; a < 999; a +=2){
            currConsecutive = calcConsecutive(b, a);
            if (currConsecutive > maxConsecutive){
                maxConsecutive = currConsecutive;
                currB = b;
                currA = a;
            }
        }
    }

    printf("b: %d, a: %d, consecutive: %d, b*a: %d\n", currB, currA, 
            maxConsecutive, currB*currA);
        
    return 0;
}
