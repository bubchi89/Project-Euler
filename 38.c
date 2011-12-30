#include <stdio.h>
#include <string.h>

int isPandigital(char *arr){
    int i;
    char digits[10] = {0};
    char currDigit;
    
    if (strlen(arr) > 9) return 0;

    for (i = 0; i < 9; i++){
        currDigit = arr[i] - '0';
        if (currDigit) digits[currDigit]++;
        else return 0;
        if (digits[currDigit] > 1) return 0;
    }

    return 1; 
}

int main(){
    int i, j, currPandigital, maxPandigital = 918273645;
    char curr[12] = {0}, buffer[10] = {0};

    for (i = 9000; i < 10000; i++){
        memset(curr, 0, 12);
        sprintf(curr, "%d", i);
        for (j = 2; strlen(curr) < 9; j++){
            sprintf(buffer, "%d", i*j);
            strcat(curr, buffer);
            memset(buffer, 0, 10);
        }
        
        if (isPandigital(curr)){
            sscanf(curr, "%d", &currPandigital);
            if (currPandigital > maxPandigital){
                maxPandigital = currPandigital;
            }
        }
    }

    printf("%d\n", maxPandigital);

    return 0;
}
