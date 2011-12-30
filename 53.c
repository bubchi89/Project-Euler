#include <stdio.h>
#include <math.h>

int primes[100] = {0};
int SIZE = 0;

void genPrimes(){
    int i, j;
    char isPrime;

    primes[0] = 2;
    SIZE = 1;

    for (i = 3; i < 100; i += 2){
        isPrime = 1;
        for (j = 0; primes[j]*primes[j] <= i; j++){
            if (!(i % primes[j])){ 
                isPrime = 0; 
                break;
            }
        }
        
        if (isPrime){
            primes[SIZE] = i;
            SIZE++;
        }
    }
}

void factorize(int arr[100], int n){
    int i = 0;
    int curr;
        
    for (; n > 1; n--){
        curr = n;
        i = 0;
        while (curr > 1){
            while (!(curr % primes[i])){
                curr /= primes[i];
                arr[i]++; 
            }

            i++;
        }
    }
}

unsigned long choose(int n, int r){
    int topArr[100] = {0}; 
    int nrArr[100] = {0};
    int rArr[100] = {0};
    int combinations[100] = {0};
    unsigned long ret = 1;
    int i;

    factorize(topArr, n);
    factorize(nrArr, n-r);
    factorize(rArr, r);

    for (i = 0; i < SIZE; i++){
        combinations[i] = topArr[i] - nrArr[i] - rArr[i]; 
    }

    for (i = 0; i < SIZE; i++)
        ret *= (unsigned long) pow((long double) primes[i], combinations[i]);

    return ret;

}

int main(){
    int n, r;
    int curr, total = 0, limit;

    genPrimes();

    for (n = 23; n <= 100; n++){
        curr = 0;
        if (!(n % 2)) curr = 1;

        limit = (n-1)>>1;
        for (r = 2; r <= limit; r++){
            if (choose(n, r) > 1000000){
                curr += ((limit-r+1)<<1);
                break;
            }
        }

        total += curr;
    }

    printf("%d\n", total);

    return 0; 
}
