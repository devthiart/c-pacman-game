#ifndef _MAP_H_
#define _MAP_H_

#define HERO '@'
#define GHOST 'G'
#define EMPTY '.'
#define WALL_VERTICAL '|'
#define WALL_HORIZONTAL '-'
#define PILL 'P'

struct map
{
	char **matrix;
	int lines;
	int columns;
};

typedef struct map MAP;

struct position
{
	int x;
	int y;
};

typedef struct position POSITION;

void freemap(MAP *m);
void readmap(MAP *m);
void allocmap(MAP *m);
void printmap(MAP *m);
int findonmap(MAP *m, POSITION *p, char c);
int isvalid(MAP *m, int x, int y);
int isempty(MAP *m, int x, int y);
int moveonmap(MAP *m, int xorigin, int yorigin, int xdestiny, int ydestiny);
void copymap(MAP *destiny, MAP *origin);
int canmove(MAP *m, char character, int x, int y);
int iswall(MAP *m, int x, int y);
int ischaracter(MAP *m, char character, int x, int y);

#endif
