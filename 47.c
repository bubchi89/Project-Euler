#include <stdio.h>
#include <stdlib.h>

#define SIZE 10000000

int primes[100000] = {0};
int arrSize = 0;

void genPrimes(int maxSize){
    int n, i;
    char isPrime;

    primes[0] = 2;
    arrSize++;
    
    for (n = 3; arrSize < maxSize; n += 2){
        isPrime = 1;

        for (i = 0; primes[i]*primes[i] <= n && isPrime; i++){
            if (!(n % primes[i])) isPrime = 0;
        }

        if(isPrime){
            primes[arrSize] = n;
            arrSize++;
        }
    }
}

int comparator(const void* n1, const void* n2){
    int num1 = *((int*) n1);
    int num2 = *((int*) n2);

    return num1-num2;
}

int isPrime(unsigned long n){
    return (bsearch(&n, primes, arrSize, sizeof(int), comparator) != NULL);
}

int main(){
    unsigned long n, copy;
    int currConsecutive = 0, i;
    int numUniquePrimeArr[SIZE] = {0}, numUniquePrime;

    genPrimes(100000);

    n = 647;

    while (1){
        if (isPrime(n)){
            currConsecutive = 0;
            n++;
            continue;
        }

        copy = n;
        i = 0;
        numUniquePrime = 0;
        while (copy > 1){
            if (!(copy % primes[i])) numUniquePrime++;
            while (!(copy % primes[i])) copy /= primes[i]; 

            i++;
        }

        numUniquePrimeArr[n] = numUniquePrime;
        
        if (numUniquePrime >= 4) currConsecutive++;
        else currConsecutive = 0;

        if (currConsecutive == 4){
            printf("%lu\n", n - 3);
            return 0;
        }

        n++;
    }

    return -1;
}
