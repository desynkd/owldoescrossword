#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "includes/puzzle_solver.h"

// use backtracking algorithm

int main()
{
    int n;
    int **board = NULL;
    int width=0, height=0;
    char input[STRSIZE];

    //get crossword board
    while(1)
    {
        fgets(input, sizeof input, stdin);
        if(input[0]=='\n')
        {
            break;
        }
        else
        {
            input[strcspn(input, "\n")] = 0;
            width = strlen(input);
            updateBoard(&board, input, (++height));
        }
    }

    drawBoard(board, height, width);


    freeBoard(board, height);
    return 0;
}