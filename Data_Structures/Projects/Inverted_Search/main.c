#include "invsearch.h"

int main(int argc, char* argv[])
{
    filenames_t* head = NULL;
    db_status status = db_empty;
    hashtable_t hash_table[28];
    for (int i = 0;i < 28;i++)
    {
        hash_table[i].index = i;
        hash_table[i].h_link = NULL;
    }
    if (read_and_validate(argc, argv, &head) == FAILURE)
    {
        printf("\033[1;31mCommand Line Validations Failed\n");
        return FAILURE;
    }
    int choice;
    while (1)
    {
        printf("\033[1;33m+______________________+\n");
        printf("| 1.  Create Database  |\n");
        printf("| 2.  Display Database |\n");
        printf("| 3.  Search Database  |\n");
        printf("| 4.  Update Database  |\n");
        printf("| 5.  Save Database    |\n");
        printf("| 6.  Exit             |\n");
        printf("+______________________+\n");
        printf("\033[1;36mEnter the Choice : ");
        printf("\033[0m");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (status == db_created)
            {
                printf("\033[1;32mError! :Database Already Created\n");
                return FAILURE;
            }
            else if (status == db_updated)
            {
                printf("\033[1;32mError! :Cannot Create After the Database is Updated\n");
                return FAILURE;
            }
            else
            {
                if (create_database(head, hash_table) == SUCCESS)
                {
                    printf("\033[1;32mDatabase Created Successfully\n");
                    status = db_created;
                }
            }
            break;
        case 2:
            if (status == db_empty)
            {
                printf("\033[1;31mDatabase Not Created Yet.Please Create Database First\n");
            }
            else if (display_database(hash_table) == FAILURE)
            {
                printf("\033[1;31mNothing to Display in Database");
                return FAILURE;
            }
            break;
        case 3:
            if (status == db_empty)
            {
                printf("\033[1;31mError! :Database is Not Even Created.Please Create Database First\n");
                return FAILURE;
            }
            else
            {
                char search_word[WORD_SIZE];
                printf("\033[1;36mEnter Word to Search: ");
                scanf("%s", search_word);
                if (search_database(hash_table, search_word) == DATA_NOT_FOUND)
                {
                    printf("\033[1;31mWord Not Found in Database\n");
                }
            }
            break;
        case 4:
            if (status == db_empty)
            {
                if (update_database(head,hash_table) == SUCCESS)
                {
                    status = db_updated;
                    if (head != NULL)
                    {
                        create_database(head, hash_table);
                    }
                    printf("Database Updated Successfully\n");
                }
                else
                {
                    printf("No Previous Database File Found.Please Create Database First\n");
                }
            }
            else if (status == db_updated)
            {
                printf("We Cannot Update an Updated Database\n");
            }
            else if(status == db_created)
            {
                printf("Update is Possible Before Database Create\n");
            }
            break;
        case 5:
            if (save_database(hash_table) == SUCCESS)
            {
                printf("\033[1;32mDatabase Saved Successfully\n");
            }
            else if(save_database(hash_table) == INVALID)
            {
                return FAILURE;
            }
            else
            {
                printf("\033[1;31mFailed to Save Database\n");
            }
            break;
        case 6:
            return EXIT;
            break;
        default:
            printf("\033[1;31mInvalid Choice Entered,Try Again\n");
        }
    }
}