/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

#include "dictionary.h"

typedef struct node
{
    char* word;
    struct node* next;
}node;

node* root[26][26];
int bucket1, bucket2, bucket 3;

int count=0;
char word[LENGTH + 1];
/**
 * Returns true if word is in dictionary else false.
 */

bool check(const char* word)
{
    node* coursor;
    bucket1 = tolower(word[0]) - 'a';
    if (word[2] == '\0')
    {
        bucket2 = 0;
    }
    else
    {
        bucket2 = tolower(word[1]) - 'a';
    }
    if (word[2] == '\0')
    {
        bucket3 = 0;
    }
    else
    {
        bucket3 = tolower(word[2]) - 'a';
    }
    coursor = root[bucket1][bucket2][bucket3];
    while(coursor !=  NULL)
    {
        if(strcasecmp(coursor->word,word)==0)
        return true;
        coursor=coursor->next;
    }
    return false ;
}
/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    FILE* infile = fopen(dictionary,"r");
    int key1, key2, key3;
    if (infile == NULL)
    {
        return false;
    }
    while (fscanf(infile,"%s\n",word) != EOF)
    {
        node* new =malloc(sizeof(node));
        key1 = word[0] - 'a';
        if (word[1] == '\0')
        {
            key2 = 0;
        }
        else
        {
            key2 = word[1] - 'a';
        }
        if (word[2] == '\0')
        {
            key3 = 0;
        }
        else
        {
            key3 = word[2] - 'a';
        }
        new->word = malloc(strlen(word) + 1);
        strcpy(new->word,word);
        
        if(root[key1][key2][key3]==NULL)
        {
            root[key1][key2][key3]=new;
            new->next=NULL;
        }
        else
        {
            new->next=root[key1][key2][key3];
            root[key1][key2][key3]=new;
        }
        
        count++;
    }
    fclose(infile);
    
    return true;
}


/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return count;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    node* cursor;
    node* temp;
    for(int i=0;i<26;i++)
    {
        for (int j = 0; j < 26; j++)
        {
            for (int k = 0; k < 26; k++)
            {
                cursor= root[i][j][k];
                while (cursor != NULL)
                {
                    temp =cursor;
                    cursor=cursor->next;
                    free(temp->word);
                    free(temp);
                }
            }
        }
    }
    return true;
}