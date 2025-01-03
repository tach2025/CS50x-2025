#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int get_cl_index(string text);
int get_num_letters(string text);
int get_num_words(string text);
int get_num_sentences(string text);

int main(void)
{
    // Get text from the user
    string text = get_string("Text: ");

    // Get the Coleman-Liau index
    int score = get_cl_index(text);

    // Print the readability score
    if (score < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (score >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", score);
    }
    return 0;
}

int get_cl_index(string text)
{
    // Get the number of letters
    float num_letters = (float) get_num_letters(text);
    // Get the number of sentences
    float num_sentences = (float) get_num_sentences(text);
    // Get the number of words
    float num_words = (float) get_num_words(text);

    float L = 100 * num_letters / num_words;
    float S = 100 * num_sentences / num_words;

    int score = round(0.0588 * L - 0.296 * S - 15.8);

    return score;
}

int get_num_letters(string text)
{
    int num_letters = 0;
    // Iterate through the entire text
    for (int i = 0; i < strlen(text); i++)
    {
        // If the character is alphabetical, update num_letters
        if (isalpha(text[i]) != 0)
        {
            num_letters++;
        }
    }
    return num_letters;
}

int get_num_words(string text)
{
    int num_words = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        // Words are seperated by blank space
        if (text[i] == ' ')
        {
            num_words++;
        }
    }

    // The last character of a text is usually not a space, hence num_words is incremented
    num_words++;
    return num_words;
}

int get_num_sentences(string text)
{
    int num_sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        // Sentences end with either '.', '!' or '?'
        if ((text[i] == '.') || (text[i] == '!') || (text[i] == '?'))
        {
            num_sentences++;
        }
    }
    return num_sentences;
}
