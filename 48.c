#include <stdio.h>
#include <gmp.h>

int main(){
    unsigned int n, m;
    mpz_t i, sum, answer;
    mpz_init(i);
    mpz_init(sum);
    mpz_init(answer);
    mpz_set_ui(sum, 0);

    for (n = 1; n <= 1000; n++){
        mpz_set_ui(i, n);
        for (m = 1; m < n; m++){
            mpz_mul_ui(i, i, n);
        }
        mpz_add(sum, sum, i);
    }

    mpz_mod_ui(answer, sum, 10000000000);

    mpz_out_str(stdout, 10, answer);
    
    mpz_clear(i);
    mpz_clear(sum);
    mpz_clear(answer);

    return 0;
}
