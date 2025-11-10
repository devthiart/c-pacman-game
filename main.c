#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"
#include "map.h"

MAP m;
POSITION hero;

int wheredoestheghostgo(int xcurrent, int ycurrent, int *xdestiny, int *ydestiny)
{
	int options[4][2] = {
		{xcurrent, ycurrent + 1},
		{xcurrent + 1, ycurrent},
		{xcurrent - 1, ycurrent},
		{xcurrent, ycurrent - 1}};

	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		int position = rand() % 4;
		if (canmove(&m, GHOST, options[position][0], options[position][1]))
		{
			*xdestiny = options[position][0];
			*ydestiny = options[position][1];

			return 1;
		}
	}

	return 0;
}

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
				int xdestiny;
				int ydestiny;

				int found = wheredoestheghostgo(i, j, &xdestiny, &ydestiny);

				if (found)
				{
					moveonmap(&m, i, j, xdestiny, ydestiny);
				}
			}
		}
	}

	freemap(&copy);
}

int endgame()
{
	POSITION pos;
	int heroisonmap = findonmap(&m, &pos, HERO);
	return !heroisonmap;
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
	if (!canmove(&m, HERO, nextx, nexty))
		return;

	moveonmap(&m, hero.x, hero.y, nextx, nexty);
	hero.x = nextx;
	hero.y = nexty;
}

int main()
{

	readmap(&m);
	findonmap(&m, &hero, HERO);

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
