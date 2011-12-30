#include <stdio.h>
#include <string.h>

int itoa(int val, char *buffer, int base){
    int i = 20;

    for (; val && i; --i, val /= base){
        buffer[i] = "0123456789abcdef"[val % base];
    }

    return (i+1);

}

int isPalindrome(char *arr){
    int beg = 0, end = strlen(arr) - 1;

    while (beg < end){
        if (arr[beg] != arr[end]) return 0;
        beg++;
        end--;
    }

    return 1;
}

int main(){
    int arrStart, i;
    char binary[21] = {0};
    char decimal[10] = {0};
    unsigned long sum = 0;

    for (i = 1; i < 1000000; i += 2){
        arrStart = itoa(i, binary, 2);
        sprintf(decimal, "%d", i);
        if (isPalindrome(binary + arrStart) && isPalindrome(decimal)){
            /*printf("%d\n", i);*/
            sum += i;
        }
    }

    printf("%lu\n", sum);

    return 0;
}
