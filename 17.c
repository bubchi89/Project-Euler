#include <stdio.h>

#define ZERO 0
#define ONE 3
#define TWO 3
#define THREE 5
#define FOUR 4
#define FIVE 4
#define SIX 3
#define SEVEN 5
#define EIGHT 5
#define NINE 4
#define TEN 3
#define ELEVEN 6
#define TWELVE 6
#define THIRTEEN 8
#define FOURTEEN 8
#define FIFTEEN 7
#define SIXTEEN 7
#define SEVENTEEN 9
#define EIGHTEEN 8
#define NINETEEN 8
#define TWENTY 6
#define THIRTY 6
#define FORTY 5
#define FIFTY 5
#define SIXTY 5
#define SEVENTY 7
#define EIGHTY 6
#define NINETY 6
#define HUNDRED 7
#define AND 3

int singles[20] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, 
    TEN, ELEVEN, TWELVE, THIRTEEN, FOURTEEN, FIFTEEN, SIXTEEN, SEVENTEEN, 
    EIGHTEEN, NINETEEN}; 

int translate(int n){
    if (n < 20) return singles[n];

    else if (n < 100){
        switch (n/10){
            case 2: return TWENTY + translate(n % 10);
                    break;
            case 3: return THIRTY + translate(n % 10);
                    break;
            case 4: return FORTY + translate(n % 10); 
                    break;
            case 5: return FIFTY + translate(n % 10);
                    break;
            case 6: return SIXTY + translate(n % 10);
                    break;
            case 7: return SEVENTY + translate(n % 10);
                    break;
            case 8: return EIGHTY + translate(n % 10);
                    break;
            case 9: return NINETY + translate(n % 10);
                    break;
            default: printf("switch statement error.\n");
                     return 0;
        }
    }
    
    else if (!(n % 100)) return translate(n/100) + HUNDRED;
    else return translate(n/100*100) + translate(n % 100) + AND;

    return -1;
}

int main(){
    int i, translated, sum = 11;

    for (i = 1; i < 1000; i++){
        translated = translate(i);
        printf("%d: %d\n", i, translated);
        sum += translated;
    }

    printf("%d\n", sum);
    return 0;
}

