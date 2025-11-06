#include <stdio.h>
#include <stdlib.h>
#include "main.h"

MAP m;

void freemap()
{
	for (int i = 0; i < m.lines; i++)
	{
		free(m.matrix[i]);
	}
	free(m.matrix);
}

void allocmap()
{
	m.matrix = malloc(sizeof(char *) * m.lines);
	for (int i = 0; i < m.lines; i++)
	{
		m.matrix[i] = malloc(sizeof(char) * (m.columns + 1));
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

	fscanf(f, "%d %d", &m.lines, &m.columns);
	printf("Lines: %d Columns: %d\n", m.lines, m.columns);

	allocmap();

	for (int i = 0; i < 5; i++)
	{
		fscanf(f, "%s", m.matrix[i]);
	}

	fclose(f);
}

void printmap()
{
	for (int i = 0; i < 5; i++)
	{
		printf("%s\n", m.matrix[i]);
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
	for (int i = 0; i < m.lines; i++)
	{
		for (int j = 0; j < m.columns; j++)
		{
			if (m.matrix[i][j] == '@')
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
		m.matrix[x][y - 1] = '@';
		break;
	case 'w':
		m.matrix[x - 1][y] = '@';
		break;
	case 's':
		m.matrix[x + 1][y] = '@';
		break;
	case 'd':
		m.matrix[x][y + 1] = '@';
		break;
	}
	m.matrix[x][y] = '.';
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
