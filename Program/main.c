#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "iofunctions.h"
#include "structures.c"
#include "debugmalloc.h"
#include "functions.h"



int main()
{
    int items = 0;
    scoreboard *sbFirst, *sbMoving, *sbBehind;              //sb = ScoreBoard
    scoreboardInOrder *sbioFirst, *sbioMoving, *sbioBehind;
    char tempWord[300], tempName[300];
    int tempSteps;
    word *absoluteFirst, *moving, *first, *behind;
    srand(time(0));
    int random = 0;
    int indexes[20];
    int steps = 0;
    bool guess = 0;
    int min;

//reading the words from words.txt
    FILE* fPointer = fopen("words.txt", "r");
    if(fPointer == NULL){return -1;}

    first = (word*)malloc(sizeof(word));
    moving = first;
    while (!feof(fPointer)){
        moving->inGame = 1;
        moving->matchingLetters = 0;
        fscanf(fPointer, "%s", moving->word);
        moving->letters = strlen(moving->word);
        moving->next = (word*)malloc(sizeof(word));
        if (moving->next == NULL) printf("problem");
        moving->gameNext = moving->next;
        moving = moving->next;
        items++;
    } moving->next = NULL;
moving->gameNext = moving->next;


    absoluteFirst = first;
    int numberOfLetters = randNumberOfLetters(absoluteFirst, items);

//setting up the solution variable
    char* solution = (char*) malloc(sizeof(char) * (numberOfLetters+1));
    for(int i = 0; i<numberOfLetters; i++){
        solution[i] = '_';
    }solution[numberOfLetters] = '\0';

//taking out the words, that doesn't contain the correct amount of letters
    letterAmount(absoluteFirst, numberOfLetters);
    items = listUpdate(&first);
    bool done = 0;
    newPage();
    helpFunc();

//begins the interactive part-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	while(!done){
        char newGuess[300];
        if(!guess){
        printf("%s \nYour word is %d letters long.\nPlease guess a letter:", solution, numberOfLetters);
        scanf("%s", newGuess);
        }
        guess = 0;
//we see if the player wrote a command or a guess
//Quit
        if(strcmp(newGuess, "quit") == 0){
            done = 1;

//Help
        }else if(strcmp(newGuess, "help") == 0){
            newPage();
            helpFunc();

//New_game
       }else if(strcmp(newGuess, "new_game") == 0) {
            newPage();

            //every word is in game again
            listReset(absoluteFirst);

            //creating a new "random word"
            numberOfLetters = randNumberOfLetters(absoluteFirst, items);

            //setting up the solution variable
            free(solution);
            solution = (char*) malloc(sizeof(char) * (numberOfLetters+1));
            for(int i = 0; i<numberOfLetters; i++){
                solution[i] = '_';
            }solution[numberOfLetters] = '\0';

            //taking out the words, that doesn't contain the correct amount of letters
            letterAmount(absoluteFirst, numberOfLetters);
            items = listUpdate(&first);

            steps = 0;

//Give_up
        }else if(strcmp(newGuess, "give_up") == 0){
            printf("\nAre you sure?");
            scanf("%s", newGuess);
            if(strcmp(newGuess, "yes") == 0){
                printf("Your word was: %s\n\n", first->word);
                            //every word is in game again
                listReset(absoluteFirst);

                //creating a new "random word"
                numberOfLetters = randNumberOfLetters(absoluteFirst, items);

                //setting up the solution variable
                free(solution);
                solution = (char*) malloc(sizeof(char) * (numberOfLetters+1));
                for(int i = 0; i<numberOfLetters; i++){
                    solution[i] = '_';
                }solution[numberOfLetters] = '\0';

                //taking out the words, that doesn't contain the correct amount of letters
                letterAmount(absoluteFirst, numberOfLetters);
                items = listUpdate(&first);
            }

 //Scoreboard
        }else if(strcmp(newGuess, "scoreboard") == 0) {
            //opening the file
            FILE* fScoreboardr = fopen("scoreboard.txt", "r");
            if(fScoreboardr == NULL) printf("scoreboard_error");


            //reading the records
            sbFirst = (scoreboard*) malloc(sizeof(scoreboard));
            if(sbFirst == NULL) printf("scoreboard_error");


            sbioFirst = (scoreboardInOrder*) malloc(sizeof(scoreboardInOrder));
            if(sbioFirst == NULL) printf("scoreboard_error");

            //scanning the scoreboard records from scoreboard.txt
            sbioMoving = sbioFirst;
            sbMoving = sbFirst;
            while (!feof(fScoreboardr)){
                fscanf(fScoreboardr, "%s - %s - %d\n", sbMoving->name, sbMoving->finalWord, &sbMoving->steps);
                sbMoving->done = 1;
                sbioMoving->next = (scoreboardInOrder*) malloc(sizeof(scoreboardInOrder));
                if(sbioMoving->next == NULL) printf("scoreboard_error");
                sbMoving->next = (scoreboard*)malloc(sizeof(scoreboard));
                if (sbMoving->next == NULL) printf("scoreboard_error");
                sbioMoving = sbioMoving->next;
                sbMoving = sbMoving->next;
            }
            sbMoving->next = NULL;
            sbioMoving->next = NULL;

            //setting up the scoreboardInOrder chained list, so it contains pointers to the scoreboard records in the correct order
            sbioMoving = sbioFirst;
            while(sbioMoving->next != NULL){
                int min = 999;
                scoreboard* temp;
                sbMoving = sbFirst;
                while(sbMoving->next != NULL){
                    if(sbMoving->steps < min && sbMoving->done){
                        min = sbMoving->steps;
                        temp = sbMoving;
                    }
                    sbMoving = sbMoving->next;
                }
                sbioMoving->record = temp;
                sbioMoving->record->done = 0;
                sbioMoving = sbioMoving->next;
            }



            //writing out the records
            printf("\n\n\n\nThe Scoreboard:\n");
            scoreboardInOrderPrint(sbioFirst);
            printf("\n\n\n\n");



            //freeing the memory
            sbioMoving = sbioFirst;
            while (sbioMoving->next != NULL){
                sbioBehind = sbioMoving;
                sbioMoving = sbioMoving->next;
                free(sbioBehind);
            }free(sbioMoving);

            sbMoving = sbFirst;
            while (sbMoving->next != NULL){
                sbBehind = sbMoving;
                sbMoving = sbMoving->next;
                free(sbBehind);
            }free(sbMoving);
            fclose(fScoreboardr);
//Guess
        }else {
            matchingLettersSet(first, newGuess[0]);
            steps++;
            min = 30;

            //finding out the minimum amount of letters
            moving = first;
            while(moving->gameNext != NULL){
                if(moving->matchingLetters < min)min = moving->matchingLetters;
                moving = moving->gameNext;
            }

            //if the word has more matching letters than the minimum it is out
            moving = first;
            while(moving->gameNext != NULL){
                if(moving->matchingLetters != min) moving->inGame = 0;
                moving = moving->gameNext;
            }
            items = listUpdate(&first);

            if(min > 0){
                //choosing a random word that has the minimum amount of letters
                moving = first;

                random = rand() % items;
                for(int i = 0; i < random; i++){
                    moving = moving->gameNext;
                }

                //saving the positions in which the randomly chosen word has the correct letter
                int j = 0;
                indexesReset(indexes);
                for(int i = 0;moving->word[i] != '\0'; i++){
                    if(moving->word[i] == newGuess[0]) {
                        indexes[j] = i;
                        j++;
                    }
                }

                //writing the figured out letters into the solution
                for(int i = 0; indexes[i] != -1;i++){
                    solution[indexes[i]] = newGuess[0];
                }


                //taking out of the game the words that doesn't have the right letter in the right places
                moving = first;
                while(moving->gameNext != NULL){
                    for(int i = 0; i < min; i++){
                        if(moving->word[indexes[i]] != newGuess[0]) moving->inGame = 0;
                    }
                    moving = moving->gameNext;
                }
                items = listUpdate(&first);
                printf("There is %d '%c' in the word\n\n\n", min, newGuess[0]);

                //testing if the whole word is figured out
                bool win = 1;
                for(int i = 0;i<=30;i++){
                    if(solution[i] == '_')win = 0;
                }

                //if the word is figured out, write the game with the given name onto the scoreboard
                if(win){
                    printf("%s\nCongratulations, you won the game!!\nYou used %d steps\nPlease enter a name:", solution, steps);
                    scanf("%s", tempName);
                    scoreboardWrite(tempName, solution, steps);
                    printf("Do you want to continue playing?\n");
                    scanf("%s", newGuess);
                    if(strcmp(newGuess, "yes") != 0){
                        done = 1;
                    }else{
                        printf("\n\n\n");
                        strcpy(newGuess, "new_game");
                        guess = 1;
                    }
                }

            }else printf("There is no '%c' in the word\n\n\n", newGuess[0]);


        }//end of if else...
	}//end of while



//freeing the memory
moving = absoluteFirst;
while(moving->next != NULL){
    behind = moving;
    moving = moving->next;
    free(behind);
}free(moving);






free(solution);
fclose(fPointer);

    return 0;
}
