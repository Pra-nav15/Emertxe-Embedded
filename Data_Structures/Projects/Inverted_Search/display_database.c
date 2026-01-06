#include "invsearch.h"

int display_database(hashtable_t* hash_arr)
{
    if (hash_arr == NULL)
    {
        return FAILURE;
    }
    printf("\033[1;36m");
    printf("+------+------------+----------------+----------------------+------------+\n");
    printf("| %-3s | %-9s | %-14s | %-19s | %-10s |\n","Index", "FileCount", "Word", "File Name", "Word Count");
    printf("+------+------------+----------------+----------------------+------------+\n");

    for (int i = 0;i < 28;i++)
    {
        if (hash_arr[i].h_link != NULL)
        {
            mainnode_t* main_temp = hash_arr[i].h_link;
            while (main_temp != NULL)
            {
                subnode_t* sub_temp = main_temp->s_link;
                int first = 1;
                while (sub_temp != NULL)
                {
                    if (first == 1)
                    {
                        printf("\033[1;32m| %-4d | %-10d | %-14s | %-20s | %-10d |\n", i, main_temp->file_count, main_temp->word,sub_temp->file_name, sub_temp->word_count);
                        first = 0;
                    }
                    else
                    {
                        printf("\033[1;32m| %-4s | %-10s | %-14s | %-20s | %-10d |\n", " ", " ", " ", sub_temp->file_name, sub_temp->word_count);
                    }
                    sub_temp = sub_temp->s_link;
                }
                main_temp = main_temp->m_link;
            }
        }
    }
    printf("+------+------------+----------------+----------------------+------------+\n");
    return SUCCESS;
}