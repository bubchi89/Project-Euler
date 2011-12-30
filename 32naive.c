#include <stdio.h>

void genProducts(int products[3024]){
    int thousand, hundred, ten, one;
    int currProduct, i = 0;
    
    for (thousand = 1; thousand <= 9; thousand++){
        currProduct = thousand;

        for (hundred = 1; hundred <= 9; hundred++){
            if (hundred == thousand) continue;
            currProduct = currProduct*10 + hundred; 

            for (ten = 1; ten <= 9; ten++){
                if (ten == hundred || ten == thousand) continue;
                currProduct = currProduct*10 + ten;

                for (one = 1; one <= 9; one++){
                    if (one == ten || one == hundred ||
                            one == thousand) continue;
                    currProduct = currProduct*10 + one;
                    printf("%d\n", currProduct);
                    products[i] = currProduct;
                    i++;
                    currProduct = currProduct/10;
                }

                currProduct = currProduct/10;
            }

            currProduct = currProduct/10;
        }
    }
}

void setArr(char arr[9], int product){
    while (product){
        arr[product % 10] = 1;
        product /= 10;
    }
}

int main(){
    int products[3024] = {0};
    int i, j;
    char curr[9], currMultiplicand = 0;

    genProducts(products);

    for (i = 0; i < 3024; i++){
        j = 0;
        memset(curr, 0, 9);
        setArr(curr, products[3024]);
        while (!currMultiplicand){
            if (!curr[j]){
                currMultiplicand = j+1;
                curr[j] = 1;
            }
            j++;
        }

        j = 0;
        while (curr[j]) j++;

    return 0;
}
