#include <stdio.h>
#include <stdlib.h>

char **map;
int lines;
int columns;

int main()
{
	FILE *f;
	f = fopen("map.txt", "r");
	if (f == 0)
	{
		printf("Error reading file");
		exit(1);
	}

	fscanf(f, "%d %d", &lines, &columns);
	printf("Lines: %d Columns: %d\n", lines, columns);

	map = malloc(sizeof(char *) * lines);
	for (int i = 0; i < lines; i++)
	{
		map[i] = malloc(sizeof(char) * (columns + 1));
	}

	for (int i = 0; i < 5; i++)
	{
		fscanf(f, "%s", map[i]);
	}

	for (int i = 0; i < 5; i++)
	{
		printf("%s\n", map[i]);
	}

	fclose(f);

	for (int i = 0; i < lines; i++)
	{
		free(map[i]);
	}
	free(map);

	return 0;
}
