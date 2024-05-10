//Tim Cheng, Joshua Woo, Timmy Tan

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_ROWS 100
#define MAX_COLS 100

char maze[MAX_ROWS][MAX_COLS];
int rows, cols;


int mark(Position *currentPosition)
{
    printf("Current position is at (%d, %d)", currentPosition->x, currentPosition->y);
    return 0;
}

int moveF(Position *currentPosition)
{
    currentPosition->x++;
    printf("Moved forward to (%d, %d)", currentPosition->x, currentPosition->y);
    return 0;
}

int moveB(Position *currentPosition)
{
    currentPosition->x--;
    printf("Moved forward to (%d, %d)", currentPosition->x, currentPosition->y);
    return 0;
}

int moveL(Position *currentPosition)
{
    currentPosition->y--;
    printf("Moved forward to (%d, %d)", currentPosition->x, currentPosition->y);
    return 0;
}

int moveR(Position *currentPosition)
{
    currentPosition->y++;
    printf("Moved forward to (%d, %d)", currentPosition->x, currentPosition->y);
    return 0;
}

int CWL(Position *currentPosition)
{
    int x = 0;
    readMaze(&rows, &cols, "maze.txt");
    while (maze[(*currentPosition).x][(*currentPosition).y-x] != '*')
    {
        x++;
    }
    return x;
}

int CWR(Position *currentPosition)
{
    int x = 0;
    readMaze(&rows, &cols, "maze.txt");
    while (maze[(*currentPosition).x][(*currentPosition).y+x] != '*')
    {
        x++;
    }
    return x;
}

int CWF(Position *currentPosition)
{
    int x = 0;
    readMaze(&rows, &cols, "maze.txt");
    while (maze[(*currentPosition).x+x][(*currentPosition).y] != '*')
    {
        x++;
    }
    return x;
}

int CWB(Position *currentPosition)
{
    int x = 0;
    readMaze(&rows, &cols, "maze.txt");
    while (maze[(*currentPosition).x-x][(*currentPosition).y] != '*')
    {
        x++;
    }
    return x;
}

int CWL1(Position *currentPosition)
{
    int x = 0;
    readMaze(&rows, &cols, "maze.txt");
    if (maze[(*currentPosition).x][(*currentPosition).y-x] != '*')
    {
        return 1;
    }
    return 0;
}

int CWR1(Position *currentPosition)
{
    int x = 0;
    readMaze(&rows, &cols, "maze.txt");
    if (maze[(*currentPosition).x][(*currentPosition).y+x] != '*')
    {
        return 1;
    }
    return 0;
}

int CWF1(Position *currentPosition)
{
    int x = 0;
    readMaze(&rows, &cols, "maze.txt");
    if (maze[(*currentPosition).x+x][(*currentPosition).y] != '*')
    {
        return 1;
    }
    return 0;
}

int CWB1(Position *currentPosition)
{
    int x = 0;
    readMaze(&rows, &cols, "maze.txt");
    if (maze[(*currentPosition).x-x][(*currentPosition).y] != '*')
    {
        return 1;
    }
    return 0;
}

void BJPI(Position *currentPosition, int (*f) (Position))
{
    int x = 0;
    if (f == &CWF)
    {
        while(CWF)
            currentPosition->x+CWF(currentPosition);
        return;
    }
    else if (f == &CWB)
    {
        while(CWB)
            currentPosition->x-CWB(currentPosition);
        return;
    }
    else if (f == &CWL)
    {
        while(CWL)
            currentPosition->y-CWL(currentPosition);
        return;
    }
    else if (f == &CWR)
    {
        while(CWR)
            currentPosition->y+CWR(currentPosition);
        return;
    }
}

int CJPI(Position *currentPosition, int (*f)(Position))
{
    if (f == &CWF)
    {
        currentPosition->x+1;
        return;
    }
    else if (f == &CWB)
    {
        currentPosition->x-1;
        return;
    }
    else if (f == &CWL)
    {
        currentPosition->y-1;
        return;
    }
    else if (f == &CWR)
    {
        currentPosition->y+1;
        return;
    }
}

void backTrack(Stack *s)
{
    Position prevPosition = pop(s);
    printf("BackTracked back to (%d, %d)", prevPosition.x, prevPosition.y);
}

void repeatActions(void(*p)(Position), int t)
{
    Position currentPosition;
    for (int x = 0; x < t; x++)
    {
        p(currentPosition);
    }
    printf("Repeated actions %d amount of times", t);
} 

// Function to read the maze from the input file
char readMaze(int *rows, int *cols, const char *filename) {
    FILE *file;
    char maze[MAX_ROWS][MAX_COLS];
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.");
        exit(0);
    }

    *rows = 0;
    *cols = 0;
    char ch;

    // Read characters from the file and store them in the 2D array
    while ((ch = fgetc(file)) != EOF && *rows < MAX_ROWS && *cols < MAX_COLS) {
        if (ch == '\n') {
            *rows += 1;
            *cols = 0;
        } else {
            maze[*rows][*cols] = ch;
            *cols += 1;
        }
    }

    fclose(file);

    return maze[*rows][*cols];
}








