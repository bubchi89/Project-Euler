#include <stdio.h>

void printArr(int arr[15][15]){
    int r, c;

    for (r = 0; r < 15; r++){
        for (c = 0; c < 15; c++){
            printf("%02d ", arr[r][c]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]){
    int arr[15][15] = {{0}};
    int r, c, max = 0;
    FILE *inp;

    if (argc < 2 || argv[1] == NULL){
        printf("enter input file\n");
        return -1;
    }

    inp = fopen(argv[1], "r");

    if (!inp){
        printf("entered invalid file\n");
        return -1;
    }

    for (r = 0; r < 15; r++){
        for (c = 0; c <= r; c++){
            fscanf(inp, "%d", &arr[r][c]);
        }
    }

    printArr(arr);

    for (r = 1; r < 15; r++){
        arr[r][0] += arr[r-1][0];
        for (c = 1; c <= r; c++){
            if (arr[r-1][c-1] > arr[r-1][c])
                arr[r][c] += arr[r-1][c-1];
            else arr[r][c] += arr[r-1][c];
        }
    }

    printArr(arr);

    for (c = 0; c < 15; c++){
        if (arr[14][c] > max) max = arr[14][c];
    }

    printf("%d", max);

    fclose(inp);
    return 0;
}
