void freemap();
void readmap();
void allocmap();
void printmap();
int endgame();
void move(char direction);

struct map
{
	char **matrix;
	int lines;
	int columns;
};

typedef struct map MAP;