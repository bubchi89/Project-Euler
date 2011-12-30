#include <stdio.h>
#include <math.h>

int powers[10] = {0};

int main(){
    int i, orig, curr, currDigit, currSum;
    unsigned long sum = 0;

    for (i = 0; i < 10; i++){
        powers[i] = (int) pow((float)i, 5.0);
    }

    for (orig = 32; orig < 999999; orig++){
        curr = orig;
        currSum = 0;
        while (curr){
           currDigit = curr % 10;
           curr /= 10; 
           currSum +=  powers[currDigit];
        }

        if (currSum == orig) sum += currSum;
    }

    printf("%lu\n", sum);

    return 0;
}
