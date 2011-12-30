#include <stdio.h>

void reverse(char arr[10], int beg){
    int end = 9;
    char temp;

    while (beg < end){
        temp = arr[beg];
        arr[beg] = arr[end];
        arr[end] = temp;
        beg++;
        end--;
    }
}

void printArray(char arr[10]){
    int i;

    for (i = 0; i < 10; i ++){
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main(){
    char arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i, j, k;
    char temp;

    for (i = 1; i < 1000000; i++){
        j = 8;
        while (arr[j+1] < arr[j]) j--;
        k = j+1;
        while (arr[k] > arr[j]) k++;
        temp = arr[k-1];
        arr[k-1] = arr[j];
        arr[j] = temp;
        reverse(arr, j+1);
    }

    printArray(arr);

    return 0;
}

