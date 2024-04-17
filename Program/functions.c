
//setting up the inGame chained list, and counting the items
int listUpdate(word** first){
    int items = 0;
    word *moving1, *moving2;
    moving1 = *first;

    while(!moving1->inGame && moving1->gameNext != NULL){
        moving1 = moving1->gameNext;
    }
    moving2 = moving1;
    *first = moving2;
    while (moving1->gameNext != NULL){
        moving1 = moving1->gameNext;
        if(moving1->inGame){
            moving2->gameNext = moving1;
            moving2 = moving1;
            items++;
        }
    }
    moving2->gameNext = NULL;
    return items;
}

void listReset(word* absFirst){
    word* moving = absFirst;
    while(moving->next != NULL){
        moving->gameNext = moving->next;
        moving->inGame = 1;
        moving->matchingLetters = 0;
        moving = moving->next;
    }
}


int randNumberOfLetters(word* first, int items){
    int random = rand() % items;
    word* moving = first;
    for(int i = 0;i < random; i++){
        moving = moving->next;
    }
    return strlen(moving->word);
}

void letterAmount(word* first, int number){
    word* moving = first;
    while (moving->next != NULL){
        if(strlen(moving->word) != number)
            moving->inGame = 0;
        moving = moving->next;
    }
}

void matchingLettersSet(word* first, char c){
    word* moving = first;
    int temp;
    while (moving->gameNext != NULL){
        temp = 0;
        for(int i = 0; moving->word[i] != '\0'; i++){
            if(moving->word[i] == c)temp++;
        }
        moving->matchingLetters = temp;
        moving = moving->gameNext;
    }
}

void indexesReset(int* indexes){
for(int i = 0; i < 20; i++){
    indexes[i] = -1;
}
}

void scoreboardWrite(char* name, char* word, int steps){
FILE* fScoreboardw = fopen("scoreboard.txt", "a");
if(fScoreboardw == NULL)return -1;
fprintf(fScoreboardw, "%s - %s - %d\n", name, word, steps);
fclose(fScoreboardw);
}


