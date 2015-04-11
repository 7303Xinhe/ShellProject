#include "shell.h"

#include "alias_functions.c"
#include "cd_functions.c"
#include "env_functions.c"
#include "error_functions.c"
#include "execute_function.c"

main() {
	shell_init();
	// loops till bye
	while(1) {
		// prepare parser
		textArray[0] = strdup("");
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

void processCommand() {
	
	if(builtin_type > 0)
		do_it();
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
	builtin_type = 0;
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

void shell_init() {
	// black background
	
	printf("[01;32;40m" "\n****************************** SHELL STARTS HERE *******************************\n\n");
	printf("[00;32;40m" "");

	textArray = (char**) malloc(500 * sizeof(char*));
	textArray[0] = strdup("");

	aliasCount = 0;
	wordCount = 0; //number of wordCount
	addedWords = 0;
	builtin_type = 0;
	cdPath = malloc(500 * sizeof(char));
	variable = malloc(500 * sizeof(char));
	word = malloc(500 * sizeof(char));


	myPath = malloc(500 * sizeof(char));
	if(myPath == (char *) NULL) { //error
		perror("Memory allocation error.");
		printf("Error at line %d\n", __LINE__);
		lineHeaderPath();
		return;
	}
	strcpy(myPath, getenv("PATH")); //get path directory so it stays constant
	myHome = malloc(500 * sizeof(char));
	if(myHome == (char *) NULL) { //error
		perror("Memory allocation error."); 
		printf("Error at line %d\n", __LINE__);
		lineHeaderPath();
		return;
	}
	strcpy(myHome, getenv("HOME")); //get home directory so that it stays constant
	//signal(SIGINT, SIG_IGN); //prevent crash from ctrl-c
	signal(SIGTSTP, SIG_IGN); //prevent crash from ctrl-z
	signal(SIGQUIT, SIG_IGN); //prevent crash from ctrl-/

	// start in home
	cd_home_function();
	// // print path
	// lineHeaderPath();
}


int write_to_function(char *text) {
	int out = open(text, O_WRONLY | O_CREAT | O_TRUNC | S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR); //open file
	if(out == -1) {//error
		perror("File not created");
		printf("Error at line %d\n", __LINE__);
		return -1;
	}
	savedOutput = dup(1); //get current output
	//redirect output to file
	if (dup2(out, 1) == -1) {//error
		perror("Output not redirected");
		printf("Error at line %d\n", __LINE__);
		return -1;
	}
	return 0;
}


int read_from_function (char *text) {
	int in = open(text, O_RDONLY); //open file
	if(in == -1) {//error
		perror("File not opened");
		printf("Error at line %d\n", __LINE__);
		return -1;
	}
	savedInput = dup(0); //get current input
	//redirect input from file
	if (dup2(in, 0) == -1) {//error
		perror("Input not redirected");
		printf("Error at line %d\n", __LINE__);
		return -1;
	}
	return 0;
}


void insertToWordTable(char *text) {
	char * es;
	es = malloc(strlen(text) + 1); //allocate space for word and terminating character
	if (es == NULL) {//error
		perror("Memory allocation error.");
		printf("Error at line %d\n", __LINE__);
		return;
	}
	strcpy(es, text); //copy text into pointer
	char **newTextArray = (char **) malloc((wordCount+2)*sizeof(char *)); //null entry and new word
	if ( newTextArray == (char **) NULL ) { //no array created
		perror("Array not created");
		printf("Error at line %d\n", __LINE__);
		return;
	}
	memcpy ((char *) newTextArray, (char *) textArray, wordCount*sizeof(char *)); //copy all entries from textArray into newTextArray
	newTextArray[wordCount]   = es; //word
	newTextArray[wordCount+1] = NULL; //null entry
	textArray = newTextArray;
	++wordCount; //increment index
}



int getWords() {
	return wordCount;
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
	if(result2 == (char*) NULL) {//error with memory allocation
		perror ("Memory allocation error.");
		printf ("Error at line %d\n", __LINE__);
		return;
	}
	char* pch = strtok(text, ":"); //colon-separate
	strcpy(result2, "");
	while(pch != NULL) {
		char* result = malloc(300 * sizeof(char));
		if(result == (char*) NULL) {//error with memory allocation
			perror ("Memory allocation error.");
			printf ("Error at line %d\n", __LINE__);
			return;
		}
		strcpy(result, tildeExpansion(pch)); //get result of tilde expansion and reset
		strcat(result2, result);
		strcat(result2, ":"); //add colon
		pch = strtok(NULL, ":");
	}
	result2[strlen(result2) - 1] = '\0'; //remove last colon
	insertToWordTable(result2);
}


char* tildeExpansion(char* text)
{
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
void condenseSpaces(char* string){ 
	int i = 0;
	int size = strlen(string);
	for(i = 0; i < size;) {
		if(string[i] == ' ' && string[i+1] == ' ') {
			int j = i + 1;
			for(j = i; j <=size; j++) {
				string[j] = string[j+1];
			}
			size--;
		}
		else {
			i++;
		}
	}
}

int append_function(char* text) {
	int out = open(text, O_RDWR | O_APPEND | S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR); //open file
	if(out == -1) { //error
		perror("File not created");
		printf("Error at line %d\n", __LINE__);
		return -1;
	}
	savedOutput = dup(1); //save current output
	//redirect output to file
	if (dup2(out, 1) == -1) {//error
		perror("Output not redirected");
		printf("Error at line %d\n", __LINE__);
		return -1;
	}
	return 0;
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
	memset(textArray, 0, sizeof(textArray)); //clear contents
}






void word3_function(char* text, int position) {
	char* saved3;
	char* result = malloc((strlen(text) + 1) * sizeof(char));
	if(result == (char*) NULL) { //error
		perror("Memory allocation error.");
		printf("Error at line %d\n", __LINE__);
		return;
	}
	strcpy(result, text);
	char* result2 = malloc((strlen(text) + 1) * sizeof(char));
	if(result2 == (char*) NULL) {//error
		perror("Memory allocation error.");
		printf("Error at line %d\n", __LINE__);
		return;
	}
	strcpy(result2, result); //copy another one since strtok_r changes actual text
	char* pch = strtok_r(result, "$", &saved3); //parse to get each indiviual file
	int tokens = 0; //how many positions we add
	while(pch != NULL) {
		tokens++;
		pch = strtok_r(NULL, "$", &saved3);
	}
	char **newTextArray = (char **) malloc((wordCount+tokens)*sizeof(char *)); //null entry and new wordCount
	if ( newTextArray == (char **) NULL ) { //no array created
		perror("Array not created");
		printf("Error at line %d\n", __LINE__);
		return;
	}
	memcpy ((char *) newTextArray, (char *) textArray, position*sizeof(char *)); //copy all entries from 0 to position of textArray into newTextArray
	char** textForLater = malloc((wordCount - position) * sizeof(char *)); //text we add at the end of the textArray
	if(textForLater == (char**)NULL) { //error
		perror("Array not created");
		printf("Error at line %d\n", __LINE__);
		return;
	}
	int i;
	int index = 0;
	for(i = position + 1; i < wordCount; i++) {
		textForLater[index] = malloc((strlen(textArray[i]) + 1) * sizeof(char)); //allocate enough space for entry
		if(textForLater[index] == (char*) NULL) { //error
			perror("Error with memory allocation");
			printf("Error at line %d\n", __LINE__);
			return;
		}
		strcpy(textForLater[index], textArray[i]); //copy entry into array
		index++;
	}
	char* saved4;
	char* pch2 = strtok_r(result2, "$", &saved4);
	int j = 0;
	wordCount--; //since we are overwriting an entry, need to decrement wordCount beforehand
	while(pch2 != NULL) {
		char* es;
		es = malloc(strlen(pch2) + 1); //allocate space for word and terminating character
		if (es == NULL) {//error
			perror("Memory allocation error.");
			printf("Error at line %d\n", __LINE__);
			return;
		}
		strcpy(es, pch2); //copy text into pointer
		newTextArray[position + j] = es; //word
		j++; //move forward
		wordCount++; //added another word
		pch2 = strtok_r(NULL, "$", &saved4);
	}
	int k;
	index = 0;
	for(k = position + j; k < wordCount; k++) {
		newTextArray[k] = malloc((strlen(textForLater[index]) + 1)*sizeof(char)); //allocate space
		if(newTextArray[k] == (char*) NULL) { //error
			perror("Memory allocation error.");
			printf("Error at line %d\n", __LINE__);
			return;
		}
		strcpy(newTextArray[k], textForLater[index]); //copy over
		index++; //move to next entry
	}
	newTextArray[wordCount + 1] = NULL; //null entry
	textArray = newTextArray;
	addedWords += j - 1; //how many wordCount we added
}

void printTextArray() {
	int i;
	for(i = 0; i < wordCount; i++) {
		printf("%s\n", textArray[i]);
	}
}


int spawn_proc (int inChannel, int outChannel, struct command *cmd) {
	pid_t pid;
	if ((pid = fork ()) == 0) { //in parents
    	if (inChannel != 0) {
			dup2 (inChannel, 0);
			close (inChannel);
		}
		if (outChannel != 1) {
			dup2 (outChannel, 1);
			close (outChannel);
		}
		return execvp (cmd->argv [0], (char * const *)cmd->argv);
    }
	return pid;
}
int fork_pipes (int n, struct command *cmd)
{
	int i;
	pid_t pid;
	int inChannel, fd [2];

	/* The first process should get its input from the original file descriptor 0.  */
	inChannel = 0;

	/* All but the last part of the pipeline.  */
	for (i = 0; i < n - 1; ++i) {
		pipe (fd);
		spawn_proc (inChannel, fd [1], cmd + i); //take in read end of previous iteration, goes to write end of next iteration
		/* Close redundant output.  */
		close (fd [1]);
		/* Need this for next iteration.  */
		inChannel = fd [0];
    }

    /* Last stage of the pipeline - set stdin be the read end of the previous pipe
    and output to the original file descriptor 1. */  
    if (inChannel != 0) {
		dup2 (inChannel, 0);
	}
	/* Execute the last stage with the current process. */
	return execvp (cmd [i].argv [0], (char * const *)cmd [i].argv);
}

void aliasToCd(char* text) {
	char* altered = malloc(300 * sizeof(char));
	altered = text;

	int i;
	for(i = 0; i < strlen(altered); ++i) {
		if(altered[i] == ' ') {
			strcpy(altered, &altered[i+1]);
			break;
		}

	}
	cd_function(altered);
}


void lineHeaderPath() {
	// char *folder = malloc(300 * sizeof(char));
	// folder = getenv("PWD");
	// int sizeString = strlen(folder);
	// int lastIndex = sizeString - 1;
	// int lastSlashIndex;
	// int i;
	// for(i = lastIndex; i >= 0; --i) {
	// 	if(folder[i] == '/') {
	// 		lastSlashIndex = i; //found last slash
	// 		break;
	// 	}
	// }
	
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


void condenseSlashes(char* string) { //removes extra slashes in the beginning of a string so ////home -> /home, ./////home -> ./home
	int i = 0;
	int size = strlen(string);
	for(i = 0; i < size;){
		if(string[i] == '/' && string[i+1] == '/'){
			int j = i + 1;
			for(j = i; j <=size; j++){
				string[j] = string[j+1];
			}
			size--;
		}
		else
			i++;
	}
}
