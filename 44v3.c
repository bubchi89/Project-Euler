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

int resize(int currDiff){
    if((SIZE = genPent(SIZE, (((currDiff - 1) >> 1) + 1))) < 0)
        return -1;

    printf("SIZE: %d, pent[SIZE-1]: %lu\n", SIZE, pent[SIZE-1]);
    
    return 1;
}

int main(){ 
    time_t start, end;
    int d, j, lowerInd;
    double n = 1.0;
    unsigned long currDiff, currLower, currHigher, currIndDiff;

    time(&start);
    
    SIZE = genPent(1, SIZE);

    for (d = 1; d < SIZE; d++){
        currDiff = pent[d];
        printf("%d: %lu\n", d, currDiff);

        j = 1;

        do{
            while (j >= SIZE){
                if (resize(currDiff) < 0) return -1;
            }

            currIndDiff = pent[j];

            n = (currDiff - currIndDiff)/((long double)((j << 1) + j));
            if (n > 0){
	            if (fmod(n, 1.0) == 0.0){
                    lowerInd = (int) n;

                    while (lowerInd >= SIZE){
                        if (resize(currDiff) < 0) return -1;
                    }

                    currLower = pent[lowerInd];
                    currHigher = pent[lowerInd + j];
                    if (isPent(currLower + currHigher)){
                        printf("Answer: %lu, currLower: %lu, currHigher: %lu\n",
                                currDiff, currLower, currHigher);
	                    time(&end);
	                    printf("Time: %f\n", difftime(end, start));

	                    return 0;
                    }
	            }
            }

            j++;

        } while (n > 0);
    }

    return -1;
}
