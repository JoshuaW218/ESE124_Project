#include <stdio.h>
#include "stack.h"

int moveF(Position *currentPosition)
{
    currentPosition->y++;
    printf("Moved forward to (%d, %d)", currentPosition->x, currentPosition->y);
}
