#include "invsearch.h"

int search_database(hashtable_t* hash_arr, char* word)
{
    if (hash_arr == NULL)
    {
        return FAILURE;
    }
    int index = hash_index(word[0]);
    mainnode_t* main_temp = hash_arr[index].h_link;
    while (main_temp != NULL)
    {
        if (strcmp(main_temp->word, word) == 0)
        {
            printf("\033[1;32mThis Word is found in\033[1;33m %d \033[1;32mfiles\n", main_temp->file_count);
            subnode_t* sub_temp = main_temp->s_link;
            while (sub_temp != NULL)
            {
                printf("\033[1;34mFile Name is \033[1;33m %s\n", sub_temp->file_name);
                printf("\033[1;34mWord Count is \033[1;33m %d\n", sub_temp->word_count);
                sub_temp = sub_temp->s_link; 
            }
            return SUCCESS;
        }
        else
        {
            main_temp = main_temp->m_link;
        }
    }
    return DATA_NOT_FOUND;
}