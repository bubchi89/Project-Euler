#include <stdio.h>

int factorials[10] = {0};

int main(){
    int i, j, curr, currSum, currDigit;
    unsigned long sum = 0;

    factorials[0] = 1;

    for (i = 1; i < 10; i++){
        factorials[i] = i;
        for (j = i-1; j > 0; j--){
            factorials[i] *= j;
        }
    }

    for (i = 15; i < 10000000; i++){
        curr = i;
        currSum = 0;

        while (curr){
            currDigit = curr % 10;
            curr /= 10;
            currSum += factorials[currDigit];
        }
        
        if (currSum == i){
            sum += currSum;
        }
    }
        
    printf("%lu\n", sum);

    return 0;
}
