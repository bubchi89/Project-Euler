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

int calcFamily(char buffer[20], int firstInd, int secInd){
    int i, size = 0;
    int currNum;
    char copy[20];
    
    memcpy(copy, buffer, 20);

    for (i = 0; i < 10; i++){
        copy[firstInd] = copy[secInd] = (i + '0');
        sscanf(copy, "%d", &currNum);
        if (isPrimeArr[currNum]){
            family[size] = currNum;
            size++;
        }
    }

    return size;
}

int main(){
    int i, j, k;
    char buffer[20] = {0};
    int digitSum, familyValue, stringLength, numDigits;
    char firstInd, secInd;

    genPrimes();

    i = 0;
    
    while (primes[i] < 56993) i++;

    for (; i < numPrimes; i++){
        if (!primes[i]) continue;

        memset(buffer, 0, 20);
        sprintf(buffer, "%d", primes[i]); 
        stringLength = strlen(buffer); 

        for (numDigits = 1; numDigits < stringLength; numDigits++){
	        for (firstInd = 0; firstInd < stringLength-2; firstInd++){
	            for (secInd = firstInd + 1; secInd < stringLength-1; secInd++){
	                digitSum = 0;
	                for (j = 0; j < stringLength; j++){
	                    if (j != firstInd && j != secInd) 
	                        digitSum += buffer[j] - '0';
	                }
	
	                if ((digitSum % 3) == 2){
	                    if ((familyValue = 
                                    calcFamily(buffer, firstInd, secInd)) > 7){
	                        printf("%d\n", family[0]);
	                        return 0;
	                    }
	
	                    else {
	                        for (k = 0; k < familyValue; k++)
	                            primes[family[k]] = 0;
	                    }
	
	                }
	            }
	        }
        }

    printf("%d\n", primes[i-1]);

    return -1;
}
