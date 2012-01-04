#include <stdio.h>
#include <gmp.h>

#define MAX_NATURAL 99

unsigned calc_digit_sum(mpz_t *bignum);

int main()
{
	unsigned a, b, curr_sum, max_sum = 0;
	unsigned curr_pow;
	mpz_t base, curr;

	mpz_init(base);
	mpz_init(curr);

	/* Could loop backwards but that check is a small percentage of
	 * computation */
	for (a = 2; a <= MAX_NATURAL; a++)
	{
		for (b = 2; b <= MAX_NATURAL; b++)
		{
			/* Initialize */
			mpz_set_ui(base, a);
			mpz_set_ui(curr, a);

			/* Calculate exponent */
			/* Could do this with the log power algorithm but this
			 * is already insanely fast... man gmp is sweet */
			for (curr_pow = 1; curr_pow < b; curr_pow++)
			{
				mpz_mul(curr, curr, base);
			}

			/* Calculate the digit sum */
			curr_sum = calc_digit_sum(&curr);

			if (curr_sum > max_sum)
			{
				max_sum = curr_sum;
//				printf("New Max: %s\n", 
//						mpz_get_str(NULL, 10, curr));
//				printf("New Max Sum: %d, a: %d, b: %d\n", 
//						max_sum, a, b);
			}
		}
	}

	printf("max: %d\n", max_sum);

	mpz_clear(base);
	mpz_clear(curr);

	return 0;
}

unsigned calc_digit_sum(mpz_t *bignum)
{
	char *bignum_as_string = mpz_get_str(NULL, 10, *bignum);
	unsigned i = 0, sum = 0;

	while (bignum_as_string[i])
	{
		sum += bignum_as_string[i] - '0';

		i++;
	}

	return sum;
}
