#define HERO '@'
#define GHOST 'G'
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
int findonmap(MAP *m, POSITION *p, char c);
int isvalid(MAP *m, int x, int y);
int isempty(MAP *m, int x, int y);
int moveonmap(MAP *m, int xorigin, int yorigin, int xdestiny, int ydestiny);
void copymap(MAP *destiny, MAP *origin);
int canmove(MAP *m, int x, int y);
