#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "map.h"

MAP m;
POSITION hero;

int endgame()
{
	return 0;
}

void move(char direction)
{
	// Validating user input
	if (direction != 'w' &&
		direction != 'a' &&
		direction != 's' &&
		direction != 'd')
	{
		return;
	}

	int nextx = hero.x;
	int nexty = hero.y;

	switch (direction)
	{
	case 'a':
		nexty--;
		break;
	case 'w':
		nextx--;
		break;
	case 's':
		nextx++;
		break;
	case 'd':
		nexty++;
		break;
	}

	// Check if the hero can move to the desired position
	if (nextx >= m.lines)
		return;
	if (nexty >= m.columns)
		return;
	if (m.matrix[nextx][nexty] != '.')
		return;

	m.matrix[nextx][nexty] = '@';
	m.matrix[hero.x][hero.y] = '.';
	hero.x = nextx;
	hero.y = nexty;
}

int main()
{

	readmap(&m);
	findinmap(&m, &hero, '@');

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
