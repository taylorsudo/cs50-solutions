#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{

    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: %s <positive integer>\n", argv[0]);
        return 1;
    }

    int key = atoi(argv[1]);
    string plainText = get_string("Plaintext: ");
    char cipherText[strlen(plainText)];

    for (int i = 0, n = strlen(plainText) + 1; i < n; i++)
    {
        cipherText[i] = rotate(plainText[i], key);
    }

    printf("Ciphertext: %s\n", cipherText);
}

bool only_digits(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int n)
{
    if (isalpha(c))
    {
        if (isupper(c))
        {
            c = (c - 'A' + n) % 26 + 'A';
        }
        else
        {
            c = (c - 'a' + n) % 26 + 'a';
        }
    }
    return c;
}
