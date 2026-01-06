#include "invsearch.h"

int save_database(hashtable_t *hash_arr)
{
    if (hash_arr == NULL)
    {
        return FAILURE;
    }
    char database[15];
    printf("\033[1;34mEnter the database name: ");
    scanf("%s", database);
    char* exten = strstr(database, ".txt");
    if (exten == NULL || strcmp(exten, ".txt") != 0)
    {
        printf("\033[1;31mError!: Database File Should be .txt format\n");
        return INVALID;
    }
    FILE* fptr = fopen(database, "w");
    if (fptr == NULL)
    {
        printf("\033[1;31mError!:Cannot Open DataBase File\n");
        return FAILURE;
    }
    for (int i = 0; i < 28; i++)
    {
        if (hash_arr[i].h_link != NULL)
        {
            mainnode_t* main_temp = hash_arr[i].h_link;
            while (main_temp != NULL)
            {
                fprintf(fptr, "#%d;%s;%d;", i, main_temp->word, main_temp->file_count);
                subnode_t *sub_temp = main_temp->s_link;
                while (sub_temp != NULL)
                {
                    fprintf(fptr, "%s;%d#\n",sub_temp->file_name, sub_temp->word_count);
                    sub_temp = sub_temp->s_link;
                }
                main_temp = main_temp->m_link;
            }
        }
    }
    fclose(fptr);
    return SUCCESS;
}