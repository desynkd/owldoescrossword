#include <stdbool.h>

#ifndef PUZZLE_SOLVER_H
#define PUZZLE_SOLVER_H

#define STRSIZE 100

void updateBoard(int ***board, char* strInput, int height);
void drawBoard(int** board, int height, int width);
void freeBoard(int** board, int height);

#endif