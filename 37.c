#include <stdio.h>
#include <string.h>

int isPrime(unsigned long n){
    unsigned int i;

    if (n < 2) return 0;
    if (n == 2) return 1;
    if (!(n % 2)) return 0;

    for (i = 3; i*i <= n; i += 2){
        if (!(n % i)) return 0;
    }

    return 1;
}

int main(){
    int i, j, rightSize = 0;
    unsigned long curr, sum = 0;
    unsigned long circPrimes[1000] = {0};
    char isTrunc, buffer[20] = {0};

    circPrimes[0] = 2;
    circPrimes[1] = 3;
    circPrimes[2] = 5;
    circPrimes[3] = 7;
    rightSize = 4;

    for (i = 0; i < rightSize; i++){
        for (j = 1; j < 10; j += 2){
            curr = circPrimes[i]*10 + j;
            if (isPrime(curr)){
                circPrimes[rightSize] = curr;
                rightSize++;
            }
        }
    }

    for (i = 0; i < rightSize; i++){
        curr = circPrimes[i];
        isTrunc = 1;
        memset(buffer, 0, 20);

        while (curr && isTrunc){
            if (!isPrime(curr)){
                isTrunc = 0;
                circPrimes[i] = 0;
            }
            sprintf(buffer, "%lu", curr);
            memmove(buffer, buffer+1, strlen(buffer));
            if(buffer[0]) sscanf(buffer, "%lu", &curr);
            else curr = 0;
            /*printf("%lu\n", curr);*/
        }
    }

    for (i = 4; i < rightSize; i++){
        if (circPrimes[i]){
            printf("%lu\n", circPrimes[i]);
            sum += circPrimes[i];
        }
    }

    printf("%lu\n", sum);

    return 0;
}
