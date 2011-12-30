#include <stdio.h>

int main(int argc, char *argv[]){
    FILE *inp;
    int carry = 0;
    unsigned short arr[100][50];
    int r, c;
    long sum;
    long longArr[50];

    if (argc < 2 || argv[1] == NULL){
        printf("enter input file");
        return 1;
    }

    inp = fopen(argv[1], "r");

    for (r = 0; r < 100; r++){
        for (c = 0; c < 50; c++){
            fscanf(inp, "%hu", &arr[r][c]);
        }
    }

    for (r = 0; r < 100; r++){
        for (c = 0; c < 50; c++){
            printf("%hu", arr[r][c]);
        }
        printf("\n");
    }
    
    for (c = 49; c > 9; c--){
        sum = carry;
        for (r = 0; r < 100; r++){
            sum += arr[r][c];  
        }
        carry = sum / 10;
    } 
    printf("%d\n", carry);

    for (r = 0; r < 100; r++){
        longArr[r] = 0;
        for (c = 0; c < 10; c++){
            longArr[r] = longArr[r]*10 + arr[r][c];
        }
    }

    sum = carry;

    /*greatest ten digits*/
    for (r = 0; r < 100; r++){
        sum += longArr[r];
        printf("currsum: %lu\n", sum);
    }
    
    printf("%lu", sum); 

    fclose(inp);
    return 0; 
}
