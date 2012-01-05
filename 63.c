/**
 *
 * 1^n is never n digits
 * 10^n is never n digits
 *
 * Anything greater will never satisfy the nth power with n digits
 * because they grow faster than 10 (in particular they grow
 * by at least 10 each time).
 *
 */
#include <stdio.h>
#include <gmp.h>
#include <string.h>

int num_len(mpz_t *z);

int main()
{
	int base, power, i;
	int num_satis = 1; /* 1^1 */
	mpz_t accum;

	mpz_init(accum);

	/* Do 2-9 */
	for (base = 2; base < 10; base++)
	{
		for (power = 1; ; power++)
		{
			mpz_set_ui(accum, base);
			for (i = 1; i < power; i++)
			{
				mpz_mul_ui(accum, accum, base);
			}

			/* Calculate the string length */
			if (num_len(&accum) == power)
			{
				//printf("%d^%d: %s\n", base, power, mpz_get_str(NULL, 10, accum));
				num_satis++;
			}
			else
			{
				 break;
			}
		}

	}

	printf("%d\n", num_satis);

	mpz_clear(accum);

	return 0;	
}

int num_len(mpz_t *z)
{
	char *z_as_str = mpz_get_str(NULL, 10, *z);

	return strlen(z_as_str);
}
