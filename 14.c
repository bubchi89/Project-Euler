#include <stdio.h>

int main(){
    unsigned int n, curr, max = 0, nMax;
    unsigned long i;

    for (n = 2; n < 1000000; n++){
        curr = 0;
        i = n;
        while (i != 1){
            if (!(i % 2)) i /= 2;
            else i = 3*i + 1;
            curr ++;
        }  
        if (curr > max){
            max = curr;
            nMax = n;
            printf("%d\n", max);
        }
    }
    
    printf("%d", nMax);
    return 0;
}
