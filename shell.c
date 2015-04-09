#include "shell.h"
char** newTextArray; //copied words
int words = 0; //number of words
extern char** environ; //environment variables
char** aliases; //alias names and values
char** newAliases; //copied aliases
int aliasCount = 0; //number of aliases
struct passwd* pwd; //contains result of getpwnam
char* myPath;
char* myHome;
int savedOutput; //output channel
int savedInput; //input channel
int savedError; //error channel
int addedWords = 0;

#include "cd_functions.c"
#include "setenv_functions.c"
#include "alias_functions.c"

void shell_init()
{
	printf("\n********************** SHELL STARTS HERE **********************\n\n");

	myPath = malloc(500 * sizeof(char));
	if(myPath == (char *) NULL) //error
	{
		perror("Error with memory allocation.");
		printf("Error at line %d\n", __LINE__);
		lineHeaderPath();
		return;
	}
	strcpy(myPath, getenv("PATH")); //get path directory so it stays constant
	myHome = malloc(500 * sizeof(char));
	if(myHome == (char *) NULL) //error
	{
		perror("Error with 																																																														memory allocation.");
		printf("Error at line %d\n", __LINE__);
		lineHeaderPath();
		return;
	}
	strcpy(myHome, getenv("HOME")); //get home directory so that it stays constant
	signal(SIGINT, SIG_IGN); //prevent crash from ctrl-c
	signal(SIGTSTP, SIG_IGN); //prevent crash from ctrl-z
	signal(SIGQUIT, SIG_IGN); //prevent crash from ctrl-/

	// start in home
	cd_home_function();
	// print path
	lineHeaderPath();
}








int standard_error_redirect_function()
{
	savedError = dup(2); //get current standard error
	int result = dup2(1, 2); //redirect output to standard error
	if (result == -1) //error
	{
		perror("Standard error not redirected to output");
		printf("Error at line %d\n", __LINE__);
		return -1;
	}
	return 0;
}
int standard_error_redirect_function2(char *text)
{
	char* text2 = malloc(300 * sizeof(char));
	if (text2 == (char *)NULL) //error
	{
		perror("Error with memory allocation.");
		printf("Error at line %d\n", __LINE__);
		return -1;
	}
	strcpy(text2, &text[2]); //get everything after >
	int out = open(text2, O_WRONLY | O_CREAT | O_TRUNC | S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR); //open file
	if(out == -1) //error
	{
		perror("File not created");
		printf("Error at line %d\n", __LINE__);
		return -1;
	}
	savedError = dup(2); //get current standard error
	int result = dup2(out, 2); //redirect standard error to output file
	if (result == -1) //error
	{
		perror("Standard error not redirected");
		printf("Error at line %d\n", __LINE__);
		return -1;
	}
	return 0;
}
int write_to_function(char *text)
{
	int out = open(text, O_WRONLY | O_CREAT | O_TRUNC | S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR); //open file
	if(out == -1) //error
	{
		perror("File not created");
		printf("Error at line %d\n", __LINE__);
		return -1;
	}
	savedOutput = dup(1); //get current output
	int result = dup2(out, 1); //redirect output to file
	if (result == -1) //error
	{
		perror("Output not redirected");
		printf("Error at line %d\n", __LINE__);
		return -1;
	}
	return 0;
}
int read_from_function (char *text)
{
	int in = open(text, O_RDONLY); //open file
	if(in == -1) //error
	{
		perror("File not opened");
		printf("Error at line %d\n", __LINE__);
		return -1;
	}
	savedInput = dup(0); //get current input
	int result = dup2(in, 0); //redirect input from file
	if (result == -1) //error
	{
		perror("Input not redirected");
		printf("Error at line %d\n", __LINE__);
		return -1;
	}
	return 0;
}
void word_function(char *text)
{
	char * es;
	es = malloc(strlen(text) + 1); //allocate space for word and terminating character
	if (es == NULL) //error
	{
		perror("Error with memory allocation.");
		printf("Error at line %d\n", __LINE__);
		return;
	}
	strcpy(es, text); //copy text into pointer
	newTextArray = (char **) malloc((words+2)*sizeof(char *)); //null entry and new word
	if ( newTextArray == (char **) NULL ) //no array created
	{
		perror("Array not created");
		printf("Error at line %d\n", __LINE__);
		return;
	}
	memcpy ((char *) newTextArray, (char *) textArray, words*sizeof(char *)); //copy all entries from textArray into newTextArray
	newTextArray[words]   = es; //word
	newTextArray[words+1] = NULL; //null entry
	textArray = newTextArray;
	words++; //increment index
}
void printenv_function()
{
	char ** ep;
	for(ep = environ; *ep!= NULL; ep++)
	{
		printf("%s\n", *ep); //print everything line by line
	}
}


int getWords()
{
	return words;
}
char* getDirectories(char* textmatch)
{
	int i;
	int flags = 0;
	glob_t *results;
	int ret;
	DIR *dir;
	struct dirent *ent;
	results = malloc(10 * sizeof(glob_t));
	if(results == (glob_t*) NULL) //error
	{
		perror("Error with memory allocation.");
		printf("Error at line %d\n", __LINE__);
		return;
	}
	if ((dir = opendir(getenv("PWD"))) != NULL) 
	{
		/* print all the files and directories within directory */
		while ((ent = readdir (dir)) != NULL) 
		{
			flags |= (i > 1 ? GLOB_APPEND : 0);
			ret = glob(textmatch, flags, globerr, results); //glob expression
			if (ret != 0) //error
			{
				printf("Error with globbing\n");
				printf("Error at line %d\n", __LINE__);
				return "";
			}
		}
		int size = 0;
		for(i = 0; i < results->gl_pathc; i++)
		{
			size += strlen(results->gl_pathv[i]) + 1;
		}
		char* result = malloc(size * sizeof(char));
		if(result == (char*) NULL) //error
		{
			perror("Error with memory allocation.");
			printf("Error at line %d\n", __LINE__);
			return;
		}
		strcpy(result, "");
		for(i = 0; i < results->gl_pathc; i++)
		{
			strcat(result, results->gl_pathv[i]);
			strcat(result, "$");
		}
		result[strlen(result) - 1] = '\0'; //null terminate
		globfree(results); //free glob expression
		closedir(dir); //close directory 
		return result;
	}
	else 
	{
		/* could not open directory */
		perror ("Cannot open directory");
		printf("Error at line %d\n", __LINE__);
		return "";
	}
	return "";
}

int globerr(const char *path, int eerrno) //error
{
	perror ("Error with globbing\n");
	printf ("Error with path %s at line %d\n", path, __LINE__);
	return 0;	/* let glob() keep going */
}

void changeGroupedSlashesIntoOneSlash(char* string)
{ //removes extra slashes in the beginning of a string so ////home -> /home, ./////home -> ./home
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





void quoteFunction(char* text)
{
	changeGroupedSpacesIntoOneSpace(text);
	char* actualText = malloc(300 * sizeof(char));
	if(actualText == (char*) NULL) //error
	{
		perror ("Error with memory allocation.");
		printf ("Error at line %d\n", __LINE__);
		return;
	}
	strncpy(actualText, &text[1], strlen(text) - 2); //everything between quotes
	char* result = malloc(300 * sizeof(char));
	if (result == (char*) NULL) //error
	{
		perror ("Error with memory allocation.");
		printf ("Error at line %d\n", __LINE__);
		return;
	}
	int index = 0;
	int i;
	int* results = malloc(300 * sizeof(int));
	int resultCount = 0;
	int opens = 0;
	int ends = 0;
	if (results == (int*) NULL) //error
	{
		perror ("Error with memory allocation.");
		printf ("Error at line %d\n", __LINE__);
		return;
	}
	for(i = 0; i < strlen(actualText); i ++)
	{
		if(actualText[i] == '$' && actualText[i + 1] == '{') //opener
		{
			index = i;
			results[resultCount] = index;
			resultCount++;
			opens++;
		}
		if(actualText[i] == '}') //closer
		{
			index = i;
			results[resultCount] = index;
			resultCount++;
			ends++;
		}
		if(ends > opens) //incorrect input
		{
			perror ("Error with input.");
			printf ("Error at line %d\n", __LINE__);
			return;
		}
	}
	if(opens != ends) //not balanced
	{
		perror ("Syntax error");
		printf ("Error at line %d\n", __LINE__);
		return;
	}
	char *result2 = malloc(300 * sizeof(char));
	if(result2 == (char*) NULL) //error
	{
		perror ("Error with memory allocation.");
		printf ("Error at line %d\n", __LINE__);
		return;
	}
	if(resultCount == 0) //no opens or ends
	{
		word_function(actualText);
	}
	else //opens and ends
	{
		strcpy(result2, "");
		char* result3 = malloc(300 * sizeof(char));
		if(result3 == (char*) NULL) //error
		{
			perror ("Error with memory allocation.");
			printf ("Error at line %d\n", __LINE__);
			return;
		}
		for(i = 0; i < resultCount; i++)
		{
			if(i == 0) //first open
			{
				strncat(result2, &actualText[0], results[0]); //add the beginning
				memcpy(result3, &actualText[results[0] + 2], (results[1] - results[0] - 2) * sizeof(char));
				if(getenv(result3) == NULL) //invalid environment variable
				{
					perror ("Entered an invalid environment variable.");
					printf ("Error at line %d\n", __LINE__);
					return;
				}
				strcpy(result3, getenv(result3));
				strcat(result2, result3);
				memset(result3, 0, sizeof(result3)); //clear buffer
			}
			else if(i % 2 == 0 && i != 0) //other opens
			{
				strncat(result2, &actualText[results[i - 1] + 1], results[i] - results[i - 1] - 1);
				strncpy(result3, &actualText[results[i] + 2], (results[i + 1] - results[i] - 2) * sizeof(char));
				if(getenv(result3) == NULL)
				{
					perror ("Entered an invalid environment variable.");
					printf ("Error at line %d\n", __LINE__);
					return;
				}
				strcpy(result3,getenv(result3));
				strcat(result2, result3);
				memset(result3, 0, sizeof(result3)); //clear buffer
			}
			else
			{
				//do nothing
			}
		}
		if(results[resultCount - 1] != strlen(actualText) - 1) //more left
		{
			strcat(result2, &actualText[results[resultCount - 1] + 1]); //add all the leftovers
			word_function(result2);
		}
		else
		{
			word_function(result2);
		}
	}
}
void word2Function(char* text)
{
	char* result2 = malloc(300 * sizeof(char));
	if(result2 == (char*) NULL) //error with memory allocation
	{
		perror ("Error with memory allocation.");
		printf ("Error at line %d\n", __LINE__);
		return;
	}
	char* pch = strtok(text, ":"); //colon-separate
	strcpy(result2, "");
	while(pch != NULL) 
	{
		char* result = malloc(300 * sizeof(char));
		if(result == (char*) NULL) //error with memory allocation
		{
			perror ("Error with memory allocation.");
			printf ("Error at line %d\n", __LINE__);
			return;
		}
		strcpy(result, tildeExpansion(pch)); //get result of tilde expansion and reset
		strcat(result2, result);
		strcat(result2, ":"); //add colon
		pch = strtok(NULL, ":");
	}
	result2[strlen(result2) - 1] = '\0'; //remove last colon
	word_function(result2);
}
char* tildeExpansion(char* text)
{
	if(strncmp(text, "~", 1) == 0) //tilde expansion
	{
		int length = strlen(&text[1]); 
		if(length == 0) //empty afterwards, so get home directory
		{
			int result = chdir(myHome); //get home directory and move to it
			if(result == -1) //error
			{
				perror("Directory not changed");
				printf("Error at line %d\n", __LINE__);
				return;
			}
			return myHome;
		}
		else //actual expansion
		{
			char *result = strchr(&text[1], '/');
			if (result == NULL) //end of string, so must be username
			{
				pwd = getpwnam(&text[1]); //gets user info
				if (pwd == NULL) //error
				{
					perror("Error with getting struct.");
					printf("Error at line %d\n", __LINE__);
					return;
				}
				int result = chdir(pwd->pw_dir); //get home directory and move to it
				if(result == -1) //error
				{
					perror("Directory not changed");
					printf("Error at line %d\n", __LINE__);
					return;
				}
				return pwd->pw_dir; //username
			}
			else //string continues
			{
				char *directory = malloc(300 * sizeof(char));
				strcpy(directory, myHome); //start with home directory
				int index = length - 1;
				int i;
				for(i = 0; i < length; i++)
				{
					if(text[i] == '/') //find slash
					{
						index = i;
						break;
					}
				}
				char *toadd = malloc(300 * sizeof(char));
				if(toadd == (char *) NULL)
				{
					perror("Error with memory allocation.");
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
	else //no tilde
	{
		return text;
	}
}
void changeGroupedSpacesIntoOneSpace(char* string)
{ //removes extra spaces in the word so that each word has one space between it
	int i = 0;
	int size = strlen(string);
	for(i = 0; i < size;)
	{
		if(string[i] == ' ' && string[i+1] == ' ')
		{
			int j = i + 1;
			for(j = i; j <=size; j++)
			{
				string[j] = string[j+1];
			}
			size--;
		}
		else
		{
			i++;
		}
	}
}
int append_function(char* text)
{
	int out = open(text, O_RDWR | O_APPEND | S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR); //open file
	if(out == -1) //error
	{
		perror("File not created");
		printf("Error at line %d\n", __LINE__);
		return -1;
	}
	savedOutput = dup(1); //save current output
	int result = dup2(out, 1); //redirect output to file
	if (result == -1) //error
	{
		perror("Output not redirected");
		printf("Error at line %d\n", __LINE__);
		return -1;
	}
	return 0;
}
void reset()
{
	int result = dup2(savedInput, 0);
	if(result == -1) //error
	{
		perror("Input not redirected");
		printf("Error at line %d\n", __LINE__);
		return;
	}
	result = dup2(savedOutput, 1);
	if(result == -1) //error
	{
		perror("Output not redirected");
		printf("Error at line %d\n", __LINE__);
		return;
	}
	result = dup2(savedError, 2);
	if(result == -1) //error
	{
		perror("Error not redirected");
		printf("Error at line %d\n", __LINE__);
		return;
	}
	words = 0;
	addedWords = 0;
	memset(textArray, 0, sizeof(textArray)); //clear contents
}
void execute()
{
	int numberOfPipes = 0;
	int numberOfCommands = 0;
	int i;
	int indexOfRead = 0;
	int indexOfWrite = 0;
	int indexOfAppend = 0;
	int indexOfStandardError1 = 0;
	int indexOfStandardError2 = 0;
	int indexOfAmpersand = 0; 
	int endOfCommand = 0;
	int numberOfSpaces = 0;
	int numberOfGlobs = 0;
	int child;
	if((child = fork()) == -1) //error
	{
		perror("Error forking");
		printf("Error at line %d\n", __LINE__);
		reset();
		exit(0);
		return;
	}	
	if(child != 0) //in parent
	{
		if(indexOfAmpersand == 0) //wait for process to finish executing
		{
			wait((int *) 0);
		}
		reset();
	}
	else //in child
	{
		if(strcmp(textArray[0], "echo") == 0 && strcmp(textArray[1], "-e") != 0) //echo command without -e
		{
			char* result = malloc((strlen(textArray[1]) + 1) * sizeof(char));
			if(result == (char*)NULL)
			{
				perror("Error with memory allocation.");
				printf("Error at line %d\n", __LINE__);
				reset();
				exit(0);
				return;
			}
			strcpy(result, fixText(textArray[1], "\\\\", "\\"));
			strcpy(textArray[1], result);
			strcpy(result, fixText(textArray[1], "\\\"", "\""));
			strcpy(textArray[1], result);
		}
		int* spaces = malloc(300 * sizeof(int));
		if(spaces == (int*) NULL) //error
		{
			perror("Error with memory allocation.");
			printf("Error at line %d\n", __LINE__);
			reset();
			exit(0);
			return;
		}
		for(i = 0; i < words; i++)
		{
			if(strchr(textArray[i], ' ') != NULL) //there's a space
			{
				spaces[numberOfSpaces] = i;
				numberOfSpaces++;
			}
		}
		for(i = 0; i < numberOfSpaces; i++)
		{
			char ** ep;
			int index;
			int j;
			for(ep = environ; *ep!= NULL; ep++)
			{
				char* theVariable = malloc((strlen(*ep) + 1) * sizeof(char));
				if(theVariable == (char*) NULL) //error
				{
					perror("Error with memory allocation.");
					printf("Error at line %d\n", __LINE__);
					reset();
					exit(0);
					return;
				}
				strcpy(theVariable, *ep); //copy environment variable
				for(j = 0; j < strlen(theVariable); j++)
				{
					if(theVariable[j] == '=') //found =
					{
						index = j;
						break;
					}
				}
				char* result = malloc((strlen(theVariable) - index + 1) * sizeof(char));
				if(result == (char*) NULL) //error
				{
					perror("Error with memory allocation.");
					printf("Error at line %d\n", __LINE__);
					reset();
					exit(0);
					return;
				}
				strcpy(result, &theVariable[index + 1]); //take everything after =
				if(strcmp(textArray[spaces[i]], result) == 0) //there's a match
				{
					textArrayAliasExpansion(textArray[spaces[i] + addedWords], spaces[i] + addedWords); //expand to get rid of spaces
					break;
				}
			}
		}
		int* pipes = malloc(300 * sizeof(int));
		if(pipes == (int*) NULL) //error
		{
			perror("Error with memory allocation.");
			printf("Error at line %d\n", __LINE__);
			reset();
			exit(0);
			return;
		}
		int* globs = malloc(300 * sizeof(int));
		if(globs == (int*) NULL) //error
		{
			perror("Error with memory allocation.");
			printf("Error at line %d\n", __LINE__);
			reset();
			exit(0);
			return;
		}
		addedWords = 0;
		for(i = 0; i < words; i++)
		{
			if(strcmp(textArray[i], "|") == 0) //it's a pipe
			{
				pipes[numberOfPipes] = i;
				numberOfPipes++;
			}
		}
		numberOfCommands = numberOfPipes + 1;
		for(i = 0; i < numberOfCommands; i++)//resolves aliases
		{
			if(i == 0)
			{
				if(strcmp(aliasResolve(textArray[i]), "<LOOP>") == 0) //infinite alias expansion
				{
					perror("Infinite alias expansion.");
					printf("Error at line %d\n", __LINE__);
					reset();
					exit(0);
					return;
				}
				else if(strcmp(aliasResolve(textArray[i]), "") != 0) //alias has a value
				{	
					char* resolved = malloc((strlen(aliasResolve(textArray[i])) + 1) * sizeof(char));
					strcpy(resolved,aliasResolve(textArray[i]));
					textArray[i] = resolved;
					textArrayAliasExpansion(textArray[i], i + addedWords);
				}
			}
			else{
				int j;
				if(strcmp(aliasResolve(textArray[pipes[i - 1] + 1]), "<LOOP>") == 0) //infinite alias expansion
				{
					perror("Infinite alias expansion.");
					printf("Error at line %d\n", __LINE__);
					reset();
					exit(0);
					return;
				}
				else if(strcmp(aliasResolve(textArray[pipes[i - 1] + 1 + addedWords]), "") != 0) //alias has a value
				{
					char* resolved = malloc((strlen(aliasResolve(textArray[pipes[i - 1] + 1 + addedWords]) + 1) * sizeof(char)));
					strcpy(resolved,aliasResolve(textArray[pipes[i - 1] + 1 + addedWords]));
					textArray[pipes[i - 1] + 1 + addedWords] = resolved;
					textArrayAliasExpansion(textArray[pipes[i - 1] + 1 + addedWords], pipes[i - 1] + 1 + addedWords);
				}
			}
		}
		numberOfGlobs = 0;
		addedWords = 0;
		for(i = 0; i < words; i++)
		{
			if(strchr(textArray[i], '*') != NULL || strchr(textArray[i], '?') != NULL) //contains a * or ?
			{
				globs[numberOfGlobs] = i;
				numberOfGlobs++;
			}
		}
		char* saved3;
		for(i = 0; i < numberOfGlobs; i++)//takes care of globbing
		{
			if(i == 0)
			{
				printf(" ");
			}
			char* result = malloc((strlen(getDirectories(textArray[globs[i] + addedWords])) + 1)* sizeof(char));
			if(result == (char*) NULL) //error
			{
				perror("Error with memory allocation.");
				printf("Error at line %d\n", __LINE__);
				reset();
				exit(0);
				return;
			}
			strcpy(result, getDirectories(textArray[globs[i] + addedWords]));
			if(strcmp(result, "") == 0) //error
			{
				perror("No matches, so not executing.");
				printf("Error at line %d\n", __LINE__);
				reset();
				exit(0);
				return;
			}
			word3_function(result, globs[i] + addedWords);
		}
		numberOfPipes = 0;
		for(i = 0; i < words; i++)
		{
			if(strcmp(textArray[i], "|") == 0) //it's a pipe
			{
				pipes[numberOfPipes] = i;
				numberOfPipes++;
			}
			if(strcmp(textArray[i], "<") == 0) //read in
			{
				indexOfRead = i;
			}
			if(strcmp(textArray[i], ">") == 0) //write to
			{
				indexOfWrite = i;
			}
			if(strcmp(textArray[i], ">>") == 0) //append
			{
				indexOfAppend = i;
			}
			if(strcmp(textArray[i], "2>&1") == 0) //standard error redirect 2
			{
				indexOfStandardError2 = i;
			}
			else if(strcmp(textArray[i], "2>") == 0) //standard error redirect 1
			{
				indexOfStandardError1 = i;
			}
			if(strcmp(textArray[i], "&") == 0) //ampersand
			{
				indexOfAmpersand = i;
			}
		}
		if(indexOfRead != 0) //there's a read present
		{
			int result = read_from_function(textArray[indexOfRead + 1]); 
			if(result == -1)
			{
				reset();
				exit(0);
				return;
			}
		}
		if(indexOfWrite != 0) //there's a write to present
		{
			int result = write_to_function(textArray[indexOfWrite + 1]);
			if(result == -1)
			{
				reset();
				exit(0);
				return;
			}
		}
		if (indexOfAppend != 0) //there's an append present
		{
			int result = append_function(textArray[indexOfAppend + 1]);
			if(result == -1)
			{
				reset();
				exit(0);
				return;
			}
		}
		if(indexOfStandardError2 != 0) //second standard error case present
		{
			int result = standard_error_redirect_function();
			if(result == -1)
			{
				reset();
				exit(0);
				return;
			}
		}
		if(indexOfStandardError1 != 0) //first standard error case present
		{
			int result = standard_error_redirect_function2(textArray[indexOfStandardError2]);
			if(result == -1)
			{
				reset();
				exit(0);
				return;
			}
		}
		numberOfCommands = numberOfPipes + 1;
		if(numberOfPipes == 0) //no pipes, just this command
		{
			if(indexOfRead != 0) //take everything up until this 
			{
				endOfCommand = indexOfRead;
			}
			else if(indexOfWrite != 0) //no read from
			{
				endOfCommand = indexOfWrite;
			}
			else if(indexOfAppend != 0) //no read from
			{
				endOfCommand = indexOfAppend;
			}
			else if(indexOfStandardError2 != 0) //no other I/O redirection
			{
				endOfCommand = indexOfStandardError2;
			}
			else if(indexOfStandardError1 != 0) //no other I/O redirection
			{
				endOfCommand = indexOfStandardError1;
			}
			else if(indexOfAmpersand != 0) //no I/O redirection
			{
				endOfCommand = indexOfAmpersand;
			}
			else //just a command with no special components
			{ 
				endOfCommand = words;
			}
			char* result = malloc(300 * sizeof(char));
			if(result == (char*) NULL) //error
			{
				perror("Error with memory allocation.");
				printf("Error at line %d\n", __LINE__);
				reset();
				exit(0);
				return;
			}
			char* arguments[endOfCommand + 1];
			int i;
			for(i = 0; i < endOfCommand; i++)
			{
				arguments[i] = textArray[i]; //copy arguments
			}
			arguments[endOfCommand] = (char *)0; //null terminator
			int result2 = execvp(arguments[0], arguments);
			if(result2 == -1) //error
			{
				perror("Error executing.");
				printf("Error at line %d\n", __LINE__);
				reset();
				exit(0);
				return;
			}
		}
		else //perform piping
		{
			if(indexOfRead != 0) //take everything up until this 
			{
				endOfCommand = indexOfRead;
			}
			else if(indexOfWrite != 0) //no read from
			{
				endOfCommand = indexOfWrite;
			}
			else if(indexOfAppend != 0) //no read from
			{
				endOfCommand = indexOfAppend;
			}
			else if(indexOfStandardError2 != 0) //no other I/O redirection
			{
				endOfCommand = indexOfStandardError2;
			}
			else if(indexOfStandardError1 != 0) //no other I/O redirection
			{
				endOfCommand = indexOfStandardError1;
			}
			else if(indexOfAmpersand != 0) //no I/O redirection
			{
				endOfCommand = indexOfAmpersand;
			}
			else //just a command with no special components
			{ 
				endOfCommand = words;
			}
			struct command* cmd = malloc(numberOfCommands * sizeof(struct command));
			for(i = 0; i < numberOfCommands; i++)
			{
				if(i == 0) //first command
				{
					char* arguments [pipes[0] + 1];
					int j = 0;
					for(j = 0; j < pipes[0]; j++)
					{
						arguments[j] = textArray[j]; //copy arguments
					}
					arguments[pipes[0]] = (char*)0; //null terminator
					cmd[0].argv = malloc(j*sizeof(char*));
					if(cmd[0].argv == (char**)NULL) //error
					{
						perror("Error with memory allocation.");
						printf("Error at line %d\n", __LINE__);
						reset();
						exit(0);
						return;
					}
					int k = 0;
					for(k = 0; k < j; k++){
						cmd[0].argv[k] = malloc((strlen(arguments[k]) + 1) * sizeof(char));
						if(cmd[0].argv[k] == (char*) NULL) //error
						{
							perror("Error with memory allocation.");
							printf("Error at line %d\n", __LINE__);
							reset();
							exit(0);
							return;
						}
						strcpy(cmd[0].argv[k], arguments[k]);
					}
					cmd[0].argv[j] = (char*) 0;
				}
				else if(i != (numberOfCommands - 1)) //in the middle
				{
					char* arguments[pipes[i] - pipes[i - 1]];
					int j;
					for(j = 0; j < pipes[i] - pipes[i - 1] - 1; j++)
					{
						arguments[j] = textArray[pipes[i - 1] + 1 + j]; //copy arguments
					}
					arguments[pipes[i] - pipes[i - 1] - 1] = (char *)0; //null terminator
					cmd[i].argv = malloc(j*sizeof(char*));
					if(cmd[i].argv == (char**)NULL) //error
					{
						perror("Error with memory allocation.");
						printf("Error at line %d\n", __LINE__);
						reset();
						exit(0);
						return;
					}
					int k = 0;
					for(k = 0; k < j; k++){
						cmd[i].argv[k] = malloc((strlen(arguments[k]) + 1) * sizeof(char));
						if(cmd[i].argv[k] == (char*) NULL) //error
						{
							perror("Error with memory allocation.");
							printf("Error at line %d\n", __LINE__);
							reset();
							exit(0);
							return;
						}
						strcpy(cmd[i].argv[k], arguments[k]);
					}
					cmd[i].argv[j] = (char*) 0;
				}
				else //at the end
				{
					char* arguments[endOfCommand - pipes[i - 1]];
					int j;
					for(j = 0; j < endOfCommand - pipes[i - 1] - 1; j++)
					{
						arguments[j] = textArray[pipes[i - 1] + 1 + j]; //copy arguments
					}
					arguments[endOfCommand - pipes[i - 1] - 1] = (char *)0; //null terminator
					cmd[numberOfCommands - 1].argv = malloc(j*sizeof(char*));
					if(cmd[numberOfCommands - 1].argv == (char**) NULL) //error
					{
						perror("Error with memory allocation.");
						printf("Error at line %d\n", __LINE__);
						reset();
						exit(0);
						return;
					}
					int k = 0;
					for(k = 0; k < j; k++){
						cmd[numberOfCommands - 1].argv[k] = malloc((strlen(arguments[k]) + 1) * sizeof(char));
						if(cmd[numberOfCommands - 1].argv[k] == (char*) NULL) //error
						{
							perror("Error with memory allocation.");
							printf("Error at line %d\n", __LINE__);
							reset();
							exit(0);
							return;
						}
						strcpy(cmd[numberOfCommands - 1].argv[k], arguments[k]);
					}
					cmd[numberOfCommands - 1].argv[j] = (char*) 0;
				}		
			}
			int result = fork_pipes(numberOfCommands, cmd);
			if(result == -1) //error
			{
				perror("Error executing.");
				printf("Error at line %d\n", __LINE__);
				reset();
				exit(0);
				return;
			}
		}
		exit(0);
	}
}
void word3_function(char* text, int position)
{
	char* saved3;
	char* result = malloc((strlen(text) + 1) * sizeof(char));
	if(result == (char*) NULL) //error
	{
		perror("Error with memory allocation.");
		printf("Error at line %d\n", __LINE__);
		return;
	}
	strcpy(result, text);
	char* result2 = malloc((strlen(text) + 1) * sizeof(char));
	if(result2 == (char*) NULL) //error
	{
		perror("Error with memory allocation.");
		printf("Error at line %d\n", __LINE__);
		return;
	}
	strcpy(result2, result); //copy another one since strtok_r changes actual text
	char* pch = strtok_r(result, "$", &saved3); //parse to get each indiviual file
	int tokens = 0; //how many positions we add
	while(pch != NULL)
	{
		tokens++;
		pch = strtok_r(NULL, "$", &saved3);
	}
	newTextArray = (char **) malloc((words+tokens)*sizeof(char *)); //null entry and new words
	if ( newTextArray == (char **) NULL ) //no array created
	{
		perror("Array not created");
		printf("Error at line %d\n", __LINE__);
		return;
	}
	memcpy ((char *) newTextArray, (char *) textArray, position*sizeof(char *)); //copy all entries from 0 to position of textArray into newTextArray
	char** textForLater = malloc((words - position) * sizeof(char *)); //text we add at the end of the textArray
	if(textForLater == (char**)NULL) //error
	{
		perror("Array not created");
		printf("Error at line %d\n", __LINE__);
		return;
	}
	int i;
	int index = 0;
	for(i = position + 1; i < words; i++)
	{
		textForLater[index] = malloc((strlen(textArray[i]) + 1) * sizeof(char)); //allocate enough space for entry
		if(textForLater[index] == (char*) NULL) //error
		{
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
	words--; //since we are overwriting an entry, need to decrement words beforehand
	while(pch2 != NULL)
	{
		char* es;
		es = malloc(strlen(pch2) + 1); //allocate space for word and terminating character
		if (es == NULL) //error
		{
			perror("Error with memory allocation.");
			printf("Error at line %d\n", __LINE__);
			return;
		}
		strcpy(es, pch2); //copy text into pointer
		newTextArray[position + j] = es; //word
		j++; //move forward
		words++; //added another word
		pch2 = strtok_r(NULL, "$", &saved4);
	}
	int k;
	index = 0;
	for(k = position + j; k < words; k++)
	{
		newTextArray[k] = malloc((strlen(textForLater[index]) + 1)*sizeof(char)); //allocate space
		if(newTextArray[k] == (char*) NULL) //error
		{
			perror("Error with memory allocation.");
			printf("Error at line %d\n", __LINE__);
			return;
		}
		strcpy(newTextArray[k], textForLater[index]); //copy over
		index++; //move to next entry
	}
	newTextArray[words + 1] = NULL; //null entry
	textArray = newTextArray;
	addedWords += j - 1; //how many words we added
}

void printTextArray()
{
	int i;
	for(i = 0; i < words; i++)
	{
		printf("%s\n", textArray[i]);
	}
}


int spawn_proc (int inChannel, int outChannel, struct command *cmd)
{
	pid_t pid;
	if ((pid = fork ()) == 0) //in parent
    {
    	if (inChannel != 0)
    	{
			dup2 (inChannel, 0);
			close (inChannel);
		}
		if (outChannel != 1)
		{
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
	for (i = 0; i < n - 1; ++i)
    {
		pipe (fd);
		spawn_proc (inChannel, fd [1], cmd + i); //take in read end of previous iteration, goes to write end of next iteration
		/* Close redundant output.  */
		close (fd [1]);
		/* Need this for next iteration.  */
		inChannel = fd [0];
    }

    /* Last stage of the pipeline - set stdin be the read end of the previous pipe
    and output to the original file descriptor 1. */  
    if (inChannel != 0)
	{
		dup2 (inChannel, 0);
	}
	/* Execute the last stage with the current process. */
	return execvp (cmd [i].argv [0], (char * const *)cmd [i].argv);
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
	printf("%s@", passwd->pw_name);	

	// get computer name
	char* hostName = malloc(300 * sizeof(char));
	gethostname(hostName, 20);
	printf("%s:", hostName);

	// get path
	printf("%s$ ", getenv("PWD"));
}
