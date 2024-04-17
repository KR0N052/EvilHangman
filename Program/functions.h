#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include "structures.c"
#include "functions.c"
int listUpdate(word**);
void listReset(word*);
int randNumberOfLetters(word*, int);
void letterAmount(word*, int);
void matchingLettersSet(word*, char);
void indexesReset(int*);
void scoreboardWrite(char*, char*, int);
#endif // FUNCTIONS_H_INCLUDED
