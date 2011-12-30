#include <stdio.h>
#include <string.h>

char primes[10000] = {0};

void genPrimes(){
    int i, curr;

    primes[2] = 1;

    for (i = 3; i < 10000; i += 2){
        primes[i] = 1;
    }

    i = 3;

    while (i*i <= 10000){
        for (curr = (i << 1); curr < 10000; curr += i){
           primes[curr] = 0;
        }

        do i += 2;
        while (!primes[i]);
    } 

    primes[1487] = 0;
}

void reverse(char arr[4], int beg){
    int end = 3;
    char temp;

    while (beg < end){
        temp = arr[beg];
        arr[beg] = arr[end];
        arr[end] = temp;
        beg++;
        end--;
    }
}

int nextPerm(int i){
    int j, k;
    char arr[4] = {0};
    char temp;
    int ret;

    sprintf(arr, "%d", i);

    j = 2;

    while (arr[j] >= arr[j+1] && j > -1) j--;
    if (j < 0) return -1;
    k = j+1;
    while (arr[k+1] > arr[j] && (k+1) < 4) k++;
    temp = arr[k];
    arr[k] = arr[j];
    arr[j] = temp;

    reverse(arr, j+1);

    sscanf(arr, "%d", &ret);

    return ret;
}    

void genPerms(int perms[4*3*2]){
    int i, size = 1;
    int currPerm = perms[0];

    for (i = 1; i < 4*3*2; i++){
        currPerm = nextPerm(currPerm);
        if (perms[size-1] == currPerm) return; 
        if (primes[currPerm]){
            perms[size] = currPerm;
            size++;
        }
    }
}

int main(){
    int i, j, k, m;
    int permutations[4*3*2] = {0};
    int currDiff;

    genPrimes();

    for (i = 1001; i < 10000; i += 2){
        if (primes[i]){
            permutations[0] = i;
            genPerms(permutations); /*only prime perms*/
            for (j = 0; permutations[j+2] && j < (4*3*2); j++){
                for (k = j+1; permutations[k+1] && k < (4*3*2); k++){
                    currDiff = permutations[k] - permutations[j];
                    for (m = k+1; permutations[m] && m < (4*3*2); m++){
                        if (permutations[m] == permutations[k] + currDiff){
                            printf("%d%d%d\n", permutations[j], permutations[k],
                                    permutations[m]);
                            return 0;
                        }
                    }
                }
            }

            for (j = 0; permutations[j] && j < 4*3*2; j++){
                primes[j] = 0;
            }    
        }

        memset(permutations, 0, 4*3*2*sizeof(int));
    }

    return -1;
}
