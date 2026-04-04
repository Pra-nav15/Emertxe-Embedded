#ifndef LEXER_H
#define LEXER_H

#define MAX_KEYWORDS 20
#define MAX_TOKEN_SIZE 200

typedef unsigned int uint;
typedef enum
{
    KEYWORD = 1,
    OPERATOR,
    SPECIAL_CHARACTER,
    CONSTANT,
    IDENTIFIER,
    UNKNOWN
} TokenType;

typedef struct
{
    FILE* fptr_file;
    int line_no;
    char filename[256];
    char lexi[MAX_TOKEN_SIZE];
    TokenType type;
} Token;

extern int error_flag;
extern int line;
extern int token_count;
extern Token token_list[MAX_TOKEN_SIZE];

void initializeLexer(char* argv[]);
Token getNextToken();
void categorizeToken(Token* token);
int isKeyword(char* str);
int isOperator(char* str);
int isSpecialCharacter(char* str);
int isConstant(char* str);
int isLibFunctions(char* str);;
int isIdentifier(char* str);

#endif
