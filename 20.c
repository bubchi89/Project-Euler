#include <stdio.h>

void mult(int prod[200], int y);
void print(int arr[200]);

void mult(int prod[200], int y){
    int ones[200] = {0}, tens[200] = {0};
    int onesPlace = y % 10;
    int tensPlace = y / 10;
    int i;

    ones[0] = prod[0] * onesPlace;
    for (i = 1; i < 199; i++){
        ones[i] = prod[i] * onesPlace + (ones[i-1] / 10);
        ones[i-1] %= 10;
    } 
    
    tens[1] = prod[0] * tensPlace; 
    for (i = 1; i < 198; i++){
        tens[i+1] = prod[i] * tensPlace + (tens[i] / 10);
        tens[i] %= 10;
    }

    prod[0] = tens[0] + ones[0];
    for (i = 1; i < 200; i++){
        prod[i] = tens[i] + ones[i] + (prod[i-1] / 10);
        prod[i-1] %= 10;
    }

}

void print(int arr[200]){
    int i;

    for (i = 199; i >= 0; i--){
        printf("%d", arr[i]);
    }

    printf("\n");
}

int main(){
    int arr[200] = {1};
    int i;
    long sum = 0;
    
    for (i = 2; i < 100; i++){
        mult(arr, i);
    }

    for (i = 0; i < 200; i++){
        sum += arr[i];
    }

    printf("%lu", sum);

    return 0;

}
