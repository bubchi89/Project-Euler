#include <stdio.h>
#include <math.h>

int main(){
    long double floatM, floatK;
    unsigned long n, m, k;

    for (n = 286; n > 0; n++){
        floatM = (1 + sqrt(1 + 12*(n*n + n)))/6;
        if (fmod(floatM, 1.0) == 0.0){
            m = (int) floatM;
            floatK = (1 + sqrt(1 + 4*(3*m*m - m)))/4;
            if (fmod(floatK, 1.0) == 0.0){
                k = (int) floatK;
                printf("tri: %lu, pent: %lu, hex: %lu\n", n, m, k);
                printf("answer: %lu\n", n*(n+1) >> 1);
                return 0;
            }
        }
    }

    return -1;
}
