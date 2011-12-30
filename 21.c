#include <stdio.h>
#include <math.h>

int calcDivSum(int n){
    int sum = 1, i;
    double nSqrt = sqrt((double) n);

    if (!(fmod(n/nSqrt, 1))) sum += nSqrt;

    for (i = 2; i < nSqrt; i++){
        if (!(n % i)){
            sum += i;
            sum += n/i;
        }
    }

    return sum;
    
}

int main(){
    int i, da;
    int arr[10000];
    long sum = 0;

    arr[0] = 0;
    for (i = 1; i < 9999; i++){
        arr[i] = calcDivSum(i+1);
    }

    for (i = 0; i < 9999; i++){
        da = arr[i];
        if (da < 10000 && arr[i] != (i+1)){
           if (arr[da-1] == (i+1)){
               sum += (i+1);
               printf("%d: %d\n", (i+1), arr[i]);
               printf("%d: %d\n", arr[i], arr[da-1]);
           }
        } 
    }

    printf("%lu", sum);

    return 0;

}
