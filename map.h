#define HERO '@'
#define EMPTY '.'
#define WALL_VERTICAL '|'
#define WALL_HORIZONTAL '-'

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
void findinmap(MAP *m, POSITION *p, char c);
int isvalid(MAP *m, int x, int y);
int isempty(MAP *m, int x, int y);
int moveonmap(MAP *m, int xorigin, int yorigin, int xdestiny, int ydestiny);