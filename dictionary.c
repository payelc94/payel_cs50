/**
 * Implements a dictionary's functionality.
 */
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "dictionary.h"


int countWord = 0;




typedef struct node
{
    char* word;
    struct node* next;
}node;

//hashTable of linked list
node* hashTable[1000];



int hashValue(const char* str)
{
    int wordLength = 0, hashVal = 0;
    wordLength = strlen(str);
    for(int i = 0; i < wordLength; i++)
    {
        hashVal= hashVal +str[i];
    }
     int val=hashVal % 1000;
     return val;
}


/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    char before[LENGTH + 1];
    char lowString;
    for(int i = 0, n = strlen(word); i < n; i++)
    {
        lowString = tolower(word[i]);
        before[i] = (char)lowString;
    }
    
    
   before[strlen(word)] = '\0';
    
    int hashVal = hashValue(before);
    node* cursor = hashTable[hashVal];
    if(cursor == NULL)
    {
        return false;
    }
    while(cursor != NULL)
    {
        if(!strcmp(before, cursor -> word))
        {
            return true;
        }
        cursor = cursor -> next; 
    }
    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    int hashVal = 0;
    char dict[LENGTH + 1];
    
    FILE* file = fopen(dictionary, "r");
    if(file == NULL)
    {
        return false;
    }
    
    while(fscanf(file, "%s\n", dict) != EOF)
    {
        node* new_node = malloc(sizeof(node));
        hashVal = hashValue(dict);
        
        new_node -> word = malloc(strlen(dict) + 1);
        
        strcpy(new_node -> word, dict);
        
        
        if(hashTable[hashVal] == NULL)
        {
            hashTable[hashVal] = new_node;
            new_node -> next = NULL;
        }
        else
        {
            new_node -> next = hashTable[hashVal];
            hashTable[hashVal] = new_node;
        }
        
        countWord++;
    }
    fclose(file);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return countWord;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    node* L1 = NULL ; 
    
    for(int i = 0; i < 1000; i++)
    {
        L1 = hashTable[i];
        free(L1);
        hashTable[i] = NULL;
    }
    return true;
}
