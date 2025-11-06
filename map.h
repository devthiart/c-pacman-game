struct map
{
  char **matrix;
  int lines;
  int columns;
};

typedef struct map MAP;

void freemap(MAP *m);
void readmap(MAP *m);
void allocmap(MAP *m);
void printmap(MAP *m);