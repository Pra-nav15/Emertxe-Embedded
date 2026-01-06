#include "invsearch.h"

int read_and_validate(int argc, char* argv[], filenames_t** head)
{
    int flag;
    if (argc < 2)
    {
        printf("\033[1;31mError ! --> Usage: ./a.out file1.txt file2.txt\033[0m");
        return FAILURE;
    }
    for (int i = 1; i < argc; i++)
    {
        if (open_files(argv[i]) == SUCCESS)
        {
            filenames_t* temp = *head;
            flag = 0;
            while (temp != NULL) //traverse until last
            {
                if (strcmp(temp->file_name, argv[i]) == 0) //duplicate check
                {
                    printf("\033[1;37mDuplicate Found: %s\n", argv[i]);
                    flag = 1;
                    break;
                }
                temp = temp->f_link;
            }
            if (flag == 0)
            {
                filenames_t* new = malloc(sizeof(filenames_t));
                strcpy(new->file_name, argv[i]);
                new->f_link = *head;
                *head = new;
            }
        }
        else if (open_files(argv[i]) == FILE_EMPTY)
        {
            printf("\033[1;34mFile is Empty\n");
            return FAILURE;
        }
        else
        {
            printf("\033[1;31mError !:Files Cannot be opened\n");
            return FAILURE;
        }
    }
    return SUCCESS;
}

int open_files(char* argv)
{
    char* exten = strrchr(argv, '.');
    if (exten != NULL  && strcmp(exten, ".txt") == 0)
    {
        FILE *fptr = fopen(argv, "r");
        if (fptr != NULL)
        {
            fseek(fptr, 0, SEEK_END);
            if (ftell(fptr) <= 0) //empty file
            {
                return FILE_EMPTY;
            }
            else //file has some contents
            {
                return SUCCESS;
            }
        }
        else
        {
            return FAILURE;
        }
    }
}