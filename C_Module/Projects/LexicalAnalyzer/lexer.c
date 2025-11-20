#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "lexer.h"

Token* token;

static char* res_kwords_data[] = { "const", "volatile", "extern", "auto", "register","static", "signed", "unsigned", "short", "long","double", "char", "int", "float", "struct","union", "enum", "void", "typedef", "" };
static char* res_kwords_non_data[] = { "goto", "return", "continue", "break","if", "else", "for", "while","switch", "case", "default", "sizeof", "do","" };
static char operators[] = { '/', '+', '*', '-', '%', '=', '<', '>', '~', '&', ',' ,'!', '^', '|' };
static char symbols[] = { '(', ')', '{', '}', '[', ']', ':' };

void initializeLexer(char *argv[])
{
    char* extn = strstr(argv[1], ".c");
    if (extn != NULL && strcmp(extn, ".c") == 0)
    {
        strcpy(token->filename, argv[1]);
        token->fptr_file = fopen(token->filename, "r");  
        if (token->fptr_file == NULL)
        {
            perror("\033[0;31mfopen\033[0m");
            fprintf(stderr, "\033[0;31mERROR: Unable to Open .c file %s\033[0m\n", token->filename);
        }
    }
}
void categorizeToken(Token* token)
{
    int i = 0;
    char buffer[MAX_TOKEN_SIZE];
    char ch;
    while (fread(&ch, 1, 1, token->fptr_file) == 1)
    {
        if (ch != '\0' && ch != ' ')
        {
            buffer_store[i++] = ch;
        }
        else
        {
            buffer[i] = '\0';
        }
    }
} 