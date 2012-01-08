/**
 * This solution assumes that there are no duplicate numbers
 * and no cycles. Otherwise the problem is actually hard.
 * It is simply a topological sort of the numbers in the input file.
 *
 * I used sort -u to get rid of duplicates
 *
 * This is the code that I should've written on the whiteboard
 * during my first Google interview s/[numbers]/[alphabet]/g
 *
 * TODO:
 * I don't know how to do this if there are cycles or repeated numbers
 */

#include <stdio.h>
#include <string.h>

void top_sort(int graph[][10], int sort[]);
int find_root(int graph[][10]);

int main()
{
	FILE *file;
	/* graph[i][j] == 1 iff there is a sequence "ij" in the input */
	int graph[10][10];
	int sort[10];
	/* Nodes that occur in input. We want the shortest sequence so we assume
	 * that no nodes are in the graph to start with, but we do need to keep
	 * track of nodes with no outgoing edges */
	int nodes[10];
	char curr[3];
	int i;

	if ((file = fopen("./keylog-short.txt", "r")) == NULL)
	{
		printf("fopen failed\n");
		return -1;
	}

	/* Initialize data structures */
	memset(graph, 0, 10*10*sizeof(int));
	memset(nodes, 0, 10*sizeof(int));

	while (fscanf(file, "%s", curr) != EOF)
	{
		graph[curr[0] - '0'][curr[1] - '0'] = 1;
		graph[curr[1] - '0'][curr[2] - '0'] = 1;

		nodes[curr[0] - '0'] = 1;
		nodes[curr[1] - '0'] = 1;
		nodes[curr[2] - '0'] = 1;
	}

	top_sort(graph, sort);

	for (i = 0; i < 10 && sort[i] > 0; i++)
	{
		printf("%d", sort[i]);
		// Unset this so we can print the remaining ones in the next
		// step
		nodes[sort[i]] = 0;
	}
	/* Add any numbers which have no successors */
	for (i = 0; i < 10; i++)
	{
		if (nodes[i])
		{
			printf("%d", i);
		}
	}

	printf("\n");

	fclose(file);
	
	return 0;
}

void top_sort(int graph[][10], int sort[])
{
	int curr_root, sort_ind = 0;
	
	while ((curr_root = find_root(graph)) != -1)
	{
		sort[sort_ind] = curr_root;
		sort_ind++;
	}
}

int find_root(int graph[][10])
{
	int tail, head, root = -1, i, j;
	int roots[10];
	
	/* Initialize possible roots */
	for (i = 0; i < 10; i++)
	{
		roots[i] = 0;
		for (j = 0; j < 10; j++)
		{
			if (graph[i][j])
			{
				roots[i] = 1;
				break;
			}
		}
	}

	for (tail = 0; tail < 10; tail++)
	{
		for (head = 0; head < 10; head++)
		{
			if (graph[tail][head])
			{
				roots[head] = 0;
			}
		}
	}

	for (i = 0; i < 10; i++)
	{
		if (roots[i])
		{
			root = i;
			break;
		}
	}

	if (root == -1)
	{
		return root;
	}
	
	/* Delete root node from graph */
	for (head = 0; head < 10; head++)
	{
		graph[root][head] = 0;
	}

	return root;
}
