#include <stdio.h>

unsigned long mult(unsigned long curr, unsigned int base){
    curr = (curr*base) % 10000000000;

    return curr;
}

int main(){
    unsigned int i, j;
    unsigned long currValue, sum = 0;

    for (i = 1; i <= 1000; i++){
        currValue = i;
        for (j = 1; j < i; j++){
            currValue = mult(currValue, i);
        }
        sum += currValue;
        sum %= 10000000000;
    }

    printf("%lu\n", sum);
    
    return 0;
}
