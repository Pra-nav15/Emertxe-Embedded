#include"invsearch.h"

int update_database(filenames_t* head, hashtable_t* hash_arr)
{
    char db_file[100];
    char backup_file[100];
    int index;
    char word[50];
    printf("Enter the Database File to Update : ");
    scanf("%s", db_file);
    char* exten = strstr(db_file, ".txt");
    if (exten == NULL || strcmp(exten, ".txt") != 0)
    {
        printf("\033[1;31mError!:Database File Should be .txt format\n");
        return FAILURE;
    }
    FILE* fptr = fopen(db_file, "r");
    if (fptr == NULL)
    {
        printf("File Could Not be opened\n");
        return FAILURE;
    }
    while (fscanf(fptr, "%s", db_file) != EOF)
    {
        if (db_file[0] == '#')
        {
            char* token = strtok(db_file + 1, ";");
            index = atoi(token);

            mainnode_t* m_new = malloc(sizeof(mainnode_t));
            if (m_new == NULL)
            {
                return FAILURE;
            }
            m_new->m_link = NULL;
            strcpy(m_new->word, strtok(NULL, ";"));
            m_new->file_count = atoi(strtok(NULL, ";"));
            for (int i = 0;i < m_new->file_count;i++)
            {
                subnode_t* s_new = malloc(sizeof(subnode_t));
                if (s_new == NULL)
                {
                    return FAILURE;
                }
                strcpy(s_new->file_name, strtok(NULL, ";"));
                strcpy(backup_file, s_new->file_name);
                s_new->word_count = atoi(strtok(NULL, ";"));
                s_new->s_link = NULL;
                filenames_t* temp = head;
                filenames_t* prev = NULL;
                while (temp != NULL)
                {
                    if (strcmp(temp->file_name, backup_file) == 0)
                    {
                        if (prev == NULL)
                        {
                            head = temp->f_link;
                        }
                        else
                        {
                            prev->f_link = temp->f_link;
                        }
                        filenames_t* delete = temp;
                        temp = temp->f_link;
                        free(delete);
                    }
                    else
                    {
                        prev = temp;
                        temp = temp->f_link;
                    }
                }
                if (m_new->s_link == NULL)
                {
                    m_new->s_link = s_new;
                }
                else
                {
                    subnode_t* sub_temp = m_new->s_link;
                    while (sub_temp->s_link != NULL)
                    {
                        sub_temp = sub_temp->s_link;
                    }
                    sub_temp->s_link = s_new;
                }
            }
            if (hash_arr[index].h_link == NULL)
            {
                hash_arr[index].h_link = m_new;
            }
            else
            {
                mainnode_t* main_temp = hash_arr[index].h_link;
                while (main_temp->m_link != NULL)
                {
                    main_temp = main_temp->m_link;
                }
                main_temp->m_link = m_new;
            }
        }
        else
        {
            printf("No database file is detected\n");
            fclose(fptr);
            return FAILURE;
        }
    }
    fclose(fptr);
    return SUCCESS;

}