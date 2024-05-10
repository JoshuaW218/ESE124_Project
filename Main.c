//Tim Cheng, Joshua Woo, Timmy Tan

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "functions.h"
#define MAX_ROWS 100
#define MAX_COLS 100
Position *position;
Stack *stack;

void navigateMaze(char maze[MAX_ROWS][MAX_COLS], Position start, Position end) {
    Stack stack;
    initialize(&stack);
    push(&stack, start);

    int visited[MAX_ROWS][MAX_COLS] = {0}; // Array to mark visited cells

    while (!isEmpty(&stack)) {
        Position current = pop(&stack);
        int x = current.x;
        int y = current.y;

        if (x == end.x && y == end.y) {
            printf("Path found!\n");
            return;
        }

        if (isValid(x, y) && maze[x][y] && !visited[x][y]) {
            visited[x][y] = 1;

            // Push adjacent cells onto the stack
            push(&stack, (Position){x + 1, y}); // Down
            push(&stack, (Position){x - 1, y}); // Up
            push(&stack, (Position){x, y + 1}); // Right
            push(&stack, (Position){x, y - 1}); // Left
        }
    }

    printf("No path found!\n");
}
    
int main() {
    int rows, ys;
    char maze[MAX_ROWS][MAX_COLS] = readmaze(&rows, &ys, "maze.txt");
    initialize(&stack);
    int mx = rows, my = ys; //maze dimensions
    int sx, sy;
    int ex, ey;

    int x = sx, y= sy;

    while (isEmpty(stack)) 
    {
        if (CWR1(position)){
            BJPI(position,CWR(position));
        }
        else if (CWF1(position))
        {
            BJPI(position,CWF(position));
        }
        else if (CWL1(position))
        {
            BJPI(position,CWL(position));
        }
        else if (CWB1(position))
        {
            BJPI(position,CWB(position));
        }
    }
    printf("Maze solved!\n");
    return 0;
}

