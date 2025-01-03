#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool is_valid_key(string key);
char get_substitution_cipher(string key, char plaintext);

int main(int argc, string argv[])
{
    // Check if user inputs correct number of command line args
    if (argc != 2)
    {
        // Print error message
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Get the key as a command line arg
    string key = argv[argc - 1];

    // Check if the key is valid or not
    if (is_valid_key(key))
    {
        // Prompt the user for a plaintext
        string plaintext = get_string("plaintext: ");
        printf("ciphertext: ");

        // Print each character after passing each char to substitution cipher
        for (int i = 0; i < strlen(plaintext); i++)
        {
            printf("%c", get_substitution_cipher(key, plaintext[i]));
        }
        printf("\n");
        return 0;
    }
    else
    {
        // Print error message
        printf("Key must contain 26 characters.\n");
        return 1;
    }
}

bool is_valid_key(string key)
{
    // Invalid key if it doesnt contain 26 chars
    if (strlen(key) != 26)
    {
        return false;
    }

    bool is_present[26];
    for (int i = 0; i < strlen(key); i++)
    {
        // Check if each char is a alphabet
        if (isalpha(key[i]) != 0)
        {
            // Check if each char is not repeated in the key
            if (is_present[tolower(key[i]) - 'a'])
            {
                return false;
            }
            else
            {
                is_present[tolower(key[i]) - 'a'] = true;
            }
        }
        else
        {
            return false;
        }
    }

    return true;
}

char get_substitution_cipher(string key, char plaintext)
{
    // Check if the char is an alphabet
    if (isalpha(plaintext) != 0)
    {
        // Substitution cipher
        if (isupper(plaintext) != 0)
        {
            return toupper(key[plaintext - 'A']);
        }
        else
        {
            return tolower(key[plaintext - 'a']);
        }
    }
    // Non alphabetic chars are returned as it is
    else
    {
        return plaintext;
    }
}
