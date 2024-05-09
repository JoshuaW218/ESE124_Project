#include <stdio.h>
#include "stack.h"

int moveF(Position *currentPosition)
{
    currentPosition->x--;
    printf("Moved forward to (%d, %d)", currentPosition->x, currentPosition->y);
}
