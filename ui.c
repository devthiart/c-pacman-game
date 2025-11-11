#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ui.h"

char ghostdrawing[4][7] = {
	{" .-.  "},
	{"| OO| "},
	{"|   | "},
	{"'^^^' "}};

char walldrawing[4][7] = {
	{"......"},
	{"......"},
	{"......"},
	{"......"}};

char herodrawing[4][7] = {
	{" .--. "},
	{"/ _.-'"},
	{"\\  '-."},
	{" '--' "}};

char pilldrawing[4][7] = {
	{"      "},
	{" .-.  "},
	{" '-'  "},
	{"      "}};

char emptydrawing[4][7] = {
	{"      "},
	{"      "},
	{"      "},
	{"      "}};

void printpart(char drawing[4][7], int part)
{
	printf("%s", drawing[part]);
}

void printmap(MAP *m)
{
	for (int i = 0; i < m->lines; i++)
	{
		for (int part = 0; part < 4; part++)
		{
			for (int j = 0; j < m->columns; j++)
			{
				switch (m->matrix[i][j])
				{
				case GHOST:
					printpart(ghostdrawing, part);
					break;

				case HERO:
					printpart(herodrawing, part);
					break;

				case PILL:
					printpart(pilldrawing, part);
					break;
				case WALL_VERTICAL:
				case WALL_HORIZONTAL:
					printpart(walldrawing, part);
					break;

				case EMPTY:
					printpart(emptydrawing, part);
					break;

				default:
					break;
				}
			}
			printf("\n");
		}
	}
}
