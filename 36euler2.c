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

int makePalindrome(int n, char oddLength){
    int palindrome = n;
    if (oddLength) n /= 10;

    while (n){
        palindrome = (palindrome * 10) + (n % 10);
        n /= 10;
    }

    return palindrome;
}

int makePalindromeBin(int n, char oddLength){
    int palindrome = n;
    if (oddLength) n >>= 1;

    while (n){
        palindrome = (palindrome << 1) + (n & 1);
        n >>= 1;
    }

    return palindrome; 
}

int main(){
    int arrStart, i, p;
    char binary[21] = {0};
    char decimal[10] = {0};
    unsigned long sum = 0;

    i = 1;
    p = makePalindromeBin(i, 1);
    while (p < 1000000){
        sprintf(decimal, "%d", p);
        if (isPalindrome(decimal)) sum += p;
        i++;
        p = makePalindromeBin(i, 1);
    }

    i = 1;
    p = makePalindromeBin(i, 0);
    while (p < 1000000){
        sprintf(decimal, "%d", p);
        if (isPalindrome(decimal)) sum += p;
        i++;
        p = makePalindromeBin(i, 0);
    }

    printf("%lu\n", sum);

    return 0;
}
