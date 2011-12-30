#include <stdio.h>
int main(int argc, char *argv[]){
    FILE *input;
    int arr[20][20], i, j, currMax = 0, curr;

    if (argc < 2 || argv[1] == NULL){
        printf("enter input file.\n"); 
        return 1;
    }
   
    input = fopen(argv[1], "r"); 

    for (i = 0; i < 20; i++){
        for (j = 0; j < 20; j++){
            fscanf(input, "%d", &arr[i][j]);
        }
    }

    for (i = 0; i < 20; i++){
        for (j = 0; j < 20; j++){
            printf("%02d ", arr[i][j]);
        }
        printf("\n");
    }

    /*horizontally*/
    for (i = 0; i < 20; i++){
        for (j = 0; j < 17; j++){
            curr = arr[i][j]*arr[i][j+1]*arr[i][j+2]*arr[i][j+3];
            if (curr > currMax) currMax = curr;
        }
    }

    /*vertically*/
    for (j = 0; j < 20; j++){
        for (i = 0; i < 17; i++){
            curr = arr[i][j]*arr[i+1][j]*arr[i+2][j]*arr[i+3][j];
            if (curr > currMax) currMax = curr;
        }
    }

    /*right diagonal*/
    for (i = 0; i < 17; i++){
        for (j = 0; j < 17; j++){
            curr = arr[i][j]*arr[i+1][j+1]*arr[i+2][j+2]*arr[i+3][j+3];
            if (curr > currMax) currMax = curr;
        }
    }

    /*left diagonal*/
    for (i = 0; i < 17; i++){
        for (j = 3; j < 20; j++){
            curr = arr[i][j]*arr[i+1][j-1]*arr[i+2][j-2]*arr[i+3][j-3];
            if (curr > currMax) currMax = curr;
        }
    }

    printf("%d", currMax);

    fclose(input);
    return 0;
}
