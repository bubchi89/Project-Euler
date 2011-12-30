#include <stdio.h>

int main(){
    int n, currStart, prevStart = 1;
    long sum = 1;

    for (n = 3; n <= 1001; n += 2){
        currStart = prevStart + 4*n - 10;
        sum += 4*currStart;
        sum += 6*(n-1);
        prevStart = currStart;
    }

    printf("%lu\n", sum);

    return 0;
}
