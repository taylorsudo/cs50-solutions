#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

float count_letters(string text);
float count_words(string text);
float count_sentences(string text);

int main(void)
{
    // Prompt user for string of text
    string text = get_string("Text: ");

    // Get number of letters
    float letters = count_letters(text);

    // Get number of words
    float words = count_words(text);

    // Get number of sentences
    float sentences = count_sentences(text);

    // L = average number of letters per 100 words
    float L = letters / words * 100;

    // S = average number of sentences per 100 words
    float S = sentences / words * 100;

    // Compute Coleman-Liau index
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

float count_letters(string text)
{
    float count = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

float count_words(string text)
{
    float count = 1;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]))
        {
            count++;
        }
    }
    return count;
}

float count_sentences(string text)
{
    float count = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}
