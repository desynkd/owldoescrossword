#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define STRSIZE 100

typedef struct Lines{
    char* col;
    //do i store the no of hashtags here to see if a
    //word can be fit horizontally in said line
}Line;

void createRow(Line** row, int size);
void addRow(Line* row, char* input);

int main()
{
    Line* row = NULL;
    int size=0, n;
    bool continueLoop = true;
    char input[STRSIZE];

    while(1)
    {
        scanf(" %s", input);
        //take string as input and if its only a new line then stop?
        //use string length?
        if(strlen(input)==0)
        {
            break;
        }
        else
        {
            createRow(&row, size);
            addRow(row+(size-1), input);
        }

        #ifdef DEBUG1
        for(n=0; n<size; n++)
        {
            printf("DEBUG : n=%d | %s\n", n, row[n].col);
        }
        #endif
    }

    return 0;
}

void createRow(Line** row, int size)
{
    if (*row == NULL)
    {
        *row = (Line*)malloc(size * sizeof(Line));
    }
    else
    {
        *row = (Line*)realloc(*row, size * sizeof(Line));
    }
}

void addRow(Line* row, char* input)
{
    int strLen = strlen(input);
    row->col = (char*)malloc(sizeof(char) * (strLen + 1));
    strcpy(row->col, input);
}