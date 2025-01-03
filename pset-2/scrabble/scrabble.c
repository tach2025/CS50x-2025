#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Prototype of get_score
int get_score(string word);

int main(void)
{
    // Prompt user for two words
    string first_word = get_string("Player 1: ");
    string second_word = get_string("Player 2: ");

    // Compute the score for the two words
    int score_one = get_score(first_word);
    int score_two = get_score(second_word);

    // Print the winner
    if (score_one > score_two)
    {
        printf("Player 1 wins!\n");
    }
    else if (score_one < score_two)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

    return 0;
}

int get_score(string word)
{
    int score = 0;
    int SCORE[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    // Iterate through all character of the word
    for (int i = 0; i < strlen(word); i++)
    {
        // If the character is alphabetical then update score
        if (isalpha(word[i]) != 0)
        {
            // Get score for each character
            score += SCORE[tolower(word[i]) - 'a'];
        }
    }

    return score;
}
