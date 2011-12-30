#include <stdio.h>

short coins[8] = {1, 2, 5, 10, 20, 50, 100, 200};

int calcComb(int maxCoinIndex, int remaining){
    int i;
    int maxCoin = coins[maxCoinIndex];
    int mostMax = remaining/maxCoin;
    int newRemaining;
    int subTotal = 0;

    if (maxCoin == 1) return 1;

    for (i = mostMax; i >= 0; i--){
        newRemaining = remaining - i*maxCoin;
        subTotal += calcComb(maxCoinIndex-1, newRemaining);
    }

    return subTotal;
}

int main(){
    printf("%d\n", calcComb(7, 200));
    return 0;
}
