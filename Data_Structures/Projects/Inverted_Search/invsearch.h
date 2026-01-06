#ifndef INVSEARCH_H
#define INVSEARCH_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define WORD_SIZE 26
#define FNAME_SIZE 20
#define SUCCESS 1
#define FAILURE 0
#define DATA_NOT_FOUND -1
#define EXIT -2
#define FILE_EMPTY -3
#define INVALID -4

typedef enum
{
    db_empty,
    db_created,
    db_updated,
}db_status;

typedef struct file
{
    char file_name[WORD_SIZE];
    struct file* f_link;
}
filenames_t;

typedef struct subnode
{
    char file_name[FNAME_SIZE];
    int word_count;
    struct subnode* s_link;
}subnode_t;

typedef struct mainnode
{
    int file_count;
    char word[WORD_SIZE];
    struct mainnode* m_link;
    subnode_t *s_link;
}mainnode_t;

typedef struct hashtable
{
    int index;
    mainnode_t* h_link;
}hashtable_t;

int read_and_validate(int argc, char* argv[], filenames_t** head);
int open_files(char* argv);
int hash_index(char ch);
int display_database(hashtable_t* hash_arr);
int create_database(filenames_t* head, hashtable_t* hash_arr);
int search_database(hashtable_t* hash_table, char* word);
int save_database(hashtable_t* hash_arr);
int update_database(filenames_t* head,hashtable_t* hash_arr);


#endif
