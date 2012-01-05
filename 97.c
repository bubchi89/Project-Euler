/**
 * In mult() we multiply the multiplicand by the 10-digit array and store
 * the result in the same array.
 * Algorithm by Dan Walker: Generate the ith digit by multiplying the ith digit
 * in the array by the multiplicand and storing the lowest digit in the ith
 * digit of the array. The carry accumulates until the end when we replace the
 * remaining digits with the carry (ignoring overflow).
 */

#include <stdio.h>

void mult(int *arr, int multiplicand);

int main()
{
	int power = 7830457;
	int multiplicand = 28433;
	int ten_arr[10];
	int i;

	for (i = 0; i < 10; i++)
	{
		ten_arr[i] = -1;
	}
	ten_arr[9] = 1;
	for (i = 0; i < power; i++)
	{
		mult(ten_arr, 2);
	}

	mult(ten_arr, multiplicand);

	for (i = 0; i < 10; i++)
	{
		printf("%d", ten_arr[i]);
	}
	printf("\n");

	return 0;
}

/* Multiplies 10 digits in arr by multiplicand */
void mult(int *arr, int multiplicand)
{
	int index = 9, carry = 0;
	int new_digit;
	
	for (; index >= 0 && arr[index] != -1; index--)
	{
		new_digit = arr[index] * multiplicand + carry;
		carry = new_digit / 10;
		new_digit = new_digit % 10;
		arr[index] = new_digit;
	}

	while (index >= 0 && carry != 0)
	{
		arr[index] = carry % 10;
		carry /= 10;
		index--;
	}	
}
