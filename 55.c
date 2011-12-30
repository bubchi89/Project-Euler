#include <stdio.h>
#include <string.h>

#define NUM_ITER 50

#define MAX_NUM 10000

#define ARR_SIZE 56

typedef struct numarr
{
	int arr[ARR_SIZE];
	int len;
} numarr_t;

int is_lychrel(int num);
int is_palindrome(numarr_t *p);
void print_arr(numarr_t *p);
void sum_rec(numarr_t *num, numarr_t *sum);
void normalize(numarr_t *sum);
void num_to_numarr(int n, numarr_t *p);

int main()
{
	int i;
	int num_lychrel = 0;

	/* Start at 5, make addition stuff easier (removes 0 edge case) */
	for (i = 5; i < MAX_NUM; i++)
	{
		if (is_lychrel(i))
		{
			num_lychrel++;
		}
	}

	printf("Total: %d\n", num_lychrel);

	return 0;
}

int is_lychrel(int n)
{
	int i;
	numarr_t num, sum;
	numarr_t *nump = &num, *sump = &sum;

	memset(nump->arr, 0, ARR_SIZE * sizeof(int));
	memset(sump->arr, 0, ARR_SIZE * sizeof(int));

	// Convert num to an array
	num_to_numarr(n, nump);
	// Initialize sum
	sump->len = 0;

	// Do two iterations each time to keep naming correct
	for (i = 0; i < NUM_ITER; i += 2)
	{
		// First iteration
		sum_rec(nump, sump);
		if (is_palindrome(sump))
		{
			//printf("%d IS NOT LYCHREL: ", n);
			//print_arr(sump);

			return 0;
		}
		
		// Second iteration
		sum_rec(sump, nump);
		if (is_palindrome(nump))
		{
			//printf("%d IS NOT LYCHREL: ", n);
			//print_arr(nump);

			return 0;
		}
	}

	//printf("IS LYCHREL\n");
	return 1;
}

int is_palindrome(numarr_t *p)
{
	int high_to_low, low_to_high;

	high_to_low = p->len - 1;
	low_to_high = 0;

	while (low_to_high < high_to_low)
	{
		if (p->arr[low_to_high] != p->arr[high_to_low])
		{
			return 0;
		}

		high_to_low--;
		low_to_high++;
	}

	return 1;
}

void print_arr(numarr_t *p)
{
	int i = p->len - 1;

	for (; i >= 0; i--)
	{
		printf("%d", p->arr[i]);
	}

	printf("\n");
}

void num_to_numarr(int n, numarr_t *p)
{
	p->len = 0;

	while (n > 0)
	{
		p->arr[p->len] = n % 10;
		p->len++;
		n = n / 10;
	}
}

void sum_rec(numarr_t *num, numarr_t *sum)
{
	int i;

	for (i = 0; i < num->len; i++)
	{
		sum->arr[i] = num->arr[i] + num->arr[num->len-i-1];
	}

	normalize(sum);
}

void normalize(numarr_t *sum)
{
	int i;

	for (i = 0; i < ARR_SIZE; i++)
	{
		if (sum->arr[i] >= 10)
		{
			sum->arr[i+1] += sum->arr[i] / 10;
			sum->arr[i] %= 10;
		}
	}

	// Find len
	i = ARR_SIZE-1;
	while (sum->arr[i] == 0)
	{
		i--;
	}

	sum->len = i + 1;
}
