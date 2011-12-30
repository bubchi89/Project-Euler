#include <stdio.h>

int sumDiv(int n){
    int sum = 1, p = 2, j;

    while (p*p <= n){
        j = p;

        if (!(n % p)){
            while (!(n % p)){
                j *= p;
                n /= p;
            }
            sum = sum*(j-1)/(p-1);
        }
        
        if (p == 2) p = 3;
        else p += 2;
    }

    if (n > 1) sum *= (n+1);
    return sum;
}

int genAbundant(int abundArr[8000]){
    int i = 0, n;

    for (n = 2; n < 28123; n++){
        if (sumDiv(n) > (n << 1)){
            printf("%d: %d\n", i, n);
            abundArr[i] = n;
            i++;
        }
    }

    return i;
}

int bsearch(int arr[8000], int n, int size){
    int beg = 0, end = size-1, mid;

    while (beg <= end){
        mid = (end-beg)/2 + beg;
        if (arr[mid] == n) return mid;
        else if (arr[mid] > n) end = mid - 1;
        else beg = mid + 1;
    }

    return -1;
}

int main(){
    int abundArr[8000] = {0};
    int i, j, size;
    char found = 0;
    long sum = 0;

    size = genAbundant(abundArr);

    for (i = 0; i < size; i++){
        printf("%d\n", abundArr[i]);
    }

    for (i = 1; i < 28123; i++){
        j = 0;
        found = 0;
        while (abundArr[j] <= (i >> 1)){
            if (bsearch(abundArr, i-abundArr[j], size) > -1){
                found = 1;
                break;
            }
            j++;
        }
        if (!found) sum += i;
    }

    printf("%lu\n", sum);

    return 0;
}
