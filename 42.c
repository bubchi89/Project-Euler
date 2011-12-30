#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    FILE *inp;
    int i, numNames, numTri = 0, curr;
    unsigned int j;
    char *names[2000], buffer[20];
    char tri[5000] = {0};

    for (i = 1; i < 95; i++){
        tri[i*(i+1)/2] = 1;
    }

    if (argc < 2){
        printf("enter input file.\n");
        return -1;
    }

    inp = fopen(argv[1], "r");

    if (!inp){
        printf("input filename invalid.\n");
        return -1;
    }

    numNames = 0;
    while (fscanf(inp, "%*[^A-Z]%19[A-Z]", buffer) == 1){
        names[numNames] = malloc(strlen(buffer)+1);
        if (!names[numNames]) printf("malloc failed.\n");
        strcpy(names[numNames], buffer); 
        memset(buffer, 0, 20);
        numNames++;
    }

    for (i = 0; i < numNames; i++){
        curr = 0;
        for (j = 0; j < strlen(names[i]); j++){
            curr += (names[i][j] - 'A' + 1);
        }
        
        if (tri[curr]) numTri++;
    }

    printf("%d\n", numTri);

    for (i = 0; i < numNames; i++){
        free(names[i]);
    }

    return 0;
}
