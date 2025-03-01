#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform a single round of the game and return the winner
int gamePerform(char person1, char person2) {
    if (person1 == person2) {
        return 0; // It's a tie
    }
    if ((person1 == 's' && person2 == 'p') || 
        (person1 == 'p' && person2 == 'r') || 
        (person1 == 'r' && person2 == 's')) {
        return 1; // Person 1 wins
    }
    return 2; // Person 2 wins
}

int main() {
    char scissor = 's';
    char rock = 'r';
    char paper = 'p';
    char person1, person2;
    int n;
    
    printf("Some important points to note before the game starts:\n");
    printf("Denotation of tossing Scissors = %c.\nDenotation of tossing Rock = %c.\nDenotation of tossing Paper = %c.\n", scissor, rock, paper);

    // Input for person 1 and person 2
    printf("Enter person1's choice (s for Scissors, r for Rock, p for Paper): ");
    scanf(" %c", &person1); // Notice the space before %c to capture newline characters

    printf("Enter person2's choice (s for Scissors, r for Rock, p for Paper): ");
    scanf(" %c", &person2);

    printf("Enter the number of rounds to play: ");
    scanf("%d", &n);

    int person1Wins = 0, person2Wins = 0, ties = 0;

    // Play the game for 'n' rounds
    for (int i = 0; i < n; i++) {
        int result = gamePerform(person1, person2);
        if (result == 1) {
            person1Wins++;
            printf("Round %d: Person 1 wins!\n", i + 1);
        } else if (result == 2) {
            person2Wins++;
            printf("Round %d: Person 2 wins!\n", i + 1);
        } else {
            ties++;
            printf("Round %d: It's a tie!\n", i + 1);
        }
    }

    // Display the final winner based on the number of wins
    if (person1Wins > person2Wins) {
        printf("\nPerson 1 wins the game with %d wins!\n", person1Wins);
    } else if (person2Wins > person1Wins) {
        printf("\nPerson 2 wins the game with %d wins!\n", person2Wins);
    } else {
        printf("\nIt's a tie! Both players won %d rounds each.\n", person1Wins);
    }

    return 0;
}