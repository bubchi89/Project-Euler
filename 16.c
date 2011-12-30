#include <stdio.h>

char arr[1000];

int main(){
    int i, j;
    /*unsigned long pow = 1, copy;*/
    int sum;
/*
    for (i = 1; i < 64; i++){
        pow <<= 1;
        copy = pow;
        sum = 0;

        while (copy != 0){
            sum += copy % 10;
            copy /= 10;
        }

        printf("%d\n", sum);
    }
*/
    arr[0] = 2;

    for (i = 0; i < 999; i++){
        arr[0] <<= 1;
        j = 1;

        while (j < 1000){
            arr[j] <<= 1;
            arr[j] += arr[j-1] / 10;
            arr[j-1] = arr[j-1] % 10;
            j++;
        }
        /*
        for (j = 500; j >= 0; j--){
            printf("%d", arr[j]);
        }

        printf("\n");
        */
    }

    sum = 0;
    for (j = 0; j < 1000; j++){
        sum += arr[j]; 
    }

    printf("%d\n", sum);

    return 0;
}
