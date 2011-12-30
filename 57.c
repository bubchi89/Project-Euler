#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <gmp.h>

mpz_t curr_bot;
mpz_t curr_top;
mpz_t temp;

mpz_t pow_of_ten;

int iteration()
{

  mpz_set(temp, curr_bot);

  mpz_add(curr_bot, curr_bot, curr_top);
  mpz_add(curr_top, curr_bot, temp);

  /*
  mpz_out_str(stdout, 10, curr_top);
  printf("\n");
  */

  mpz_cdiv_q(temp, curr_bot, pow_of_ten);

  /*
  printf("top: ");
  mpz_out_str(stdout, 10, curr_top);
  printf("\nbot: ");
  mpz_out_str(stdout, 10, curr_bot);
  printf("\npow: ");
  mpz_out_str(stdout, 10, pow_of_ten);
  printf("\ntemp: ");
  mpz_out_str(stdout, 10, temp);
  printf("\n");
  */

  if (mpz_cmp_d(temp, 10) > 0)
  {
    mpz_mul_ui(pow_of_ten, pow_of_ten, 10);
  }
  else
  {
    mpz_cdiv_q(temp, curr_top, pow_of_ten);

    if (mpz_cmp_d(temp, 10) > 0)
    {
      /*
      printf("top: ");
      mpz_out_str(stdout, 10, curr_top);
      printf("\nbot: ");
      mpz_out_str(stdout, 10, curr_bot);
      printf("\n");
      */
      return 1;
    }
  }

  return 0;
}

int main()
{
  int num_huge_numerator = 0;
  int i;

  mpz_init_set_si(curr_bot, 2);
  mpz_init_set_si(curr_top, 3);
  mpz_init_set_ui(pow_of_ten, 1);
  mpz_init(temp);

  for (i = 1; i < 1000; i++)
  {
    if (iteration())
    {
      num_huge_numerator++;
    }
  }

  printf("%d\n", num_huge_numerator);

  return 0;
}

