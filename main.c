#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "map.h"

MAP m;
POSITION hero;

void ghosts()
{
	MAP copy;

	copymap(&copy, &m);

	for (int i = 0; i < copy.lines; i++)
	{
		for (int j = 0; j < copy.columns; j++)
		{
			if (copy.matrix[i][j] == GHOST)
			{
				if (isvalid(&m, i, j + 1) && isempty(&m, i, j + 1))
				{
					moveonmap(&m, i, j, i, j + 1);
				}
			}
		}
	}

	freemap(&copy);
}

int endgame()
{
	return 0;
}

int validinput(char userinput)
{
	return userinput == UP ||
		   userinput == LEFT ||
		   userinput == DOWN ||
		   userinput == RIGHT;
}

void move(char direction)
{
	// Validating user input
	if (!validinput(direction))
		return;

	int nextx = hero.x;
	int nexty = hero.y;

	switch (direction)
	{
	case LEFT:
		nexty--;
		break;
	case UP:
		nextx--;
		break;
	case DOWN:
		nextx++;
		break;
	case RIGHT:
		nexty++;
		break;
	}

	// Check if the hero can move to the desired position
	if (!isvalid(&m, nextx, nexty))
		return;
	if (!isempty(&m, nextx, nexty))
		return;

	moveonmap(&m, hero.x, hero.y, nextx, nexty);
	hero.x = nextx;
	hero.y = nexty;
}

int main()
{

	readmap(&m);
	findinmap(&m, &hero, HERO);

	do
	{
		printmap(&m);

		char userinput;
		scanf(" %c", &userinput);
		move(userinput);
		ghosts();
	} while (!endgame());

	freemap(&m);

	return 0;
}
