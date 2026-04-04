#include <stdio.h>
#include <string.h>
#include "lexer.h"
int main(int argc, char* argv[])
{
    if(argc < 2)									
	{
		printf("Insufficient Number of Arguments\n");
		printf("Usage: ./a.out <sample.c file>\n");		
		return 0;
	}
	initializeLexer(argv);
	Token new_token;
	printf("\n\033[32m=====================================================================\n");
	printf("\033[33m%40s","LEXICAL ANALYZER\n");
	printf("\033[32m=====================================================================\033[0m\n");
	printf("--------------------------------------------------------------------\n");
	printf("| \033[1;36m%-5s\033[0m | \033[1;36m%-30s\033[0m | \033[1;36m%-23s\033[0m |\n", "Sl No", "Token", "Type");
	printf("--------------------------------------------------------------------\n");
	int i = 1;
	while ((new_token = getNextToken()).type != UNKNOWN)
	{
		printf("| \033[1;33m%-5d\033[0m | \033[1;37m%-30s\033[0m |", i++, new_token.lexi);
		switch (new_token.type)
		{
			case KEYWORD:
			{
				printf("\033[1;35m%-25s\033[0m|\n"," KEYWORD");
			}
			break;
			case OPERATOR:
			{
				printf("\033[1;33m%-25s\033[0m|\n"," OPERATOR");
			}
			break;
			case SPECIAL_CHARACTER:
			{
				printf("\033[1;36m%-25s\033[0m|\n"," SYMBOL");
			}
			break;
			case CONSTANT:
			{
				printf("\033[1;31m%-25s\033[0m|\n"," CONSTANT");
			}
			break;
			case IDENTIFIER:
			{
				printf("\033[1;32m%-25s\033[0m|\n"," IDENTIFIER");
			}
			break;
			default:
			{
				printf("\033[1;34mUNKNOWN\033[0m");
			}
		}
	}
	for (int i = 0; i < token_count - 1; i++)
	{
		TokenType current_token = token_list[i].type;
		TokenType next_token    = token_list[i + 1].type;
		// skip if previous token was an operator (expression context)
		if (i > 0 && token_list[i - 1].type == OPERATOR)
		{
			continue;
		}
		// skip if next token is an operator (still in expression)
		if (next_token == OPERATOR)
		{
			continue;
		}
		// skip if current token is inside or adjacent to parentheses
		if (strcmp(token_list[i].lexi, "(") == 0 || strcmp(token_list[i].lexi, ")") == 0)
		{
			continue;
		}
		// skip if next token is a parenthesis (function call context)
		if (strcmp(token_list[i + 1].lexi, "(") == 0 || strcmp(token_list[i + 1].lexi, ")") == 0)
		{
			continue;
		}
		// skip if current token is inside or adjacent to brackets (array context)
		if (strcmp(token_list[i].lexi, "[") == 0 || strcmp(token_list[i].lexi, "]") == 0)
		{
			continue;
		}
		// skip if next token is a bracket
		if (strcmp(token_list[i + 1].lexi, "[") == 0 || strcmp(token_list[i + 1].lexi, "]") == 0)
		{
			continue;
		}
		// skip comma context (multiple declarations or arguments)
		if (strcmp(token_list[i].lexi, ",") == 0 || strcmp(token_list[i + 1].lexi, ",") == 0)
		{
			continue;
		}
		if ((current_token == IDENTIFIER || current_token == CONSTANT) && (next_token == KEYWORD || next_token == IDENTIFIER || strcmp(token_list[i + 1].lexi, "}") == 0) &&strcmp(token_list[i + 1].lexi, "else") != 0)
		{ 
			printf("\033[1;31mError [Line %d]: Missing ';' after '%s'\033[0m\n",token_list[i].line_no, token_list[i].lexi);
			error_flag = 1;
		}
	}
	printf("--------------------------------------------------------------------\n");

	if (error_flag)
	{
		printf("\033[1;31m=========================================\033[0m\n");
		printf("\033[1;31mBuild Failed — errors found in %s\033[0m\n", argv[1]);
		printf("\033[1;31m=========================================\033[0m\n");
	}
	else
	{
		printf("\033[1;32m=========================================\033[0m\n");
		printf("\033[1;32mBuild Success\033[0m\n");
		printf("\033[1;32m==========================================\033[0m\n");
	}
	return 0;
}