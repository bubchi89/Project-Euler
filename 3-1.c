#include <stdio.h>

int main(){
    long curr = 600851475143;
    int n = 2;

    while (n <= curr/2){ /*sqrt(curr) fails*/
        while (!(curr % n)){
            curr = curr/n;
        }
        n++;
    }

    printf("%lu", curr);
    return 0;
}
