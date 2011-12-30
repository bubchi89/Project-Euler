#include <stdio.h>

int reverse(int n){
    int result = 0;

    while (n){
        result = 10*result;
        result += n % 10;
        n /= 10;
    }

    return result;
}

int main(){
    int num1, num2; 
    int currMax = 0, curr;
    
    for (num1 = 999; num1 >= 100; num1--){
        printf("%d\n", num1);
        num2 = 999;
        for(; num2 >= 100; num2--){
            curr = num1*num2;         
            if (curr == reverse(curr) && curr > currMax) currMax = curr;
        }
    }

    printf("%d", currMax); 

    return 0;
}
