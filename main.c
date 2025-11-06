#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "map.h"

MAP m;

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

	readmap(&m);

	do
	{
		printmap(&m);

		char userinput;
		scanf(" %c", &userinput);
		move(userinput);
	} while (!endgame());

	freemap(&m);

	return 0;
}
