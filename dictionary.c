/**
 * Implements a dictionary's functionality.
 * This implementation is CS50's pset5. This file is a helper file, which is compiled together with speller.c (also on github for reference)
 *
 * There are 3 main functions in dictionary.c : load, check, unload.
 * Load creates a Hashtable (of pointers to nodes in a linked list) to represent an English dictionary (list of lowercase words).
 * Check checks whether a given word is in that hash_table.
 * Unload unallocates the memory that Hashtable was taking up.
 */

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "dictionary.h"

unsigned long hash(char *str); //See below for hash function.

#define ARR_SIZE 150000 // I know my dictionary has 143,091 words in it.
#define LENGTH 45       // I know the longest word in my dictionary is 45 chars. These were given.

//CREATE a struct to hold the nodes with which I'm going to build a linked list.
typedef struct word_node
{
    char word[LENGTH+1];
    int key;
    struct word_node* next;
}
word_node;

//CREATE an array of word_node pointers. Unfortunately, this has to be in global memory
//due to constraints on input/return values of load, check, unload, etc. These were given.

word_node *HashTable[ARR_SIZE];

//This counter will be used to check how many words are in the dictionary.
unsigned int counter = 0;


/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    //Create variable to hold word to check.
    char word_to_check[LENGTH+1];

    //Convert word to lowercase.
    for (int i = 0, n = strlen(word); i<=n; i++)
    {
        word_to_check[i] = tolower(word[i]);
    }

    //Hash the word.
    int hash_key = hash(word_to_check) % ARR_SIZE;

    //Create pointer and set ptr to point to the same word_node as the header pointer.
    word_node* ptr = NULL;
    ptr = HashTable[hash_key];

    //If the ptr at HashTable[hash_key] is empty, then the word is not in the dictionary.
    if (ptr == NULL)
    {
        return false;
    }

    //If the pointer is pointing to a word_node whose word is the same as the word to check,
    //return true.
    if (strcmp(ptr->word,word_to_check) == 0)
    {
        return true;
    }
    //If the pointer is pointing to a word_node whose word is NOT the same as the word to check,
    //then we have to check whether there was a collision while loading the dictionary.
    //We do this by iterating through the members of the linked list and checking whether
    //the word at that node is the same as the word we are checking.
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;

            //The printf below prints the word/hash_key of every word_node in the linked list.
            //printf("%s, %s, %i, %i\n", word_to_check, ptr->word, hash_key, ptr->key);

            if (strcmp(ptr->word,word_to_check) == 0)
            {
                return true;
            }

        }
    }
    //If the linked list at the hash_key'th position of HashTable doesn't have a node
    //which holds the word, then it's not in the dictionary.
    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    // Open input file.
    FILE *dict = fopen(dictionary, "r");

    // If it cannot open, print an error message.
    if (dict == NULL)
    {
        fprintf(stderr, "Could not open your stupid dictionary.\n");
        return false;
    }
    /*OVERVIEW FOR HOW I LOAD THE DICTIONARY. I am making a hashmap.
    1. INITIALIZE the hash_table array to store NULL pointers.
    As the HashTable populates, these will become Pointers to Nodes of a linked list. (linked in case of collisions).

    2. READ the words out of the dictionary one by one. For each word...

    3. CREATE a pointer to a new word_node (storing the word, its hashed value, and its pointer to the next node)

    4. INSERT the node into the array - in the hash_key position.
    */
    //1. INITIALIZE HashTable to NULL pointers.
    for (int n = 0; n<ARR_SIZE; n++)
    {
        HashTable[n] = NULL;
    }


    //2. READ the words out, storing them to a buffer variable called entry.
    char entry[LENGTH+1];
    while (fscanf(dict, "%s", entry) != EOF)
    {
        //Allocate enough memory for a new word_node. Have new_node_ptr point to that newly allocated memory.
        word_node *new_node_ptr = malloc(sizeof(word_node));

        //If malloc fails, it returns NULL. Then you don't have memory to create a new node, so quit.
        if (new_node_ptr == NULL)
        {
            unload();
            return false;
        }
        //If malloc succeeds, access the word property of the pointees, and save the entry there.
        strcpy(new_node_ptr->word, entry);

        //Now hash the word to determine its index in the hashtable
        int hash_key = hash(new_node_ptr->word) % ARR_SIZE;
        new_node_ptr->key = hash_key;

        //Initializes next of word_node to NULL (if first item) or Next item in linked list.
        new_node_ptr->next = HashTable[hash_key];
        //Sets pointer at HashTable[hash_key] to point to the new word_node
        HashTable[hash_key] = new_node_ptr;
        //printf("%s and %i\n", new_node_ptr->word, new_node_ptr->key); //Uncomment line to see each word + hash key value.

        counter++;
    }
    return true;
}


/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return counter;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    for (int i = 0; i<ARR_SIZE; i++)
    {
        word_node* prevptr = HashTable[i];
        word_node* nextptr;
        while (prevptr != NULL)
        {
            nextptr = prevptr->next;
            free(prevptr);
            prevptr = nextptr;
        }
    }
    return true;
}

//This hashing function is djb2 by dan bernstein. I found it on stack_overflow.
unsigned long hash(char *str)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}
