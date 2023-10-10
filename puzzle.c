#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define STRSIZE 100

typedef struct Lines{
    char* col;
    int size;
}Line;

typedef struct CrssWrdPlaces{
    int row;
    int col;
    int aval;
}CrssWrdPlace;

typedef struct Words{
    char* data;
}Word;

void createRow(Line** row, int size);
void createAvalBlank(CrssWrdPlace** avalBlank, int size);
void createWord(Word** input, int size);
void addWord(Word* input, char* userInput);
void addRow(Line* row, char* input);
void initAval();

Line* row = NULL;
CrssWrdPlace* avalBlank = NULL;
Word *inpWord;
int lineSize=0, blankSize=0, wordSize=0;

int main()
{
    int n;
    bool continueLoop = true;
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
            createRow(&row, ++lineSize);
            addRow(row+(lineSize-1), input);
        }

        #ifdef DEBUG1
        for(n=0; n<lineSize; n++)
        {
            printf("DEBUG : n=%d | %s\n", n, row[n].col);
        }
        #endif
    }

    //initalize crossword pattern
    initAval();

    //get words
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
            createWord(&inpWord, ++wordSize);
            addWord(inpWord+(wordSize-1), input);
        }

        #ifdef DEBUG1
        for(n=0; n<wordSize; n++)
        {
            printf("DEBUG : n=%d | %s\n", n, inpWord[n]);
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

void createAvalBlank(CrssWrdPlace** avalBlank, int size)
{
    if (*avalBlank == NULL)
    {
        *avalBlank = (CrssWrdPlace*)malloc(size * sizeof(CrssWrdPlace));
    }
    else
    {
        *avalBlank = (CrssWrdPlace*)realloc(*avalBlank, size * sizeof(CrssWrdPlace));
    }
}

void createWord(Word** input, int size)
{
    if (*input == NULL)
    {
        *input = (Word*)malloc(size * sizeof(Word));
    }
    else
    {
        *input = (Word*)realloc(*input, size * sizeof(Word));
    }
}

void addWord(Word* input, char* userInput)
{
    input->data = (char*)malloc(sizeof(char) * (strlen(userInput) + 1));
    strcpy(input->data, userInput);
}

void addRow(Line* row, char* input)
{
    row->size = strlen(input);
    row->col = (char*)malloc(sizeof(char) * (row->size + 1));
    strcpy(row->col, input);
}

void initAval()
{
    //calculate data of available spaces in struct
    int size = blankSize;

    for(int n=0; n<lineSize; n++)
    {
        for(int m=0; row[n].col[m] != '\0'; m++)
        {
            if(row[n].col[m]=='#')
            {
                createAvalBlank(&avalBlank,++size);
                avalBlank[size-1].row = n;
                avalBlank[size-1].col = m;

                //identify pattern (N-E-S-W)
                avalBlank[size-1].aval = 0;
                //north
                if(n > 0)
                {
                    if(row[n-1].col[m]=='#')
                    {
                        avalBlank[size-1].aval += 8;
                    }
                }
                //east
                if(row[n].col[m+1]=='#')
                {
                    avalBlank[size-1].aval += 4;
                }
                //south
                if(n < lineSize-1)
                {
                    if(row[n+1].col[m]=='#')
                    {
                        avalBlank[size-1].aval += 2;
                    }
                }
                //west
                if(m > 0)
                {
                    if(row[n].col[m-1]=='#')
                    {
                        avalBlank[size-1].aval += 1;
                    }
                }
            }
        }
    }
    blankSize = size;

    #ifdef DEBUG1
    for(int n=0; n<size; n++)
    {
        printf("DEBUG : col=%d | row=%d | aval=%d\n", 
        avalBlank[n].row, avalBlank[n].col, avalBlank[n].aval);
    }
    #endif
}