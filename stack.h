#define MAX_SIZE 100

typedef struct {
    int x;
    int y;
} Position;

// Structure to represent the stack
typedef struct {
    Position items[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *stack);
void push(Stack *stack, Position pos);
void pop(Stack *stack);
void peek(Stack *stack);
int isEmpty(Stack *stack);
int isFull(Stack *stack);
void clear(Stack *stack);
