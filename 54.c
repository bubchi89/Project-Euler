#include <stdio.h>
#include <string.h>

#define HIGH 0
#define PAIR 1
#define TPAIR 2
#define THREE 3
#define STRAIGHT 4
#define FLUSH 5
#define HOUSE 6
#define FOUR 7
#define SFLUSH 8
#define RFLUSH 9

int cardMap[(int)'Z' + 1];
int fpairs[4];
int spairs[4];
char ftypes[10];
char stypes[10];

int compare(char curr, char min){
    return cardMap[(int) curr] - cardMap[(int) min];  
}

void sort(char hand[5][3]){
    char temp[3];
    char min;
    int i, j, minIndex;

    for (j = 0; j < 4; j++){
        min = hand[j][0];
        minIndex = j;
        for (i = j+1; i < 5; i++){
            if (compare(hand[i][0], min) < 0){
                min = hand[i][0];
                minIndex = i;
            }
        }

        strcpy(temp, hand[j]);
        strcpy(hand[j], hand[minIndex]);
        strcpy(hand[minIndex], temp);
    }
}

int handType(char hand[5][3], int pairs[4], char types[10]){
    int i;

    memset(types, 0, 10);
    memset(pairs, 0, sizeof(int)<<2);

    if (hand[0][0] == hand[1][0]) pairs[0] = cardMap[(int)hand[0][0]];
    if (hand[1][0] == hand[2][0]) pairs[1] = cardMap[(int)hand[1][0]];
    if (hand[2][0] == hand[3][0]) pairs[2] = cardMap[(int)hand[2][0]];
    if (hand[3][0] == hand[4][0]) pairs[3] = cardMap[(int)hand[3][0]];

    types[HIGH] = 1;

    if (pairs[0] || pairs[1] || pairs[2] || pairs[3]){
        types[PAIR] = 1;

        if ((pairs[0] && pairs[2] && (pairs[0] != pairs[2])) || 
                ((pairs[0] && pairs[3]) && (pairs[0] != pairs[3]))||
               ((pairs[1] && pairs[3]) && (pairs[1] != pairs[3])))
            types[TPAIR] = 1;

        if ((pairs[0] && pairs[1]) || (pairs[1] && pairs[2]) ||
               (pairs[2] && pairs[3]))
            types[THREE] = 1;

        if ((pairs[0] && pairs[1] && pairs[2]) || 
                (pairs[1] && pairs[2] && pairs[3]))
            types[FOUR] = 1;
    }

    else if (((cardMap[(int)hand[0][0]] + 1) ==
             cardMap[(int)hand[1][0]]) &&
            ((cardMap[(int)hand[1][0]] + 1) ==
             cardMap[(int)hand[2][0]]) &&
            ((cardMap[(int)hand[2][0]] + 1) ==
             cardMap[(int)hand[3][0]])){
        if (((cardMap[(int)hand[3][0]] + 1) ==
                cardMap[(int)hand[4][0]]))
            types[STRAIGHT] = 2;
        else if (hand[0][0] == '2' && hand[4][0] == 'A')
            types[STRAIGHT] = 1;
    }

    if ((hand[0][1] == hand[1][1]) && (hand[1][1] == hand[2][1]) &&
           (hand[2][1] == hand[3][1]) && (hand[3][1] == hand[4][1])){
        types[FLUSH] = 1;
    }

    if (types[STRAIGHT] && types[FLUSH]){
            types[SFLUSH] = 1;
            if (hand[0][0] == 10) types[RFLUSH] = 1;
    } 

    for (i = 9; i >= 0; i--){
        if (types[i]) return i;
    }

    return 0;
}

int checkHands(char first[5][3], char second[5][3]){
    int i,j;
    int firstValue, secondValue;

    firstValue = handType(first, fpairs, ftypes);
    secondValue = handType(second, spairs, stypes);

    if (firstValue < secondValue) return 0;
    else if (firstValue > secondValue) return 1;

    switch (firstValue){
        case HIGH:
            for (i = 4; i >= 0; i--){
                if (cardMap[(int)first[i][0]] > 
                        cardMap[(int)second[i][0]])
                    return 1;
                else if (cardMap[(int)first[i][0]] <
                        cardMap[(int)second[i][0]])
                    return 0;
            }

            return 0;
            break;
        case PAIR:
            for (i = 3; i >= 0; i--){ 
                if (!fpairs[i]) continue;
                for (j = 3; j >= 0; j--){
                    if (!spairs[j]) continue;
                    if (fpairs[i] > spairs[j]) return 1;
                    else if (fpairs[i] < spairs[j]) return 0;
                }
            }

            for (i = 4; i >= 0; i--){
                if (cardMap[(int)first[i][0]] > 
                        cardMap[(int)second[i][0]])
                    return 1;
                else if (cardMap[(int)first[i][0]] < 
                        cardMap[(int)second[i][0]])
                    return 0;
            }

            return 0;
            break;
        case TPAIR:
            for (i = 3; i >= 0; i--){
                if (!fpairs[i]) continue;
                for (j = 3; j >= 0; j--){
                    if (!spairs[j]) continue;
                    if (fpairs[i] > spairs[j]) return 1;
                    else if (fpairs[i] < spairs[j]) return 0;
                } 
            }

            for (i = i-2; i >= 0; i--){
                if (!fpairs[i]) continue;
                for (j = j-2; j >= 0; j--){
                    if (!spairs[j]) continue;
                    if (fpairs[i] > spairs[j]) return 1;
                    else if (fpairs[i] < spairs[j]) return 0;
                }
            }

            for (i = 4; i >= 0; i--){
                if (cardMap[(int)first[i][0]] > 
                        cardMap[(int)second[i][0]])
                    return 1;
                else if (cardMap[(int)first[i][0]] < 
                        cardMap[(int)second[i][0]])
                    return 0;
            }

            return 0;

            break;
        case THREE:
            for (i = 3; i >= 0; i--){
                if (!fpairs[i]) continue;
                for (j = 3; j >= 0; j--){
                    if (!spairs[i]) continue;
                    if (fpairs[i] > spairs[j]) return 1;
                    else if (fpairs[i] < spairs[j]) return 0;
                }
            }

            for (i = 4; i >= 0; i--){
                if (cardMap[(int)first[i][0]] > 
                        cardMap[(int)second[i][0]])
                    return 1;
                else if (cardMap[(int)first[i][0]] < 
                        cardMap[(int)second[i][0]])
                    return 0;
            }

            return 0; 

            break;
        case STRAIGHT:
            if (ftypes[STRAIGHT] == 1 && stypes[STRAIGHT] == 1) return 0;
            else if (ftypes[STRAIGHT] == 1 && stypes[STRAIGHT] == 2) return 0;
            else if (ftypes[STRAIGHT] == 2 && stypes[STRAIGHT] == 1) return 1;
            else{
                if (cardMap[(int)first[4][0]] >
                        cardMap[(int)second[4][0]])
                    return 1;
                else
                    return 0;
            }

            break;
        case FLUSH:
            for (i = 4; i >= 0; i--){
                if (cardMap[(int)first[i][0]] > 
                        cardMap[(int)second[i][0]])
                    return 1;
                else if (cardMap[(int)first[i][0]] < 
                        cardMap[(int)second[i][0]])
                    return 0;
            }

            return 0;

            break;
        case HOUSE:
            /*must be part of triple*/
            if (cardMap[(int)first[2][0]] >
                    cardMap[(int)second[2][0]])
                return 1;
            else if (cardMap[(int)first[2][0]] <
                    cardMap[(int)second[2][0]])
                return 0;

            else{
                for (i = 4; i >= 0; i--){
                    if (cardMap[(int)first[i][0]] > 
                            cardMap[(int)second[i][0]])
                        return 1;
                    else if (cardMap[(int)first[i][0]] < 
                            cardMap[(int)second[i][0]])
                        return 0;
                }
            }

            return 0;

            break;
        case FOUR:
            /*must be part of triple*/
            if (cardMap[(int)first[2][0]] >
                    cardMap[(int)second[2][0]])
                return 1;

            return 0; /*can't be equal quads */

            break;
        case SFLUSH:
            if (ftypes[STRAIGHT] == 1 && stypes[STRAIGHT] == 1) return 0;
            else if (ftypes[STRAIGHT] == 1 && stypes[STRAIGHT] == 2) return 0;
            else if (ftypes[STRAIGHT] == 2 && stypes[STRAIGHT] == 1) return 1;
            else{
                if (cardMap[(int)first[4][0]] >
                        cardMap[(int)second[4][0]])
                    return 1;
                else
                    return 0;
            }

            break;
        case RFLUSH:
            return 0;
            break;
        default:
            printf("Unrecognized Hand\n");
            return 0;
    }

    return 0;
}

int main(){
    FILE *inp;
    int i, handNum = 1, numWins = 0;
    char first[5][3] = {{0}};
    char second[5][3] = {{0}};

    inp = fopen("poker.txt", "r");

    if (!inp){
        printf("failed to open\n");
        return -1;
    }

    cardMap[(int)'2'] = 2;
    cardMap[(int)'3'] = 3;
    cardMap[(int)'4'] = 4;
    cardMap[(int)'5'] = 5;
    cardMap[(int)'6'] = 6;
    cardMap[(int)'7'] = 7;
    cardMap[(int)'8'] = 8;
    cardMap[(int)'9'] = 9;
    cardMap[(int)'T'] = 10;
    cardMap[(int)'J'] = 11;
    cardMap[(int)'Q'] = 12;
    cardMap[(int)'K'] = 13;
    cardMap[(int)'A'] = 14;

    while (fscanf(inp, "%2s %2s %2s %2s %2s %2s %2s %2s %2s %2s", 
                first[0], first[1], first[2], first[3], first[4],
                second[0], second[1], second[2], second[3], second[4]) 
            != EOF){

        sort(first);
        sort(second);
/*
        printf("%3d: ", handNum);
        for (i = 0; i < 5; i++) printf("%s ", first[i]);
        printf("| ");
        for (i = 0; i < 5; i++) printf("%s ", second[i]);
        printf("\n");
*/
        if (checkHands(first, second)){
            /*
            for (i = 0; i < 10; i++) printf("%d ", ftypes[i]);
            printf("| ");
            for (i = 0; i < 10; i++) printf("%d ", stypes[i]);
            */
            /*printf("Win\n\n");*/
            numWins++;
        }

        else{
            /*
            for (i = 0; i < 10; i++) printf("%d ", ftypes[i]);
            printf("| ");
            for (i = 0; i < 10; i++) printf("%d ", stypes[i]);
            printf("Lose\n\n");
            */
        }

        handNum++;
    }

    printf("%d\n", numWins);

    fclose(inp);

    return 0;
}
