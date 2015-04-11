%{
#include "shell.h"
extern char *yytext;
typedef struct yy_buffer_state * YY_BUFFER_STATE;
extern YY_BUFFER_STATE yy_scan_string(char * str);
extern void yy_delete_buffer(YY_BUFFER_STATE buffer);

void yyerror(const char *str) {
	fprintf(stderr,"error: %s\n", str);
}

int yywrap() {
	return 1;
}

%}
%token CD PRINTENV UNSETENV SETENV NEWLINE ALIAS UNALIAS BYE WORD QUOTES ENVIRONMENTVARIABLE READFROM WRITETO PIPE AMPERSAND APPEND STANDARDERROR1 STANDARDERROR2 
%%

// some recursion
begin: 
		| builtin_commands NEWLINE {
			return 0;
		}
		| execute_commands begin {
			return 0;
		}
		| NEWLINE {
			return 0;
		};

// these cases make builtin_type > 0
builtin_commands:
		cd_case
		|env_case
		|alias_case
		|bye_case;
		
cd_case:
		CD {
			builtin_type = CDHOME_DEF;
			//cd_home_function();
		}
	    |
		CD word_case {
			builtin_type = CDPATH_DEF;	
			strcpy(cdPath, wordTable[getWords() - 1]);
		};
env_case:
	    PRINTENV {
			builtin_type = PRINTENV_DEF;
		}
		| 
		UNSETENV word_case {
			builtin_type = UNSETENV_DEF;
			variable = strdup(wordTable[getWords() - 1]);
		}   
		|
		SETENV word_case word_case {
			//setenv_function(wordTable[getWords() - 2], wordTable [getWords() - 1], 1);	
			builtin_type = SETENV_DEF;
			variable = strdup(wordTable[getWords() - 2]);
			word = strdup(wordTable[getWords() - 1]);
		};
alias_case:
		ALIAS {
			builtin_type = ALIASPRINT_DEF;
		}
		|
		ALIAS  word_case  word_case {
			//alias_function(wordTable[getWords() - 2], wordTable[getWords() - 1]);
			builtin_type = ALIAS_DEF;
			variable = strdup(wordTable[getWords() - 2]);
			word = strdup(wordTable[getWords() - 1]);
		}
		|
		UNALIAS word_case {
			//unalias_function(wordTable[getWords() - 1], 1);  
			builtin_type = UNALIAS_DEF;
			variable = strdup(textArray[getWords() - 1]);
		};		
bye_case:
		BYE { 
			printf("[01;31;40m" "\n******************************  SHELL ENDS HERE  *******************************\n\n");
			printf("[00;00;00m");
			exit(0); //exit shell
		};



execute_commands:
		ampersand_case
		|standard_error_redirect_case
		|standard_error_redirect_case2
		|error_case        
		|word_case
		|pipe2_case
		|read_from_case2
		|write_to_case2
		|append_case2;

read_from_case2:
		READFROM
							{
								insertToWordTable("<");
								//lineHeaderPath();
							};
write_to_case2:
		WRITETO
							{
								insertToWordTable(">");
								//lineHeaderPath();
							};

pipe2_case:
		PIPE
							{
								insertToWordTable("|");
							};

ampersand_case:
		AMPERSAND			
							{
								insertToWordTable("&");
								//lineHeaderPath();
							};
standard_error_redirect_case:
		STANDARDERROR1
							{
								insertToWordTable("2>&1");
								//lineHeaderPath();
							};

standard_error_redirect_case2:
		STANDARDERROR2		
							{
								insertToWordTable(yytext);
								//lineHeaderPath();
							};
error_case:
		error
							{
								//printf ("Syntax error.\n");
								//lineHeaderPath();
							};
append_case2:
		APPEND				{
								insertToWordTable(">>");
								//lineHeaderPath();
							};
							
///////////////////////////////taken out shit storm

word_case:
		WORD				
							{
								yytextProcessor(yytext);
							}
	|	ENVIRONMENTVARIABLE
							{
								char* actualText = malloc(300 * sizeof(char));
								if(actualText == (char*) NULL) //error
								{
										perror ("Error with memory allocation.");
										printf ("Error at line %d\n", __LINE__);
								}
								else
								{
									strncpy(actualText, &yytext[2], strlen(yytext) - 3); //take everything between ${ and }
									char* result = malloc(300 * sizeof(char));
									if(result == (char*) NULL) //error
									{
										perror ("Error with memory allocation.");
										printf ("Error at line %d\n", __LINE__);
									}
									else
									{
										if(getenv(actualText) == NULL) //invalid environment variable
										{
											perror ("Entered an invalid environment variable.");
											printf ("Error at line %d\n", __LINE__);
										}
										else
										{
											strcpy(result, getenv(actualText)); //get value, if any
											insertToWordTable(result);
										}
									}
								}		
							}
	|	QUOTES				{
								quoteFunction(yytext);
							};

