#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"

void copymap(MAP *destiny, MAP *origin)
{
	destiny->lines = origin->lines;
	destiny->columns = origin->columns;

	allocmap(destiny);
	for (int i = 0; i < origin->lines; i++)
	{
		// for (int j = 0; j < origin->columns; j++)
		// {
		// 	destiny->matrix[i][j] = origin->matrix[i][j];
		// }
		strcpy(destiny->matrix[i], origin->matrix[i]);
	}
}

int moveonmap(MAP *m, int xorigin, int yorigin, int xdestiny, int ydestiny)
{
	char character = m->matrix[xorigin][yorigin];
	m->matrix[xdestiny][ydestiny] = character;
	m->matrix[xorigin][yorigin] = EMPTY;
}

int isvalid(MAP *m, int x, int y)
{
	if (x >= m->lines)
		return 0;
	if (y >= m->columns)
		return 0;

	return 1;
}

int isempty(MAP *m, int x, int y)
{
	return m->matrix[x][y] == EMPTY;
}

void findinmap(MAP *m, POSITION *p, char c)
{
	// Find player position
	for (int i = 0; i < m->lines; i++)
	{
		for (int j = 0; j < m->columns; j++)
		{
			if (m->matrix[i][j] == c)
			{
				p->x = i;
				p->y = j;
				break;
			}
		}
	}
}

void freemap(MAP *m)
{
	for (int i = 0; i < m->lines; i++)
	{
		free(m->matrix[i]);
	}
	free(m->matrix);
}

void allocmap(MAP *m)
{
	m->matrix = malloc(sizeof(char *) * m->lines);
	for (int i = 0; i < m->lines; i++)
	{
		m->matrix[i] = malloc(sizeof(char) * (m->columns + 1));
	}
}

void readmap(MAP *m)
{
	FILE *f;
	f = fopen("map.txt", "r");
	if (f == 0)
	{
		printf("Error reading file");
		exit(1);
	}

	fscanf(f, "%d %d", &m->lines, &m->columns);

	allocmap(m);

	for (int i = 0; i < 5; i++)
	{
		fscanf(f, "%s", m->matrix[i]);
	}

	fclose(f);
}

void printmap(MAP *m)
{
	for (int i = 0; i < 5; i++)
	{
		printf("%s\n", m->matrix[i]);
	}
}
