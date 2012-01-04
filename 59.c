/**
 * I cheated. I did use unix and some heuristics, but
 * honestly I had no idea how to analyze the data I came up with.
 * The most commonly encrypted characters could have been XOR'd
 * with any of three characters...
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char key[3] = {'g', 'o', 'd'};

int main()
{
	int i, len = 0;
	int sum = 0;
	char *encrypted_text, *str;
	char *decrypted_text;
	FILE *file;

        if ((file = fopen("./cipher1.txt", "r")) == 0)
	{
		printf("fopen failed\n");
		return -1;
	}

	if ((encrypted_text = malloc(10000)) == 0)
	{

		printf("malloc failed\n");
		return -2;
	}

	if ((decrypted_text = malloc(10000)) == 0)
	{

		printf("malloc failed\n");
		return -2;
	}

	if (fscanf(file, "%s", encrypted_text) < 0)
	{
		printf("fscanf failed\n");
		return -3;
	}

	str = strtok(encrypted_text, ",");

	while (str != NULL)
	{
		for (i = 0; i < 3; i++)
		{
			sprintf(decrypted_text + len, "%c", atoi(str) ^ key[i]);
			sum += atoi(str) ^ key[i];
			len++;

			if ((str = strtok(NULL, ",")) == NULL)
			{
				break;
			}
		}
	}

	printf("%d\n", sum);

	fclose(file);

	return 0;
}
