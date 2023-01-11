#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * grid_sum - Sum 3x3 grids
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 * Return: void
 */
void grid_sum(int grid1[3][3], int grid2[3][3])
{
	int x, y;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
			grid1[x][y] += grid2[x][y];
	}
}

/**
 * unstable - Check if grid is unstable
 * @grid: 3x3 grid
 * Return: 1 if unstable, 0 if not
 */
int unstable(int grid[3][3])
{
	int x, y;

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			if (grid[x][y] > 3)
				return (1);
		}
	}
	return (0);
}

/**
 * topple - Topple grid
 * @grid: 3x3 grid
 * Return: void
 */
void topple(int grid[3][3])
{
	int x, y, toppled[3][3];

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
			toppled[x][y] = grid[x][y];
	}

	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			if (toppled[x][y] > 3)
			{
				grid[x][y] -= 4;
				if (x - 1 >= 0)
					grid[x - 1][y] += 1;
				if (x + 1 < 3)
					grid[x + 1][y] += 1;
				if (y - 1 >= 0)
					grid[x][y - 1] += 1;
				if (y + 1 < 3)
					grid[x][y + 1] += 1;
			}
		}
	}
}

/**
 * sandpiles_sum - Sum 2 sandpiles
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 * Return: void
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	grid_sum(grid1, grid2);

	while (unstable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		topple(grid1);
	}
}
