#include <stdio.h>
#include <string.h>

char isPrimeArr[1000000] = {0};

int primes[1000000] = {0};
int numPrimes = 0;
int family[10] = {0};

void genPrimes(){
    int i, curr;
    char isPrime;

    isPrimeArr[2] = 1;

    for (i = 3; i < 1000000; i+=2) isPrimeArr[i] = 1;

    i = 3;
    while (i*i <= 1000000){
        for (curr = (i << 1); curr < 1000000; curr += i){
            isPrimeArr[curr] = 0; 
        }

        do i+= 2;
        while (!isPrimeArr[i]);
    }

    primes[0] = 2; primes[1] = 3;
    numPrimes = 2;

    for (curr = 5; curr < 1000000; curr += 2){
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

int calcFamily(char buffer[20], int indicesArr[10], int numDigits){
    int i, j, size = 0;
    int currNum;
    char copy[20];
    
    memcpy(copy, buffer, 20);

    for (j = 0; j < numDigits; j++) copy[indicesArr[j]] = '1';
    sscanf(copy, "%d", &currNum);
    if (isPrimeArr[currNum]){
        family[size] = currNum;
        size++;
    }

    for (i = 2; i < 10; i++){
        for (j = 0; j < numDigits; j++) copy[indicesArr[j]]++;
        sscanf(copy, "%d", &currNum);
        if (isPrimeArr[currNum]){
            family[size] = currNum;
            size++;
        }

        if (size < i-1) return size;
    }

    return size;
}

int main(){
    int i, j, k;
    char buffer[20] = {0};
    int digitSum, familyValue, stringLength, numDigits, currDigit;
    int indices, indicesLimit, curr;
    int indicesArr[10];

    genPrimes();

    i = 0;
    
    while (primes[i] <= 56993) i++;

    for (; i < numPrimes; i++){
        if (!primes[i]) continue;

        memset(buffer, 0, 20);
        sprintf(buffer, "%d", primes[i]); 
        stringLength = strlen(buffer); 

        indicesLimit = 1 << stringLength;
        for (indices = 1; indices < indicesLimit; indices++){
            memset(indicesArr, 0, 10*sizeof(int));
            numDigits = 0;
            currDigit = 0;
            curr = indices;
            while (curr){
                if (curr & 1){
                    indicesArr[numDigits] = currDigit;
                    numDigits++;
                }
                currDigit++;
                curr >>= 1;
            }

            digitSum = 0;
            for (j = 0; j < stringLength; j++)
                digitSum += buffer[j] - '0';
            for (j = 0; j < numDigits; j++)
                digitSum -= buffer[indicesArr[j]] - '0';
            
            if ((numDigits % 3) == 2 && (digitSum % 3) == 2){
                if ((familyValue = 
                            calcFamily(buffer, indicesArr, numDigits)) > 7){
                    printf("%d\n", family[0]);
                    return 0;
                }
            }

            else if (!(numDigits % 3) && ((digitSum % 3) == 1 || 
                        (digitSum % 3) == 2)){
                if ((familyValue = 
                            calcFamily(buffer, indicesArr, numDigits)) > 7){
                    printf("%d\n", family[0]);
                    return 0;
                }
            } 
        }
    }

    return -1;
}
