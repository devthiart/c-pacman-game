#include <stdio.h>
#include <stdlib.h>
#include "map.h"

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
	printf("Lines: %d Columns: %d\n", m->lines, m->columns);

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