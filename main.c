#include <stdio.h>
#include <stdlib.h>
#include "main.h"

char **map;
int lines;
int columns;

void freemap()
{
	for (int i = 0; i < lines; i++)
	{
		free(map[i]);
	}
	free(map);
}

void allocmap()
{
	map = malloc(sizeof(char *) * lines);
	for (int i = 0; i < lines; i++)
	{
		map[i] = malloc(sizeof(char) * (columns + 1));
	}
}

void readmap()
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

	allocmap();

	for (int i = 0; i < 5; i++)
	{
		fscanf(f, "%s", map[i]);
	}

	fclose(f);
}

int main()
{

	readmap();

	for (int i = 0; i < 5; i++)
	{
		printf("%s\n", map[i]);
	}

	freemap();

	return 0;
}
