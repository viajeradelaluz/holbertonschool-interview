#include "slide_line.h"

/**
 * slide_line - slides and merges an array of integers
 * @line: points to an array of integers containing size elements
 * @size: number of elements in array
 * Return: 1 upon success, or 0 upon failure
 */
void slide_left(int *line, size_t size)
{
	size_t i, j, k;

	for (i = 0, j = 0; i < size;)
	{
		if (line[i] == 0)
			for (; line[i] == 0;)
				i++;
		if (i == (size - 1))
			break;
		j = i + 1;
		if (line[j] == 0)
			for (; line[j] == 0;)
				j++;
		if (line[i] == line[j])
		{
			line[i] = line[i] + line[j];
			line[j] = 0;
			i = j + 1;
		}
		else
			i++;
		j = 0;
	}
	for (i = 0, k = 0; i < size; i++)
		if (line[i] != 0)
			line[k++] = line[i];
	while (k < size)
		line[k++] = 0;
}

/**
 * slide_line - slides and merges an array of integers
 * @line: points to an array of integers containing size elements
 * @size: number of elements in array
 * Return: 1 upon success, or 0 upon failure
 */
void slide_right(int *line, size_t size)
{
	size_t i, j;

	for (i = size; i > 0; i--)
	{
		for (j = i - 1; j > 0; j--)
		{
			if (line[i - 1] != 0)
			{
				if (line[i - 1] == line[j - 1])
				{
					line[i - 1] = line[i - 1] + line[j - 1];
					line[j - 1] = 0;
					break;
				}
				if (line[i - 1] != line[j - 1] &&
					line[j - 1] != 0)
					break;
			}
			if (line[i - 1] == 0)
			{
				if (line[j - 1] != 0)
				{
					line[i - 1] = line[j - 1];
					line[j - 1] = 0;
					i++;
					break;
				}
			}
		}
	}
}

/**
 * slide_line - slides and merges an array of integers
 * @line: points to an array of integers containing size elements
 * @size: number of elements in array
 * @direction: can be either SLIDE_LEFT or SLIDE_RIGHT
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction == SLIDE_LEFT)
		slide_left(line, size);
	else if (direction == SLIDE_RIGHT)
		slide_right(line, size);
	else
		return (0);
	return (1);
}
