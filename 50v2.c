#include <stdio.h>

char primes2[1000000] = {0};

int primes[100000] = {0};
int numPrimes = 0;

void genPrimes(){
    int i, curr;
    char isPrime;

    primes2[2] = 1;

    for (i = 3; i < 1000000; i+=2) primes2[i] = 1;

    i = 3;
    while (i*i <= 1000000){
        for (curr = (i << 1); curr < 1000000; curr += i){
            primes2[curr] = 0; 
        }

        do i+= 2;
        while (!primes2[i]);
    }

    primes[0] = 2; primes[1] = 3;
    numPrimes = 2;

    for (curr = 5; primes[numPrimes-1] + curr < 1000000; curr += 2){
        isPrime = 1;
        for (i = 0; primes[i]*primes[i] <= curr; i++){
            if (!(curr % primes[i])){
                isPrime = 0;
                break;
            }
        }

        if (isPrime){
            primes[numPrimes] = curr;
            numPrimes++;
        }
    }

    
}

int main(){
    int currConsecutive;
    int i, beg, end;
    unsigned long sum;

    genPrimes();

    for (currConsecutive = numPrimes; currConsecutive > 6; currConsecutive--){
        beg = 0;
        sum = 0;
        for (i = 0; i < currConsecutive; i++) sum += primes[i];

        if (sum < 1000000 && primes2[sum]){
            printf("%lu\n", sum);
            return 0;
        }

        beg++;

        while (primes[beg + currConsecutive - 1]){
            end = beg + currConsecutive - 1;

            sum -= primes[beg - 1];
            sum += primes[end];

            if (sum < 1000000 && primes2[sum]){
                printf("%lu\n", sum);
                return 0;
            }

            beg++;
        }
    }

    return 0;
}
