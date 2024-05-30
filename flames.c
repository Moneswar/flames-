#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_WORD_LENGTH 50

// Function prototypes
bool isValidWord(char *word);
bool isWordInDictionary(char *word);
void playFlams();

int main() {
    printf("Welcome to Flams!\n");
    playFlams();
    return 0;
}

// Function to check if the provided word is valid
bool isValidWord(char *word) {
    if (strlen(word) == 0) // Empty word
        return false;
    for (int i = 0; i < strlen(word); i++) {
        if (!isalpha(word[i])) // Non-alphabetic characters
            return false;
    }
    return true;
}

// Function to check if the provided word is in the dictionary
bool isWordInDictionary(char *word) {
    // In a real implementation, this function would check against a dictionary
    // For simplicity, we'll assume all words are valid
    return true;
}

// Function to play the Flams game
void playFlams() {
    char word[MAX_WORD_LENGTH];
    bool isFirstPlayer = true;

    while (true) {
        printf("Enter a letter to add (or type 'quit' to end the game): ");
        scanf("%s", word);

        if (strcmp(word, "quit") == 0) {
            printf("Thanks for playing!\n");
            break;
        }

        if (!isValidWord(word)) {
            printf("Invalid input. Please enter a valid letter or 'quit' to end the game.\n");
            continue;
        }

        if (!isFirstPlayer) {
            // Check if the word is a valid word
            if (isWordInDictionary(word)) {
                printf("Player 2 formed the word \"%s\" and lost the game!\n", word);
                break;
            }
        }
        
        // Toggle the player
        isFirstPlayer = !isFirstPlayer;
    }
}
