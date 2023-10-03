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

void createRow(Line* row, int size);
void addRow(Line* row, char* input);

int main()
{
    Line* row = NULL;
    int size=0;
    bool continueLoop = true;
    char* input;

    while(0)
    {
        scanf("%s", input);
        
        //take string as input and if its only a new line then stop?
        if(input=="\n")
        {
            break;
        }
        else
        {
            createRow(row, ++size);
            addRow(row+(size-1), input);
        }
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

void addRow(Line* row, char* input)
{
    int strLen = strlen(input);
    row->pos = (char*)malloc(sizeof(char)*strLen+1);
    strcpy(row->pos, input); 
}