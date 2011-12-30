#include <stdio.h>
#include <limits.h>
#include <string.h>

int calcFib(char (*fn1)[1000], char (*fn2)[1000], char (*sum)[1000], 
        int fn2Size){
    int i = 0;
    
    (*sum)[0] = (*fn1)[0] + (*fn2)[0];
    
    for (i = 1; i <= fn2Size; i++){
        (*sum)[i] = (*fn1)[i] + (*fn2)[i] + (*sum)[i-1]/10;
        (*sum)[i-1] %= 10;
    }

    if ((*sum)[fn2Size] > 0) fn2Size++;

    memcpy(*fn1, *fn2, 1000);
    memcpy(*fn2, *sum, 1000);
    
    return fn2Size;
}

void printArr(char arr[1000], int size){
    int i;
    
    for (i = 0; i < size; i++){
        printf("%d", arr[i]);
    }

    printf("\n");
}

int main(){
    unsigned long f_n1 = 1, f_n2 = 1, n = 2, temp, i;
    unsigned int fn2Size = 0;
    char fn1[1000] = {0}, fn2[1000] = {0}, tempArr[1000];

    while (f_n2 < (ULONG_MAX >> 1)){
        temp = f_n2;
        f_n2 += f_n1;
        f_n1 = temp;
        n++;
    }
    
    printf("%lu\n", f_n2);

    i = 0;
    while (f_n2){
        fn1[i] = f_n1 % 10;
        fn2[i] = f_n2 % 10;
        f_n1 /= 10;
        f_n2 /= 10;
        fn2Size++;
        i++;
    }

    while (fn2Size < 1000){
        memset(tempArr, 0, 1000);
        fn2Size = calcFib(&fn1, &fn2, &tempArr, fn2Size);
        n++;
    }

    printArr(fn2, fn2Size);

    printf("%lu\n", n);

    return 0;
}
