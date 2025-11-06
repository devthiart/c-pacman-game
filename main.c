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

void printmap()
{
	for (int i = 0; i < 5; i++)
	{
		printf("%s\n", map[i]);
	}
}

int endgame()
{
	return 0;
}

void move(char direction)
{
	int x;
	int y;

	// Find player position
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (map[i][j] == '@')
			{
				x = i;
				y = j;
				break;
			}
		}
	}

	// move player on map
	switch (direction)
	{
	case 'a':
		map[x][y - 1] = '@';
		break;
	case 'w':
		map[x - 1][y] = '@';
		break;
	case 's':
		map[x + 1][y] = '@';
		break;
	case 'd':
		map[x][y + 1] = '@';
		break;
	}
	map[x][y] = '.';
}

int main()
{

	readmap();

	do
	{
		printmap();

		char userinput;
		scanf(" %c", &userinput);
		move(userinput);
	} while (!endgame());

	freemap();

	return 0;
}
