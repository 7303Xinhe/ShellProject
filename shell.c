#include "shell.h"

#include "alias_functions.c"
#include "cd_functions.c"
#include "env_functions.c"
#include "execute_function.c"

main() {
	shell_init();
	// loops till bye
	while(1) {
		// prepare parser
		wordArray[0] = strdup("");
		// header
		lineHeaderPath();
		switch(getCommand()) {
			case ERRORS:
				break;
			case OK:
				processCommand();
				break;
			default: 				
				break;
		}
	}
}

void shell_init() {
	// black background
	
	printf("[01;32;40m" "\n****************************** SHELL STARTS HERE ******************************\n");
	printf("[00;32;40m" "");

	wordArray = (char**) malloc(500 * sizeof(char*));
	wordArray[0] = strdup("");

	aliasCount = 0;
	wordCount = 0; //number of wordCount
	addedWords = 0;
	builtin_type = 0;
	cdPath = malloc(500 * sizeof(char));
	variable = malloc(500 * sizeof(char));
	word = malloc(500 * sizeof(char));
	
	myHome = malloc(500 * sizeof(char));
	strcpy(myHome, getenv("HOME")); //get home directory so that it stays constant
	
	//signal(SIGINT, SIG_IGN); //prevent crash from ctrl-c
	signal(SIGTSTP, SIG_IGN); //prevent crash from ctrl-z
	signal(SIGQUIT, SIG_IGN); //prevent crash from ctrl-/

	// start in home
	cd_home_function();
	// // print path
	// lineHeaderPath();
}


int getCommand() {
	// error
	if(yyparse()) {
		return ERRORS;
	} 
	// ok
	else {
		return OK;
	}
}

void processCommand() {
	
	if(builtin_type > 0)
		do_it();
	// take care of all possible cases (redirections and pipes)
	else if(piped) {
		execute_pipes();
		piped = FALSE;
	}
	else
		execute();
}

void do_it() {
	switch (builtin_type) {
		case ALIAS_DEF:
			alias_function(variable, word);
			break;
		case ALIASPRINT_DEF:
			alias_print_function();
			break;
		case CDHOME_DEF:
			cd_home_function();
			break;
		case CDPATH_DEF:
			cd_function(cdPath);
			break;
		case UNALIAS_DEF:
			unalias_function(variable, 1);
			break;
		case SETENV_DEF:
			setenv_function(variable, word, 1);	
			break;
		case UNSETENV_DEF:
			unsetenv_function(variable, 1);
			break;
		case PRINTENV_DEF: 
			printenv_function();
			break;
		default:
			break;
	}
	// reset to 0
	builtin_type = 0;
}


void insertToWordTable(char *text) {
	char * word = strdup(text);
	char **tempWordArray = (char **) malloc((wordCount+2)*sizeof(char *)); //null entry and new word

	memcpy ((char *) tempWordArray, (char *) wordArray, wordCount*sizeof(char *)); //copy all entries from wordArray into tempWordArray
	tempWordArray[wordCount]   = word; //word
	tempWordArray[++wordCount] = NULL; //null entry
	wordArray = tempWordArray;
}

char* getDirectories(char* textmatch) {
	int i;
	int flags = 0;
	glob_t *results;
	int ret;
	DIR *dir;
	struct dirent *ent;
	results = malloc(10 * sizeof(glob_t));
	if(results == (glob_t*) NULL) {//error
		perror("Memory allocation error.");
		printf("Error at line %d\n", __LINE__);
		return;
	}
	if ((dir = opendir(getenv("PWD"))) != NULL) {
		/* print all the files and directories within directory */
		while ((ent = readdir (dir)) != NULL) {
			flags |= (i > 1 ? GLOB_APPEND : 0);
			ret = glob(textmatch, flags, globerr, results); //glob expression
			if (ret != 0) {//error
				printf("Error with globbing\n");
				printf("Error at line %d\n", __LINE__);
				return "";
			}
		}
		int size = 0;
		for(i = 0; i < results->gl_pathc; i++) {
			size += strlen(results->gl_pathv[i]) + 1;
		}
		char* result = malloc(size * sizeof(char));
		if(result == (char*) NULL) { //error
			perror("Memory allocation error.");
			printf("Error at line %d\n", __LINE__);
			return;
		}
		strcpy(result, "");
		for(i = 0; i < results->gl_pathc; i++) {
			strcat(result, results->gl_pathv[i]);
			strcat(result, "$");
		}
		result[strlen(result) - 1] = '\0'; //null terminate
		globfree(results); //free glob expression
		closedir(dir); //close directory 
		return result;
	}
	else {
		/* could not open directory */
		perror ("Cannot open directory");
		printf("Error at line %d\n", __LINE__);
		return "";
	}
	return "";
}

int globerr(const char *path, int eerrno) {//error
	perror ("Error with globbing\n");
	printf ("Error with path %s at line %d\n", path, __LINE__);
	return 0;	/* let glob() keep going */
}

void quoteFunction(char* text) {
	condenseSpaces(text);
	char* actualText = malloc(300 * sizeof(char));
	if(actualText == (char*) NULL) {//error
		perror ("Memory allocation error.");
		printf ("Error at line %d\n", __LINE__);
		return;
	}
	strncpy(actualText, &text[1], strlen(text) - 2); //everything between quotes
	char* result = malloc(300 * sizeof(char));
	if (result == (char*) NULL) {//error
		perror ("Memory allocation error.");
		printf ("Error at line %d\n", __LINE__);
		return;
	}
	int index = 0;
	int i;
	int* results = malloc(300 * sizeof(int));
	int resultCount = 0;
	int opens = 0;
	int ends = 0;
	if (results == (int*) NULL) {//error
		perror ("Memory allocation error.");
		printf ("Error at line %d\n", __LINE__);
		return;
	}
	
	// Environment variable expansion
	for(i = 0; i < strlen(actualText); i ++) {
		if(actualText[i] == '$' && actualText[i + 1] == '{') { //opener
			index = i;
			results[resultCount] = index;
			resultCount++;
			opens++;
		}
		if(actualText[i] == '}') {//closer
			index = i;
			results[resultCount] = index;
			resultCount++;
			ends++;
		}
		if(ends > opens) { //incorrect input
			perror ("Error with input.");
			printf ("Error at line %d\n", __LINE__);
			return;
		}
	}
	if(opens != ends) {//not balanced
		perror ("Syntax error");
		printf ("Error at line %d\n", __LINE__);
		return;
	}
	char *result2 = malloc(300 * sizeof(char));
	if(result2 == (char*) NULL) { //error
		perror ("Memory allocation error.");
		printf ("Error at line %d\n", __LINE__);
		return;
	}
	if(resultCount == 0) {//no opens or ends
		insertToWordTable(actualText);
	}
	else {//opens and ends
		strcpy(result2, "");
		char* result3 = malloc(300 * sizeof(char));
		if(result3 == (char*) NULL) { //error
			perror ("Memory allocation error.");
			printf ("Error at line %d\n", __LINE__);
			return;
		}
		for(i = 0; i < resultCount; i++) {
			if(i == 0) {//first open
				strncat(result2, &actualText[0], results[0]); //add the beginning
				memcpy(result3, &actualText[results[0] + 2], (results[1] - results[0] - 2) * sizeof(char));
				if(getenv(result3) == NULL) {//invalid environment variable
					perror ("Entered an invalid environment variable.");
					printf ("Error at line %d\n", __LINE__);
					return;
				}
				strcpy(result3, getenv(result3));
				strcat(result2, result3);
				memset(result3, 0, sizeof(result3)); //clear buffer
			}
			else if(i % 2 == 0 && i != 0) {//other opens
				strncat(result2, &actualText[results[i - 1] + 1], results[i] - results[i - 1] - 1);
				strncpy(result3, &actualText[results[i] + 2], (results[i + 1] - results[i] - 2) * sizeof(char));
				if(getenv(result3) == NULL) {
					perror ("Entered an invalid environment variable.");
					printf ("Error at line %d\n", __LINE__);
					return;
				}
				strcpy(result3,getenv(result3));
				strcat(result2, result3);
				memset(result3, 0, sizeof(result3)); //clear buffer
			}
			else {
				//do nothing
			}
		}
		if(results[resultCount - 1] != strlen(actualText) - 1) {//more left
			strcat(result2, &actualText[results[resultCount - 1] + 1]); //add all the leftovers
			insertToWordTable(result2);
		}
		else {
			insertToWordTable(result2);
		}
	}
}

void yytextProcessor(char* text) {
	char* result2 = malloc(300 * sizeof(char));
	
	char* pch = strtok(text, ":"); //colon-separate
	strcpy(result2, "");
	while(pch != NULL) {
		char* result = malloc(300 * sizeof(char));
		strcpy(result, tildeExpansion(pch)); //get result of tilde expansion and reset
		strcat(result2, result);
		strcat(result2, ":"); //add colon
		pch = strtok(NULL, ":");
	}
	
	result2[strlen(result2) - 1] = '\0'; //remove last colon
	insertToWordTable(result2);
}

char* tildeExpansion(char* text) {

	if(strncmp(text, "~", 1) == 0) {//tilde expansion
		int length = strlen(&text[1]); 
		if(length == 0) {//empty afterwards, so get home directory
			int result = chdir(myHome); //get home directory and move to it
			if(result == -1) { //error
				perror("Directory not changed");
				printf("Error at line %d\n", __LINE__);
				return;
			}
			return myHome;
		}
		else { //actual expansion
			char *result = strchr(&text[1], '/');
			if (result == NULL) {//end of string, so must be username
				pwd = getpwnam(&text[1]); //gets user info
				if (pwd == NULL) {//error
					perror("Error with getting struct.");
					printf("Error at line %d\n", __LINE__);
					return;
				}
				int result = chdir(pwd->pw_dir); //get home directory and move to it
				if(result == -1) {//error
					perror("Directory not changed");
					printf("Error at line %d\n", __LINE__);
					return;
				}
				return pwd->pw_dir; //username
			}
			else {//string continues
				char *directory = malloc(300 * sizeof(char));
				strcpy(directory, myHome); //start with home directory
				int index = length - 1;
				int i;
				for(i = 0; i < length; i++)	{
					if(text[i] == '/') {//find slash
						index = i;
						break;
					}
				}
				char *toadd = malloc(300 * sizeof(char));
				if(toadd == (char *) NULL) {
					perror("Memory allocation error.");
					printf("Error at line %d\n", __LINE__);
					return;
				}
				strcpy(toadd, &text[index + 1]); //add everything after /
				strcat(directory, "/"); //add slash
				strcat(directory, toadd); //append
				return directory;
			}
		}
	}
	else {//no tilde
		return text;
	}
}

/* removes extra spaces in the word */
void condenseSpaces(char* string) { 
	int i = 0;
	int size = strlen(string);
	while( i < size ) {
		if(string[i] == ' ' && string[i+1] == ' ') {
			int j = i;
			while (j <= size) {
				string[j] = string[++j];
			}
			--size;
		}
		else {
			++i;
		}
	}
}

void reset() {
	if(dup2(savedInput, 0) == -1) {//error
		perror("Input not redirected");
		printf("Error at line %d\n", __LINE__);
		return;
	}
	if(dup2(savedOutput, 1) == -1) {//error
		perror("Output not redirected");
		printf("Error at line %d\n", __LINE__);
		return;
	}
	if(dup2(savedError, 2) == -1) { //error
		perror("Error not redirected");
		printf("Error at line %d\n", __LINE__);
		return;
	}
	wordCount = 0;
	addedWords = 0;
	memset(wordArray, 0, sizeof(wordArray)); //clear contents
}

void cardsGoneWild(char* text, int position) {
	char* saveptr;
	char* result = strdup(text);
	char* result2 = strdup(text);
	char* filesList = strtok_r(result, "$", &saveptr); //parse to get each indiviual file
	
	
	// how many positions we add
	int tokens = 0; 
	while(filesList != NULL) {
		tokens++;
		filesList = strtok_r(NULL, "$", &saveptr);
	}

	//  create temp table
	char **tempWordArray = (char **) malloc((wordCount+tokens)*sizeof(char *)); 

	// copy all entries from 0 to position of wordArray into tempWordArray
	memcpy ((char *) tempWordArray, (char *) wordArray, position*sizeof(char *)); 

	char** textForLater = malloc((wordCount - position) * sizeof(char *)); // text we add at the end of the wordArray

	int i;
	int index = 0;
	for(i = position + 1; i < wordCount; ++i) {
		textForLater[index] = malloc((strlen(wordArray[i]) + 1) * sizeof(char)); // allocate enough space for entry

		strcpy(textForLater[index], wordArray[i]); //copy entry into array
		index++;
	}


	char* saveptr2;
	char* filesList2 = strtok_r(result2, "$", &saveptr2);
	int j = 0;
	wordCount--; //since we are overwriting an entry, need to decrement wordCount beforehand
	while(filesList2 != NULL) {
		char* es;
		es = malloc(strlen(filesList2) + 1); //allocate space for word and terminating character

		strcpy(es, filesList2); //copy text into pointer
		tempWordArray[position + j] = es; //word
		++j; //move forward
		++wordCount; //added another word
		filesList2 = strtok_r(NULL, "$", &saveptr2);
	}
	int k;
	index = 0;
	for(k = position + j; k < wordCount; k++) {
		tempWordArray[k] = malloc((strlen(textForLater[index]) + 1)*sizeof(char)); //allocate space

		strcpy(tempWordArray[k], textForLater[index]); //copy over
		index++; //move to next entry
	}
	tempWordArray[wordCount + 1] = NULL; //null entry
	wordArray = tempWordArray;
	addedWords += j - 1; //how many wordCount we added
}

void processEnvironmentVariable(char* yyText) {
	char* insideText = malloc(300 * sizeof(char));
	strncpy(insideText, &yyText[2], strlen(yyText) - 3); //take everything between ${ and }
	char* result = malloc(300 * sizeof(char));
	if(getenv(insideText) == NULL) //invalid environment variable
	{
		perror ("Entered an invalid environment variable.");
		printf ("Error at line %d\n", __LINE__);
	}
	else
	{
		insertToWordTable( getenv(actualText));
	}	
}

void printWordArray() {
	int i;
	for(i = 0; i < wordCount; i++) {
		printf("%s\n", wordArray[i]);
	}
}

void lineHeaderPath() {

	// get user
	struct passwd *passwd;
	passwd = getpwuid ( getuid()); 
	printf("[1;34;40m" "%s@", passwd->pw_name);	

	// get computer name
	char* hostName = malloc(300 * sizeof(char));
	gethostname(hostName, 20);
	printf("[1;34;40m" "%s:", hostName);

	// get path
	printf("[1;35;40m" "%s$ ", getenv("PWD"));

	// back to normal
	printf("[00;00;40m");
}

void condenseSlashes(char* string) { 
	int i = 0;
	int size = strlen(string);
	while ( i < size ){
		if(string[i] == '/' && string[i+1] == '/'){
			int j = i;
			while ( j <=size ){
				string[j] = string[++j];
			}
			--size;
		}
		else
			++i;
	}
}

int getWords() {
	return wordCount;
}

