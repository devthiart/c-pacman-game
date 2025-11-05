#include <stdio.h>
#include <stdlib.h>

int main()
{
	// Matrix of 5x10
	// 10+1 because every string ends with /0
	char map[5][10 + 1];

	FILE *f;
	f = fopen("map.txt", "r");
	if (f == 0)
	{
		printf("Error reading file");
		exit(1);
	}

	for (int i = 0; i < 5; i++)
	{
		fscanf(f, "%s", map[i]);
	}

	printf("Printing by string:\n");
	for (int i = 0; i < 5; i++)
	{
		printf("%s\n", map[i]);
	}

	printf("Printing by char:\n");
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf("%c", map[i][j]);
		}
		printf("\n");
	}

	return 0;
}
