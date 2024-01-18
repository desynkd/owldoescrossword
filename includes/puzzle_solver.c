#include <stdbool.h>
#include <stdlib.h>
#include "puzzle_solver.h"

void createRow(Line** row, int size)
{
    //INPUT: Pointer to array of struct, Size
    //PROCESS: Allocate required memory to global variable
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
    //INPUT: Pointer to array of struct, Size
    //PROCESS: Allocate required memory to global variable
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
    //INPUT: Pointer to array of struct, Size
    //PROCESS: Allocate required memory to global variable
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
    //INPUT: Pointer to struct, string
    //PROCESS: Allocate memory and copy string to struct member
    input->data = (char*)malloc(sizeof(char) * (strlen(userInput) + 1));
    strcpy(input->data, userInput);
}

void addRow(Line* row, char* input)
{
    //INPUT: Pointer to struct, string
    //PROCESS: Allocate memory and copy string to struct member, and assign size of string to other member
    row->size = strlen(input);
    row->col = (char*)malloc(sizeof(char) * (row->size + 1));
    strcpy(row->col, input);
}

// void initAval()
// {
//     //PROCESS: Recognize availble places in puzzle and assign pattern numbers
//     int size = blankSize;

//     for(int n=0; n<lineSize; n++)
//     {
//         for(int m=0; row[n].col[m] != '\0'; m++)
//         {
//             if(row[n].col[m]=='#')
//             {
//                 createAvalBlank(&avalBlank,++size);
//                 avalBlank[size-1].row = n;
//                 avalBlank[size-1].col = m;

//                 //identify pattern (N-E-S-W)
//                 avalBlank[size-1].aval = 0;
//                 //north
//                 if(n > 0)
//                 {
//                     if(row[n-1].col[m]=='#')
//                     {
//                         avalBlank[size-1].aval += 8;
//                     }
//                 }
//                 //east
//                 if(row[n].col[m+1]=='#')
//                 {
//                     avalBlank[size-1].aval += 4;
//                 }
//                 //south
//                 if(n < lineSize-1)
//                 {
//                     if(row[n+1].col[m]=='#')
//                     {
//                         avalBlank[size-1].aval += 2;
//                     }
//                 }
//                 //west
//                 if(m > 0)
//                 {
//                     if(row[n].col[m-1]=='#')
//                     {
//                         avalBlank[size-1].aval += 1;
//                     }
//                 }
//             }
//         }
//     }
//     blankSize = size;

//     #ifdef DEBUG1
//     for(int n=0; n<size; n++)
//     {
//         printf("DEBUG : col=%d | row=%d | aval=%d\n", 
//         avalBlank[n].row, avalBlank[n].col, avalBlank[n].aval);
//     }
//     #endif
// }

void initLetterPattern()
{
    //Backtracking algorithm?
}