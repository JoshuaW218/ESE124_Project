#include <stdio.h>
#include "stack.h"

void backTrack(Stack *s)
{
    Position prevPosition = pop(s);
    printf("BackTracked back to (%d, %d)", prevPosition.x, prevPosition.y);
}


