#include <stdbool.h>

#ifndef PUZZLE_SOLVER
#define PUZZLE_SOLVER

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
void initLetterPattern();

#endif