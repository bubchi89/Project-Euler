#include <stdio.h>
long arr[10000];

int isPrime(long n){
    int i = 0;

    while (arr[i] < n/2){
        if (n % arr[i] == 0) return 0;
        i++; 
    }
    
    return 1;
}

int main(){
    int i;
    long j;

    arr[0] = 2;
    arr[1] = 3;

    for (i = 2; i < 10001; i++){
        for (j = arr[i-1] + 2; !arr[i]; j += 2){
            if (isPrime(j)) arr[i] = j; 
        }
    }

    printf("%lu", arr[10000]);
    
    return 0;
}
