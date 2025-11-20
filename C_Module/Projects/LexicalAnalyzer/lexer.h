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
    const char* filename;
    char lexi[MAX_TOKEN_SIZE];
    TokenType type;
} Token;

void initializeLexer(char* argv[]);
Token getNextToken();
void categorizeToken(Token* token);
int isKeyword(const char* str);
int isOperator(const char* str);
int isSpecialCharacter(char ch);
int isConstant(const char* str);
int isIdentifier(const char* str);

#endif
