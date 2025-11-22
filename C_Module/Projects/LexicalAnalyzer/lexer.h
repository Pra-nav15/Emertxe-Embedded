#ifndef LEXER_H
#define LEXER_H

#define MAX_KEYWORDS 20
#define MAX_TOKEN_SIZE 100

typedef unsigned int uint;
typedef enum {
    KEYWORD,
    OPERATOR,
    SPECIAL_CHARACTER,
    CONSTANT,
    IDENTIFIER,
    UNKNOWN
} TokenType;

typedef struct
{
    FILE* fptr_file;
    char* filename;
    char lexi[MAX_TOKEN_SIZE];
    TokenType type;
} Token;

void initializeLexer(char* argv[]);
//Token getNextToken();
void categorizeToken(Token* token);
int isKeyword(char* str);
int isOperator(char* str);
int isSpecialCharacter(char* str);
int isConstant(char* str);
int isIdentifier(char* str);

#endif
