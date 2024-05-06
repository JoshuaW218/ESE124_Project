#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 100

int main() {
    char maze[MAX_ROWS][MAX_COLS];
    int rows, cols;

    readMaze(maze, &rows, &cols, "maze.txt");

    // Print the maze
    printf("Maze:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }

    return 0;
}




// Function to read the maze from the input file
void readMaze(char maze[MAX_ROWS][MAX_COLS], int *rows, int *cols, const char *filename) {
    FILE *file;
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
}