#include <stdio.h>
#include <string.h>
#include <math.h>

char primes[1000000] = {0};
int numDigits;

void genPrimes(){
    int i, currPrime = 3;

    primes[2] = 1;

    for (i = 1; i < 1000000; i += 2) primes[i] = 1;

    while (currPrime*currPrime <= 1000000){
        for (i = currPrime*2; i < 1000000; i += currPrime)
            primes[i] = 0;

        i = currPrime + 2;
        while (!primes[i]) i += 2;
        
        currPrime = i;
    }
        
}

int rotate(char *rotatedArr){
    int rotated;
    char firstDigit = rotatedArr[0];
    memmove(rotatedArr, rotatedArr + 1, 19);
    rotatedArr[strlen(rotatedArr)] = firstDigit;

    sscanf(rotatedArr, "%d", &rotated);
    
    return rotated;

}

int main(){
    int i, orig, rotated, numCircPrimes = 11;
    char rotatedArr[20] = {0};
    char isValid;

    genPrimes();

    for (i = 97; i < 1000000; i += 2){
        if (primes[i] != 1) continue;
        orig = i;
        isValid = 1;        
        sprintf(rotatedArr, "%d", orig);
        rotated = rotate(rotatedArr);

        while (rotated != orig && isValid){
            if (!primes[rotated]) isValid = 0;
            else primes[rotated]++;

            rotated = rotate(rotatedArr);
        }

        if (isValid){
/*            printf("%d\n", i);*/
            numCircPrimes += strlen(rotatedArr);
        }
    }

    printf("%d\n", numCircPrimes);

    return 0;
}
