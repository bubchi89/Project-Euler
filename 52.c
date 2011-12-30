#include <stdio.h>
#include <string.h>

int check(unsigned long n){
    char orig[20] = {0};
    char origCountArr[11];
    char curr[20] = {0};
    char currCountArr[11];
    unsigned long origCount, currCount, currNum = n;
    unsigned int i, j;

    sprintf(origCountArr, "%s", "0000000000");

    sprintf(orig, "%lu", n);
    for (i = 0; i < strlen(orig); i++) origCountArr[orig[i] - '0']++;
    sscanf(origCountArr, "%lu", &origCount);

    for (i = 2; i <= 6; i++){
        currNum += n; 
        sprintf(currCountArr, "%s", "0000000000");
        sprintf(curr, "%lu", currNum); 
        for (j = 0; j < strlen(curr); j++) 
            currCountArr[curr[j] - '0']++;
        sscanf(currCountArr, "%lu", &currCount);

        if (currCount != origCount) return 0;
    }     

    return 1;
}

int main(){
    unsigned long base = 10, i, limit;
    unsigned int j;

    while (1){
        limit = 7*base/10;
        for (j = 0; j < limit; j++){
            i = base + j;
            if (check(i)){
                printf("%lu\n", i);
                return 0;
            }
        } 

        base *= 10;
    }    

    return -1;
}
