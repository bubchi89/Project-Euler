/**
 * Keep track of two rows. Use DP
 *
 * Max sum in row i is the max sum of its two possible predecessors in row i-1
 *
 * Once we hit row 100 (the input has 100 rows) just find the max sum.
 */
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ROWS 100

int main()
{
	FILE *file;
	int curr;
	int row, col, max_sum = 0;
	int tri[MAX_ROWS][MAX_ROWS];

	if ((file = fopen("./triangle.txt", "r")) == NULL)
	{
		printf("fopen failed\n");
		return -1;
	}

	fscanf(file, "%d", &(tri[0][0]));

	for (row = 1; row < MAX_ROWS; row++)
	{
		/* Do 0 edge case */
		fscanf(file, "%d", &curr);
		tri[row][0] = tri[row-1][0] + curr;

		/* Do normal case */
		for (col = 1; col < row; col++)
		{
			fscanf(file, "%d", &curr);
			tri[row][col] = (tri[row-1][col-1] > tri[row-1][col])
				? tri[row-1][col-1] + curr
				: tri[row-1][col] + curr;
		}

		/* Do col == row edge case */
		fscanf(file, "%d", &curr);
		tri[row][row] = tri[row-1][row-1] + curr;
	}

	for (col = 0; col < MAX_ROWS; col++)
	{
		if (tri[MAX_ROWS-1][col] > max_sum)
		{
			max_sum = tri[MAX_ROWS-1][col];
		}
	}

	printf("%d\n", max_sum);

	fclose(file);

	return 0;
}
