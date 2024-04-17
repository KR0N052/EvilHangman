#ifndef STRUCTURES_H
#define STRUCTURES_H
#include <stdbool.h>

typedef struct word{
    char word[30];
    struct word* next;
    struct word* gameNext;
    bool inGame;
    int matchingLetters;
    int letters;
}word;

typedef struct scoreboard {
    char name[300];
    int steps;
    char finalWord[30];
    struct scoreboard* next;
    bool done;
}scoreboard;

typedef struct scoreboardInOrder {
struct scoreboard* record;
struct scoreboardInOrder* next;
}scoreboardInOrder;

#endif
