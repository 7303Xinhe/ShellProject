/*
setenv variable word This command sets the value of the variable variable to be
word.
*/
void setenv_function (char *text, char *text2, int flag) {
	
	shortenSlashes(text2); 

	// check
	if (text == NULL || text[0] == '\0' || strchr(text, '=') != NULL || text2 == NULL) {
		perror("Invalid argument.");
		printf("Error at line %d\n", __LINE__);
		return;
	}

	// Remove all occurrences 
	unsetenv_function(text, 0);             
	
	char *variablePair;
	variablePair = malloc(strlen(text) + strlen(text2) + 2); // +2 for '=' and null terminator
	 
	if (variablePair == NULL) {
		perror("Error with memory allocation");
		printf("Error at line %d\n", __LINE__);
		return;
	}

	// setting path
	if(strcmp(text, "PATH") == 0 || strcmp(text, "ARGPATH") == 0) {
		char *pch = strtok(text2, ":"); //split on colons
		char *path = malloc(500 * sizeof(char));
		
		if(path == (char *) NULL) {
			perror("Error with memory allocation.");
			printf("Error at line %d\n", __LINE__);
			return;
		}
		
		strcpy(path, "");
		while (pch != NULL) { // still have tokens		
			char* directory = malloc(300 * sizeof(char));
			
			if(directory == (char*) NULL) {
				perror("Error with memory allocation.");
				printf("Error at line %d\n", __LINE__);
				return;
			}
			
			// current working directory
			strcpy(directory, getenv("PWD"));
			
			if(pch[0] == '.') {				
				// just a dot
				if(strlen(pch) == 1) {
					strcat(path, directory); //get current directory
					strcat(path, ":");
				}
				
				else if(strlen(pch) == 2 && pch[1] == '/') //just a dot-slash
				{
					strcat(path, directory); //get current directory
					strcat(path, ":");
				}
				else if(strlen(pch) > 2 && pch[1] == '/')
				{
					strcat(path, directory);
					strcat(path, &pch[2]);
					strcat(path, ":");
				}
				else if(pch[1] != '.') //append text after dot
				{
					strcat(path, directory);
					strcat(path, &pch[1]);
					strcat(path, ":");
				}
				else if(pch[1] == '.' && strcmp(directory, "/") != 0)//go up a level (not in the root)
				{
					int i;
					int lastSlashIndex = 1;
					for(i = strlen(directory) - 2; i >= 0; i--) //find occurence of last slash
					{
						if(directory[i] == '/')
						{
							lastSlashIndex = i; //found last slash
							break;
						}
					}
					if(lastSlashIndex != 0)
					{ //if .. does not return to the root directory
						directory[lastSlashIndex] = '\0';//sets the second to last slash to a null character
						strncat(path, directory, lastSlashIndex);
					}
					else if(lastSlashIndex == 0)
					{//if .. is returning up to the root directory
						directory[1] = '\0';//sets index 1 to null so the directory sets to the root
						strcat(path, "/");
					}
					if(strlen(pch) > 2)
					{
						strcat(path, "/"); //add slash
						strcat(path, &pch[3]); //take everything after the slash
						strcat(path, ":");
					}
					else //nothing
					{
						strcat(path, "/"); //blank it
						strcat(path, ":");
					}
				}
				else if(strcmp(directory, "/") == 0)
				{//if it is in root
					strcat(path,"/"); //change text to empty string so ".." is not concatenated to the directory later on
					strcat(path, ":");
				}
			}
			if(pch[0] == '/') //first character is slash
			{
				if(strlen(pch) == 1 || (strlen(pch) == 2 && pch[1] == '.')) //just a slash or slash-dot
				{
					strcat(path, "/");
					strcat(path, ":");
				}
				else
				{
					char* text2 = malloc(300 * sizeof(char));
					if(text2 == (char *) NULL)
					{
						perror("Error with memory allocation.");
						printf("Error at line %d\n", __LINE__);
						return;
					}
					strcat(path, &pch[1]);
					strcat(path, ":");
				}
			}
			pch = strtok(NULL, ":");
		}
		path[strlen(path) - 1] = '\0'; //get rid of colon at the end
		strcpy(text2, path);
	}
	strcpy(variablePair, text); //copy variable
	strcat(variablePair, "="); //copy =
	strcat(variablePair, text2); //copy value
	int result = putenv(variablePair); //put into array
	if(result == -1) //error
	{
		perror("Error inserting element into environment variable array");
		printf("Error at line %d\n", __LINE__);
		return;
	}
	if(flag)
	{
		reset();
	}
}



/*
unsetenv variable This command will remove the binding of variable. If the variable
is unbound, the command is ignored.
*/
void unsetenv_function(char *text, int flag)
{
	char **envVariableNames, **rightEnvVariableNames;
	size_t length;
	if (text == NULL || text == '\0' || strchr(text, '=') != NULL) { //error
		perror("Entered an invalid name");
		printf("Error at line %d\n", __LINE__);
		return;
	}
	length = strlen(text);
	for (envVariableNames = environ; *envVariableNames != NULL; )
	{
		if (strncmp(*envVariableNames, text, length) == 0 && (*envVariableNames)[length] == '=') { //found a match
			for (rightEnvVariableNames = envVariableNames; *rightEnvVariableNames != NULL; rightEnvVariableNames++)
			{
				*rightEnvVariableNames = *(rightEnvVariableNames + 1); //shift over
			}
			/* Continue around the loop to further instances of 'name' */
		} 
		else {
				envVariableNames++; //keep moving
		}
	}
	if(flag)
	{
		reset();
	}
}


/*
printenv This command prints out the values of all the environment variables, in
the format variable=value, one entry per line.
*/
void printenv_function()
{
	char ** ep;
	for(ep = environ; *ep!= NULL; ep++)
	{
		printf("%s\n", *ep); //print everything line by line
	}
}