#include <stdio.h>
#include <math.h>

int calcTri(int n){
    return (n+1)*n/2;
}

int calcNumDivisors(int triNum){
    int i, numDivisors = 0;

    if (sqrt((double) triNum) - (int) sqrt((double) triNum) == 0.0)
        numDivisors ++;
    
    for (i = 1; i < sqrt((double) triNum); i++){
        if (!(triNum % i)) numDivisors +=2;
    }

    return numDivisors;
}

int main(){
    int curr = 500, currTri;
    while (1){
        currTri = calcTri(curr);
        if (calcNumDivisors(currTri) > 500){
            printf("%d", currTri);
            return 0;
        }
        curr++;
    } 

    return 1;
}
