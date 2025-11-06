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