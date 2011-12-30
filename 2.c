#include <stdio.h>

int main(){
    long f_n = 1, f_n1 = 2, sum = 0, temp;
    int n = 0;
    
    while (f_n1 < 4000000){
        sum += (n % 6 == 0) ? f_n1:((n % 6 == 2) ? 0:f_n);
        f_n += f_n1;
        f_n1 += f_n;
        n += 2;
    }

    printf("%lu\n", sum);
    
    sum = 0; f_n = 1; f_n1 = 2; 
    while (f_n < 4000000){
        temp = f_n + f_n1; f_n = f_n1; f_n1 = temp;
        if (!(f_n % 2)) sum += f_n; 
    }

    printf("%lu", sum);

    return 0;
}


