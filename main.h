#ifndef _MAIN_H_
#define _MAIN_H_

#define UP 'w'
#define DOWN 's'
#define RIGHT 'd'
#define LEFT 'a'
#define BOMB 'b'

int endgame();
void move(char direction);
int validinput(char userinput);
void ghosts();
int wheredoestheghostgo(int xcurrent, int ycurrent, int *xdestiny, int *ydestiny);
void explodepill();
void explodepill2(int x, int y, int sumx, int sumy, int count);

#endif
