#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "lexer.h"

Token *token;

static char *res_kwords_data[] = { "const","volatile","extern","auto","register","static","signed","unsigned","short","long","double","char","int","float","struct","union","enum","void","typedef","" };
static char *res_kwords_non_data[] = { "goto","return","continue","break","if","else","for","while","switch","case","default","sizeof","do","" };
static char operators[] = { '/', '+', '*', '-', '%', '=', '<', '>', '~', '&', ',', '!', '^', '|' };
static char symbols[]   = { '(', ')', '{', '}', '[', ']', ':' };


void initializeLexer(char *argv[])
{
    char *extn = strstr(argv[1], ".c");

    if (extn != NULL && strcmp(extn, ".c") == 0)
    {
        strcpy(token->filename, argv[1]);
        token->fptr_file = fopen(token->filename, "r");
        if (token->fptr_file == NULL)
        {
            perror("fopen");
            fprintf(stderr, "ERROR: Unable to open the sample file %s\n", token->filename);
        }
    }
}

void categorizeToken(Token *token)
{
    int i = 0;
    char ch;
    while (fread(&ch, 1, 1, token->fptr_file) == 1)
    {
        if (ch!=' ')
        {
            token->lexi[i++] = ch;
        }
        else
        {
            if (i > 0)
            {
                token->lexi[i] = '\0';
                printf("Token: %s ", buffer);
                if (isKeyword(token->lexi)== KEYWORD)
                {
                    printf("Keywords\n");
                }
                if (isOperator(token->lexi) == OPERATOR)
                {
                    printf("Operator\n");
                }
                if (isSpecialCharacter(token->lexi) == SPECIAL_CHARACTER)
                {
                    printf("Special Character\n");
                }
                if (isConstant(token->lexi) == CONSTANT)
                {
                    printf("Constant\n");
                }
                if (isIdentifier(token->lexi) == IDENTIFIER)
                {
                    printf("Identifier\n");
                }
                else
                {
                    printf("Unknown\n");
                }
                i = 0;
            }
        }
    }
}

int isKeyword(char *str)
{
    int i = 0;
    while (res_kwords_data[i] != NULL)
    {
        if (strcmp(str, res_kwords_data[i]) == 0)
        {
            return KEYWORD;
        }
        i++;
    }
    while(res_kwords_non_data[i] != NULL)
    {
        if (strcmp(str, res_kwords_non_data[i]) == 0)
        {
            return KEYWORD;
        }
        i++;
    }
    return 0;
}

int isOperator(char *str)
{
    /* if (strlen(str) != 1)
    {
        return 0;
    } */
    for (int i = 0; i < sizeof(operators); i++)
    {
        if (str[0] == operators[i])
        {
            return OPERATOR;
        }
    }
    return 0;
}

int isSpecialCharacter(char *str)
{
    if (strlen(str) != 1)
    {
        return 0;
    }
    for (int i = 0; i < sizeof(symbols); i++)
    {
        if (str[0] == symbols[i])
        {
            return SPECIAL_CHARACTER;
        }
    }
    return 0;
}

int isConstant(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i]))
        {
            return 0;
        }
    }
    return CONSTANT;
}

int isIdentifier(char *str)
{
    if (!isalpha(str[0]) && str[0] != '_')
    {
        return 0;
    }

    for (int i = 1; str[i] != '\0'; i++)
    {
        if (!isalnum(str[i]) && str[i] != '_')
        {
            return 0;
        }
    }
    return IDENTIFIER;
}
