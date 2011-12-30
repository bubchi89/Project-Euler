#include <stdio.h>

int main(){
    int a, b, c;

    for (c = 998; c > 333; c--){
        for (a = 1; a < c; a++){
            for (b = a; b < c; b++){
                if (((a*a + b*b) == (c*c)) && ((a + b + c) == 1000)){
                    printf("a: %d, b: %d, c: %d\n", a, b, c);
                    printf("%d", a*b*c);
                }
            }
        }
    }
    return 0;
}
