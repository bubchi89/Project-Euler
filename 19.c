#include <stdio.h>

#define JANUARY 31
#define FEBRUARY 28
#define MARCH 31
#define APRIL 30
#define MAY 31
#define JUNE 30
#define JULY 31
#define AUGUST 31
#define SEPTEMBER 30
#define OCTOBER 31
#define NOVEMBER 30
#define DECEMBER 31

int main(){
    int curr = 0, numSun = 0;
    int i, j;
    int arr[12] = {JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST,
        SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER};

    for (i = 1901; i <= 2000; i++){
        for (j = 0; j < 12; j++){
            if (!(curr % 7)) numSun++;
            curr += arr[j];
            if ((((i % 4 == 0) && !(i % 100 == 0)) || i % 400 == 0) && j == 1)
                curr++;
        }
        printf("%d\n", numSun);
    }

    printf("%d\n", numSun);

    return 0;

}

