#include <stdio.h>

int calcGCD(int a, int b){
    while (a && b){
        if (a > b) a = a % b;
        else b = b % a;
    }

    if (a) return a;
    return b;
}

double wrongDivision(int numerator, int denominator){
    int nOnes = numerator % 10, dOnes = denominator % 10;
    int nTens = numerator/10, dTens = denominator/10;

    if (numerator >= denominator) return -1; /* greater than 1 */

    if (nOnes == dOnes) return ((double) nTens)/dTens;
    if (nOnes == dTens) return ((double) nTens)/dOnes;
    if (nTens == dOnes) return ((double) nOnes)/dTens;
    if (nTens == dTens) return ((double) nOnes)/dOnes;

    else return -1; /* don't share a digit */
}

int main(){
    int i, j, numerator, denominator;
    int tens, ones;
    int numbers[100], size = 0;
    int finalNumerator = 1, finalDenominator = 1;

    for (tens = 1; tens <= 9; tens++){
        for (ones = 1; ones <= 9; ones++){
            numbers[size] = tens*10 + ones;
            size++;
        }
    }

    for (i = 0; i < size-2; i++){
        for (j = i+1; j < size; j++){
            numerator = numbers[i];
            denominator = numbers[j];
            if (wrongDivision(numerator, denominator) ==
                ((double) numerator)/denominator){
                finalNumerator *= numerator;
                finalDenominator *= denominator;
                printf("%d/%d\n", numerator, denominator);
            }
        }
    }

    printf("%d\n", finalDenominator/calcGCD(finalNumerator, finalDenominator));

    return 0;
}
