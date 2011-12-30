#include <stdio.h>
#include <string.h>

#define PRIMES_SIZE 7654322
#define BUFFER_SIZE 8

char primes[PRIMES_SIZE] = {0};

void genPrimes(){
    int i, currPrime = 3;

    primes[2] = 1;
    
    for (i = 3; i < PRIMES_SIZE; i += 2) primes[i] = 1;

    while (currPrime*currPrime < PRIMES_SIZE){
        for (i = (currPrime << 1); i < PRIMES_SIZE; i += currPrime){
            primes[i] = 0;
        }

        currPrime += 2;

        while (!primes[currPrime]) currPrime += 2;
    }
}

void reverse(char arr[BUFFER_SIZE], int beg, int end){
    char temp;

    while (beg < end){
        temp = arr[beg];
        arr[beg] = arr[end];
        arr[end] = temp;
        beg++;
        end--;
    }
}

void nextPermutation(char arr[BUFFER_SIZE], int size){
    int i = size-2, j;
    char temp;

    while (arr[i] < arr[i+1] && i > -1) i--;
    if (i < 0) return;
    j = i + 1;
    while (arr[j+1] < arr[i] && (j+1) < size) j++;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    reverse(arr, i+1, size-1);
}

void printArr(char arr[BUFFER_SIZE], int size){
    int i;

    for (i = 0; i < size; i++){
        printf("%d ", arr[i] - '0');
    }
    printf("\n");
}

int main(){
    int i;
    char num[BUFFER_SIZE] = {'7', '6', '5', '4', '3', '2', '1', 0};
    int largest = 0, curr;

    genPrimes();

    for (i = 0; i < 7*6*5*4*3*2; i++){
        printArr(num, 7);
        sscanf(num, "%d", &curr);
        
        if (primes[curr]){
            largest = curr; 
            break;
        }

        nextPermutation(num, 7);
    }

    if (largest <= 2143){
        memset(num, 0, BUFFER_SIZE);
        num[0] = '4';
        num[1] = '3';
        num[2] = '2';
        num[3] = '1';

        for (i = 0; i < 4*3*2; i++){
            sscanf(num, "%d", &curr);

            if (primes[curr]){
                largest = curr;
                break;
            }

            nextPermutation(num, 4);
        }
    }

    printf("%d\n", largest);
   
    return 0; 
}
