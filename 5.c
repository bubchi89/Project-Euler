#include <stdio.h>

long lcm(long, long);
long gcd(long, long);

int main(){
    long i, currLCM = lcm(20, 19);

    for (i = 18; i > 9; i--){
        currLCM = lcm(currLCM, i); 
    }

    printf("%lu", currLCM);
    return 0;
}

long lcm(long a, long b){
    return a*b/gcd(a, b);
}

long gcd(long a, long b){
    while (a && b){
        printf("a: %lu, b: %lu\n", a, b);
        if (a > b) a = a % b;
        else b = b % a;
    }

    if (a) return a;
    return b;
}

