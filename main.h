#define UP 'w'
#define DOWN 's'
#define RIGHT 'd'
#define LEFT 'a'

int endgame();
void move(char direction);
int validinput(char userinput);
void ghosts();
int wheredoestheghostgo(int xcurrent, int ycurrent, int *xdestiny, int *ydestiny);
