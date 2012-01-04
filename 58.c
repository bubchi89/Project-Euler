/**
 *
 * 37 36 35 34 33 32 31
 * 38 17 16 15 14 13 30
 * 39 18  5  4  3 12 29
 * 40 19  6  1  2 11 28
 * 41 20  7  8  9 10 27
 * 42 21 22 23 24 25 26
 * 43 44 45 46 47 48 49
 * 
 * Each new layer has four members on the diagonals (the four corners). The 
 * least member is the top right. Every corner thereafter is the length of the 
 * spiral - 1 greater than the previous corner. The value of the least corner is
 * the value of the greatest corner of the previous layer, plus the length of 
 * that layer, plus 1. So:
 * nextcorner = currcorner + layer_len - 1
 * leastcorner = currcorner + layer_len + 1 = currcorner + next_layer_len - 1
 * Thus they are equivalent
 */
#include <stdio.h>
#include <string.h>

int is_prime(int num);

int main()
{
	/* Start at the second layer */
	int layer_len = 3;
	int num_on_diag = 1;	/* Redundant but clearer */
	int num_prime = 0;
	int curr_corner = 1;
	int i;

	while (1)
	{
		/* Update number of elements on diagonals */
		num_on_diag += 4;

		/* Generate corners and check primality */
		for (i = 0; i < 4; i++)
		{
			curr_corner += layer_len - 1;

			num_prime += is_prime(curr_corner);
		}

		if (num_prime * 10 < num_on_diag)
		{
			break;
		}

		layer_len += 2;
		//printf("layer_len: %d, num_prime: %d, num_diag: %d\n", layer_len, num_prime, num_on_diag);
	}

	printf("len: %d\n", layer_len);

	return 0;
}

int is_prime(int num)
{
	int i;

	for (i = 3; i*i <= num; i += 2)
	{
		if (!(num % i))
		{
			return 0;
		}
	}

	return 1;
}
