#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int SIZE = 200000;
unsigned long pent[5000000] = {0};

int genPent(int beg, int end){
    unsigned long i;

    if (((beg << 1) > end) && (beg << 1) < 5000000){
        end = beg << 1;
        for (i = beg; i < (unsigned) end; i++){
            pent[i] = ((i*((i << 1) + i - 1)) >> 1);
        }

        return end;
    }

    else if (end < 5000000){
        for (i = beg; i < (unsigned) end; i++){
            pent[i] = ((i*((i << 1) + i - 1)) >> 1);
        }

        return end;
    }

    return -1;
}

int comparator(const void *n1, const void *n2){
    unsigned long num1 = *(unsigned long*) n1;
    unsigned long num2 = *(unsigned long*) n2;

    if (num1 > num2) return 1;
    if (num1 < num2) return -1;
    return 0;
}

int isPent(unsigned long n){
    return bsearch(&n, pent, SIZE, sizeof(unsigned long), comparator) != NULL;
}

int isPent2(unsigned long n){
    unsigned long c = n << 1;
    if (fmod(((sqrt((long double) (1 + ((3*c) << 2))) + 1)/6), 1.0) == 0.0)
        return 1;

    return 0;
}

int main(){ 
    time_t start, end;
    int j, k;
    unsigned long currDiff, minDiff = -1;

    time(&start);
    
    SIZE = genPent(1, SIZE);

    for (k = 1; k < SIZE; k++){
        /*printf("%lu\n", pent[k]);*/

        if (k >= SIZE && minDiff == (unsigned long)-1){
            SIZE = genPent(SIZE, SIZE << 1);
            if (SIZE < 0){
                printf("1st: Array size too small.\n");
                return -1;
            }
        }

        for (j = k-1; j > 0; j--){
            if (isPent(pent[k]-pent[j]) && isPent(pent[k]+pent[j])){
                currDiff = pent[k] - pent[j];
                printf("currDiff: %lu\n", currDiff);
                if (currDiff < minDiff){
                    minDiff = currDiff;
                    SIZE = genPent(SIZE, (minDiff - 1)/3);
                    if (SIZE < 0){
                        printf("Array size too small.\n");
                        return -1;
                    }
                }
            }
        }
    }

    printf("%lu\n", minDiff);

    time(&end);
    printf("%f\n", difftime(end, start));

    return -1;
}
