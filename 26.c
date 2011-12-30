#include <stdio.h>
#include <stdlib.h>

int findCycleLength(int d){
    int remainder = 10, cycleLength = 0;
    char *remainders;
    
    remainders = calloc(d, sizeof(char));
    if (!remainders) return -1;

    while (remainder < d) remainder *= 10;

    remainder %= d;

    while (remainder && !remainders[remainder]){
        remainders[remainder]++;
        remainder *= 10;
        remainder %= d;
    }

    while (remainders[remainder] < 2){
        remainders[remainder]++;
        remainder *= 10;
        remainder %= d;
        cycleLength++;
    }

    /*printf("%d: %d\n", d, cycleLength);*/

    free(remainders);

    if (!remainder) return -1;

    return cycleLength;
}

int main(){
    int currMax = 0, maxCycle = 0, d;

    for (d = 2; d < 1000; d++){
        if (findCycleLength(d) > maxCycle){
            maxCycle = findCycleLength(d);
            currMax = d;
        }
    }

    printf("%d\n", currMax);

    return 0;
}
