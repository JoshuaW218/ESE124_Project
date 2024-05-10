#include "stack.h"
#define MAX_ROWS 100
#define MAX_COLS 100

void mark(Position *currentPosition);
int moveF(Position *currentPosition);
int moveB(Position *currentPosition);
int moveL(Position *currentPosition);
int moveR(Position *currentPosition);
int CWL(Position *currentPostion);
int CWR(Position *currentPosition);
int CWF(Position *currentPosition);
int CWB(Position *currentPosition);
int CWL1(Position *currentPostion);
int CWR1(Position *currentPosition);
int CWF1(Position *currentPosition);
int CWB1(Position *currentPosition);
void BJPI(Position *currentPosition, int(*f) (Position));
void CJPI(Position *currentPosition, int(*f)(Position));
void backTrack(Stack *s);
void repeatActions(void(*p)(Position), int t);
void readMaze(int *rows, int *cols, const char *filename);