#include "invsearch.h"

int create_database(filenames_t* head, hashtable_t* hash_arr)
{
    filenames_t* temp = head;
    char word[30];
    while (temp != NULL)
    {
        FILE* fptr = fopen(temp->file_name, "r");
        if (fptr == NULL)
        {
            printf("\033[1;31mError : File Cannot be Opened");
            return FAILURE;
        }
        while (fscanf(fptr, "%s", word) != EOF)
        {
            int index = hash_index(word[0]);
            if (hash_arr[index].h_link == NULL)
            {
                mainnode_t* m_new = malloc(sizeof(mainnode_t));
                subnode_t* s_new = malloc(sizeof(subnode_t));
                if (m_new == NULL || s_new == NULL)
                {
                    return FAILURE;
                }
                m_new->file_count = 1;
                strcpy(m_new->word, word);
                m_new->m_link = NULL;
                m_new->s_link = s_new;

                s_new->word_count = 1;
                strcpy(s_new->file_name, temp->file_name);
                s_new->s_link = NULL;

                hash_arr[index].h_link = m_new;
            }
            else
            {
                mainnode_t* main_temp = hash_arr[index].h_link;
                mainnode_t* main_prev = NULL;
                int found = 0;
                while (main_temp != NULL)
                {
                    if (strcmp(main_temp->word, word) == 0)
                    {
                        found = 1;
                        subnode_t* sub_temp = main_temp->s_link;
                        subnode_t* sub_prev = NULL;
                        int f_found = 0;
                        while (sub_temp != NULL)
                        {
                            if (strcmp(sub_temp->file_name, temp->file_name) == 0)
                            {
                                f_found = 1;
                                sub_temp->word_count++;
                                break;
                            }
                            sub_prev = sub_temp;
                            sub_temp = sub_temp->s_link;
                        }
                        if (f_found == 0)
                        {
                            subnode_t* s_new = malloc(sizeof(subnode_t));
                            if (s_new == NULL)
                            {
                                return FAILURE;
                            }
                            s_new->word_count = 1;
                            strcpy(s_new->file_name, temp->file_name);
                            s_new->s_link = NULL;
                            sub_prev->s_link = s_new;
                            main_temp->file_count++;
                        }
                        break;
                    }
                    main_prev = main_temp;
                    main_temp = main_temp->m_link;
                }
                if (found == 0)
                {
                    mainnode_t* m_new = malloc(sizeof(mainnode_t));
                    subnode_t* s_new = malloc(sizeof(subnode_t));
                    if (m_new == NULL || s_new == NULL)
                    {
                        return FAILURE;
                    }
                    m_new->file_count = 1;
                    strcpy(m_new->word, word);
                    m_new->m_link = NULL;
                    m_new->s_link = s_new;
                    s_new->word_count = 1;
                    strcpy(s_new->file_name, temp->file_name);
                    s_new->s_link = NULL;
                    main_prev->m_link = m_new;
                }
            }
        }
        fclose(fptr);
        temp = temp->f_link;
    }
    return SUCCESS;
}

int hash_index(char ch)
{
    if (isalpha(ch)) // for alphabets
    {
        int ret = tolower(ch) - 97;
        return ret;
    }
    else if (isdigit(ch))
    {
        return 26; // for digits 0 to 9
    }
    else
    {
        return 27; //for special characters
    }
}