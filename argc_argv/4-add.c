#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * main - entry point, adds inputs
 * @argc: arg count
 * @argv: arg list
 *
 * Return: 0 on success, 1 on fail
 */
int main(int argc, char *argv[])
{
	int sum = 0;
	int i = 1;
	int j;
	char *current;

	while (i < argc)
	{
		j = 0;
		current = argv[i];

		while (current[j] != '\0')
		{
			if (!isdigit(current[j]))
			{
				printf("Error\n");
				return (1);
			}

			j++;
		}

		sum += atoi(current);
		i++;
	}

	printf("%d\n", sum);
	return (0);
}
