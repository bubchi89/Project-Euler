#include <stdio.h>
#include <math.h>

#define MAX 1001

int main(){
    int a, b, c;
    int maxInd = 0, currInd, maxNum = 0;
    float floatC;
    char perimeters[MAX] = {0};

    for (b = 1; b <= 499; b++){
        for (a = b + 1; a <= 500-b; a++){
            floatC = sqrt((double)(a*a + b*b));
            if (fmod(floatC, 1.0) == 0.0){
                printf("a: %d, b: %d, c: %f\n", a, b, floatC);
                c = (int) floatC;
                if ((a+b+c) <= 1000) perimeters[a+b+c]++;
            }
        }
    }
             
    for (currInd = 0; currInd < MAX; currInd++){
        if (perimeters[currInd] > maxNum){
            maxInd = currInd;
            maxNum = perimeters[currInd];
        }
        printf("%d\n", perimeters[currInd]);
    }

    printf("%d: %d\n", maxInd, perimeters[maxInd]);

    return 0;
}
