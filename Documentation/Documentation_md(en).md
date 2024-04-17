<span style="font-family:Times new roman;font-size:1.2em">

## Author:

Melcher Bálint

melcherbalint@gmail.com

## Task:
Evil Hangman **

It seems like a typical hangman game: the computer thinks of a word, and the user tries to guess it by guessing letters. The trickery lies in the fact that the computer does not commit to any single word. Based on the users guesses, it always narrows down the set of possible words in a way that gives the least help to the user. For example, the user has gotten this far: abo__, and is thinking of the word "about". So they guess a 'u', and the computer says they lost because the word was "above"... Meanwhile, it didn't actually think of any word at all.

## Introduction:
This program implements a simple guessing game using the C programming language. During the game, the user tries to guess a randomly selected word.

## System Requirements:
To run the program, the following requirements must be met:

-	C compiler (e.g., GCC)
-	Text file containing the words (words.txt)
## Installation and Execution:

1.	Download and compile the program's source code with a C compiler.
2.	Ensure that the words.txt file is present alongside the executable program.
3.	Launch the program.
## Usage:
After starting the program, the user has the option to issue various commands to control the game and guess the word. The possible commands are as follows:

-	*quit:* Exit the game.
-	*help:* Display help.
-	*new_game:* Start a new game.
-	*give_up:* Give up, display the word, and start a new game.
-	*scoreboard:* View the top scores.

At the beginning of the game, the program loads the words from the appropriate file into a linked list and selects one of them completely randomly to determine the length of the "solution" word.

When the user guesses a letter, the program examines the words still in play and checks which one(s) have the fewest occurrences of the guessed letter. If there is still a word in play that does not contain the guessed letter, the program prints that the guess did not hit, and excludes from the words in play those that contain the letter. If we manage to guess one that letter appears in all the remaining words, then the program selects the words that occur the least number of times and chooses one of them randomly, then writes the guessed letter into the solution in the appropriate place(s). Then it excludes from the game the words that do not match (those that have more of the letter and those that do not have the guessed letter where it is in the solution). The game ends when only one word is left in play, and the player has guessed all of its letters.

## Data Structures:
The program uses a total of three types of newly defined data structures, one for the linked list storing words and two for reading and writing elements of the scoreboard.

I used two for the scoreboard because it was the most obvious way to be able to print the elements of the scoreboard in order. One linked list, scoreBoard, stores the data read from the file itself, in the order of reading, and each element of the other linked list, scoreBoardInOrder, stores a pointer that points to the next scoreboard element in order.
 

![picture](chart(en).png)

## Debugmalloc.h

Next to the project, there is a file called debugmalloc.h, which I mainly used during writing and debugging the program. As its name suggests, its primary use is to check for memory leaks and detects and reports buffer overflows after the program has executed. There are no memory leaks or buffer overflows in the program, as can be seen after it has run.


## Files:
The program uses various files, each providing unique functionalities:

- iofunctions.h: Declarations of input and output functions.
- structures.c: Definitions of data structures necessary for the game.
- functions.h: Declarations of various utility functions.
- debugmalloc.h: Memory tracking functions.

</span>