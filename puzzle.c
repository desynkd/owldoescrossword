#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define STRSIZE 100

typedef struct Lines{
    char* pos;
    //do i store the no of hashtags here to see if a
    //word can be fit horizontally in said line
}Line;

int main()
{
    Line* row = NULL;
    bool continueLoop = true;
    char* input;

    while(continueLoop)
    {
        scanf("%c", input);
        //take string as input and if its only a new line then stop?
    }

    return 0;
}

void createRow(Line* row, int size)
{
    if(row==NULL)
    {
        row = (Line*)malloc(size*sizeof(Line));
    }
    else
    {
        row = (Line*)realloc(row, size*sizeof(Line));
    }
}