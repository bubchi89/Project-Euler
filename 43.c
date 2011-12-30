#include <stdio.h>

void reverse(short int arr[10], int beg){
    int end = 9;
    char temp;

    while (beg < end){
        temp = arr[beg];
        arr[beg] = arr[end];
        arr[end] = temp;
        beg++; end--;
    }
}

void nextPerm(short int arr[10]){
    int i, j;
    char temp;

    i = 8;
    while (arr[i] > arr[i+1] && i > -1) i--;
    if (i < 0) return;
    
    j = i+1; 
    while (arr[j+1] > arr[i] && (j+1) < 10) j++;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    reverse(arr, i+1);
}

unsigned long toInteger(short int arr[10]){
    int i;
    unsigned long ret = 0;

    for (i = 0; i < 10; i++){
        ret *= 10;
        ret += arr[i];
    }

    return ret;
}

void printArr(short int arr[10]){
    int i;

    for (i = 0; i < 10; i++) printf("%d ", arr[i]);

    printf("\n");
}

int main(){
    long i;
    int thirDiv, sevTeenDiv;
    short int currNum[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    unsigned long sum = 0, temp;

    printArr(currNum);

    for (i = 0; i < 10*9*8*7*6*5*4*3*2; i++){
        if (!(currNum[3] % 2)){
            if (!((currNum[2] + currNum[3] + currNum[4]) % 3)){
                if (!(currNum[5] % 5)){
                    if (!((currNum[4]*100 + currNum[5]*10 + currNum[6]) % 7)){
                        if (!((currNum[5] - currNum[6] + currNum[7]) % 11)){
                            thirDiv = currNum[6]*100 + currNum[7]*10 + 
                                currNum[8];
                            if (!(thirDiv % 13)){
                                sevTeenDiv = currNum[7]*100 + currNum[8]*10 +
                                    currNum[9];
                                if (!(sevTeenDiv % 17)){
                                    temp = toInteger(currNum);
                                    printf("%lu\n", temp);
                                    sum += temp;
                                }
                            }
                        }
                    }
                }
            }
        }
        nextPerm(currNum);
    }
    
    printf("%lu\n", sum);

    return 0;
}
