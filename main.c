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
	m.matrix[hero.x][hero.y] = '.';

	// move player on map
	switch (direction)
	{
	case 'a':
		m.matrix[hero.x][hero.y - 1] = '@';
		hero.y--;
		break;
	case 'w':
		m.matrix[hero.x - 1][hero.y] = '@';
		hero.x--;
		break;
	case 's':
		m.matrix[hero.x + 1][hero.y] = '@';
		hero.x++;
		break;
	case 'd':
		m.matrix[hero.x][hero.y + 1] = '@';
		hero.y++;
		break;
	}
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
