// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Choose number of buckets in hash table
const unsigned int N = 26;

// Initialise word count
unsigned int loaded_words = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Hash the word to get the index in the hash table
    unsigned int index = hash(word);

    // Access linked list at index in the hash table
    node *cursor = table[index];

    // Traverse linked list
    while (cursor != NULL)
    {
        // If the word is in the dictionary (case-insensitive)
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }

        // Move to the next item
        cursor = cursor->next;
    }

    // Word not found in the dictionary
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int sum = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        sum += tolower(word[i]);
    }
    return sum % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    // Read strings from file one at a time
    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        // Create a new node for each word
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            fclose(file);
            free(new_node);
            return false;
        }
        strcpy(new_node->word, word);

        // Hash the word to get the index in the hash table
        int index = hash(word);

        // Insert node into hash table at that location
        new_node->next = table[index];
        table[index] = new_node;

        // Increment loaded words
        loaded_words++;
    }

    // Close dictionary file
    fclose(file);

    // Dictionary successfully loaded
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if (loaded_words > 0)
    {
        return loaded_words;
    }
    else
    {
        return 0;
    }
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Free memory for each node in the hash table
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
}
