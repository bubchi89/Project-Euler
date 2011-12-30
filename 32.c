#include <stdio.h>

static int PERMUTATIONS = 9*8*7*6*5*4*3*2*1;

void reverse(char arr[9], int beg){
    int end = 8;
    char temp;

    while (beg < end){
        temp = arr[beg];
        arr[beg] = arr[end];
        arr[end] = temp;
        beg++;
        end--;
    }
}

void printArray(char arr[9]){
    int i;

    for (i = 0; i < 9; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");
}

void nextPermutation(char arr[9]){
    int j, k;
    char temp;

	j = 7;
	while (arr[j+1] < arr[j]) j--;
    if (j < 0) return;
	k = j+1;
	while (arr[k] > arr[j] && k < 9) k++;
	temp = arr[k-1];
    arr[k-1] = arr[j];
    arr[j] = temp;
    reverse(arr, j+1); 
}

int main(){
    char digits[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    char pandigitals[9877] = {0};
    int i;
    int MP1, MP2, MP3, MP4, prod23, prod14, target;
    unsigned long sum = 0;

    for (i = 0; i < PERMUTATIONS; i++){
        
        MP2 = digits[0]*10 + digits[1];
        MP3 = digits[2]*100 + digits[3]*10 + digits[4];
        prod23 = MP2 * MP3;

        MP1 = digits[0];
        MP4 = digits[1]*1000 + digits[2]*100 + digits[3]*10 + digits[4];
        prod14 = MP1 * MP4;

        target = digits[5]*1000 + digits[6]*100 + digits[7]*10 + digits[8];

        if (prod23 == target || prod14 == target){
            pandigitals[target] = 1; 
        /*    printf("MP1: %d, MP2: %d, MP3: %d, MP4: %d, Prod23: %d, "
                   "Prod14: %d\n", MP1, MP2, MP3, MP4, prod23, prod14);
                   */
        }
        nextPermutation(digits);
    }

    for (i = 0; i < 9877; i++){
        if (pandigitals[i]) sum += i;
    }

    printf("%lu\n", sum);

    return 0;
}

