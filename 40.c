#include <stdio.h>
#include <string.h>

int main(){
    int i = 1, nDigit;
    int product = 1, suffix = 1, length = 0;
    char buffer[10] = {0};
    
    while (length < 1000000){
        sprintf(buffer, "%d", i);

        if (((int) strlen(buffer) + length) >= suffix){
            nDigit = buffer[suffix - length - 1] - '0';
            printf("%d\n", nDigit);
            product *= nDigit;
            suffix *= 10;
        }

        length += strlen(buffer);
        i++;
    }

    printf("%d\n", product);

    return 0;
}
