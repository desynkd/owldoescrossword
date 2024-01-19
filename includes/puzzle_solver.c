#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "puzzle_solver.h"
#include <string.h>


void updateBoard(int ***board, char* strInput, int height)
{
    int **matrix = *board;
    int width = strlen(strInput);
    int n, cur;

    if (matrix == NULL)
    {
        // if board has not initialised
        matrix = (int**)malloc(sizeof(int**) * 1);
        matrix[0] = (int*)malloc(sizeof(int*) * width);
        cur = 0;
    }
    else
    {
        // if initialised, resize the board as needed
        matrix = (int**)realloc(matrix, sizeof(int**) * height);
        cur = height - 1;
        matrix[cur] = (int*)malloc(sizeof(int*) * width);
    }

    // manipulate values as needed in new row
    for (n = 0; n < width; n++)
    {
        if ( strInput[n] == '*' )
        {
            matrix[cur][n] = -1;
        }
        else if ( strInput[n] == '#' )
        {
            matrix[cur][n] = 0;
        }
    }
}

void drawBoard(int** board, int height, int width)
{
    for (int n = 0; n < height; n++ )
    {
        for (int m = 0; m < width; m++)
        {
            printf(" %d ", board[n][m]);
        }
        printf("\n");
    }
}

void freeBoard(int** board, int height) 
{
    for (int i = 0; i < height; i++) 
    {
        free(board[i]);
    }
    free(board);
}