#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int partition(char *arr[6000], int b, int e){
    char *pivot, *temp;
    int pivInd, leftEndInd, i;

    srand((unsigned) time(0));
    pivInd = rand() % (e-b+1) + b;
    pivot = arr[pivInd];
    arr[pivInd] = arr[e];
    arr[e] = pivot;

    leftEndInd = b-1;

    for (i = b; i < e; i++){
        if (strcmp(arr[i], pivot) <= 0){
            leftEndInd++;
            temp = arr[i];
            arr[i] = arr[leftEndInd];
            arr[leftEndInd] = temp;
        }
    }    

    temp = arr[leftEndInd+1];
    arr[leftEndInd+1] = arr[e];
    arr[e] = temp;

    return (leftEndInd+1);
}

void quicksort(char *arr[6000], int b, int e){
    int pivot;
    if (b < e){
        pivot = partition(arr, b, e);
        quicksort(arr, b, pivot - 1);
        quicksort(arr, pivot + 1, e);
    }
} 

int calcValue(char *name){
    int i = 0;
    int value = 0;

    while (name[i]){
        value += name[i] - 'A' + 1;
        i++;
    }

    return value;
}
        
int main(int argc, char *argv[]){
    FILE *inp;
    char *arr[6000], trash[5];
    int i = 0;
    unsigned long sum = 0;

    if (argc < 2 || argv[1] == NULL){
        printf("enter input file.\n");
        return -1;
    }

    inp = fopen(argv[1], "r");

    if (!inp){
        printf("input file name invalid.\n");
        return -1;
    }

    for (i = 0; i < 6000; i++){
        arr[i] = malloc(sizeof(char)*20);
        if (!arr[i]) printf("malloc failed\n");
    }

    i = 0;
    while (fscanf(inp, "%[^A-Z]%[^\"]", trash, arr[i]) > 1){
        printf("%s\n", arr[i]);
        i++;
    }

    quicksort(arr, 0, i-1);

    for (i = 0; i < 6000; i++){
        sum += calcValue(arr[i])*(i+1);
    }

    printf("%lu\n", sum);

    for (i = 0; i < 6000; i++){
        free(arr[i]);
    }

    fclose(inp);
    return 0;
}
