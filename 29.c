#include <stdio.h>
#include <string.h>

short primes[30] = {0};
short primesSize = 0;

void genPrimes(){
    int i, n;
    char stillPrime;

    primes[0] = 2;
    primesSize = 1;

    for (n = 3; n < 100; n += 2){
        stillPrime = 1;
        for (i = 0; i < primesSize && stillPrime; i++){
            if (!(n % primes[i])) stillPrime = 0;
        }

        if (stillPrime){
            primes[primesSize] = n;
            primesSize++;
        }
    }
}

int isDuplicate(short curr[30], short arr[10000][30], int arrSize){
    int r, c, match;

    for (r = 0; r < arrSize; r++){
        match = 1;
        for (c = 0; c < 30 && match; c++){
            if (curr[c] != arr[r][c]) match = 0;
        }
        if (match) return 1;
    }

    return 0;
}

void factorize(int a, short pFactors[30]){
    int i;

    for (i = 0; i < primesSize; i++){
        while (!(a % primes[i])){
            a /= primes[i];
            pFactors[i]++;
        }
    }
}

int main(){
    int i, numUnique = 0, b, a;
    short uniqueNum[10000][30] = {{0}};
    short basePrimeFactor[30] = {0}, curr[30] = {0};

    genPrimes();

    for (a = 2; a <= 100; a++){
        memset(basePrimeFactor, 0, sizeof(short)*30); 
        factorize(a, basePrimeFactor);

        for (b = 2; b <= 100; b++){
            for (i = 0; i < 30; i++){
                curr[i] = basePrimeFactor[i]*b;
            }
            if (!isDuplicate(curr, uniqueNum, numUnique)){
                memcpy(uniqueNum[numUnique], curr, sizeof(short)*30);
                numUnique++;
            }
        }
    }

    printf("%d\n", numUnique);

    return 0;
}
