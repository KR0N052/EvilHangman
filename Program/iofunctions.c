#include <stdio.h>
#include "structures.c"



void newPage(){
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

void wordListPrint(word* absFirst){
    word* moving = absFirst;
    while (moving->next != NULL){
        printf("%s - %d\n", moving->word, moving->matchingLetters);
            moving = moving->next;
    }
}

void wordInGamePrint(word* first){
    word* moving = first;
    while (moving->gameNext != NULL){
         printf("%s - %d\n", moving->word, moving->matchingLetters);
            moving = moving->gameNext;
    }
}

void scoreboardListPrint(scoreboard* first){
    scoreboard* moving = first;
    while (moving->next != NULL){
        printf("%s, %s, %d\n", moving->name, moving->finalWord, moving->steps);
        moving = moving->next;
    }
}

void scoreboardInOrderPrint(scoreboardInOrder* first){
    scoreboardInOrder* moving = first;
    while(moving->next != NULL){
        printf("%s, %s, %d\n", moving->record->name, moving->record->finalWord, moving->record->steps);
        moving = moving->next;
    }
}


void helpFunc(){
printf("Here are the commands you can use, and what they are doing:\n    Help - listing these commands\n    New_game - creating a new game\n    Give_up - giving up the current game\n    Scoreboard - listing the scoreboard\n    Quit - quittin the program\n\n");
};
