#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 1000000

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
    unsigned long copy;
    int i;
    int currConsecutive = 0;
    int numUniquePrimeArr[SIZE] = {0};

    genPrimes((int)(sqrt((double) SIZE)));

    for (i = 0; i < arrSize; i++){
        copy = primes[i];
        while (copy < SIZE){
            numUniquePrimeArr[copy]++;
            copy += primes[i];
        }
    }

    for (i = 647; i < SIZE; i++){
        if (numUniquePrimeArr[i] >= 4) currConsecutive++;
        else currConsecutive = 0;

        if (currConsecutive == 4){
            printf("%d\n", i-3);
            return 0;
        }
    }

    return -1;
}
