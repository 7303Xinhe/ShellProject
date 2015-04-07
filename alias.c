/*
alias name word This alias command adds a new alias to the shell.s
*/
void alias_function(char *text, char *text2)
{
	char *es;
	if (text == NULL || text[0] == '\0' || strchr(text, '=') != NULL || text2 == NULL) //check to see if valid
	{
		perror("Invalid argument");
		printf("Error at line %d\n", __LINE__);
		reset();
		return;
	}
	if(strcmp(text, "cd") == 0 || strcmp(text, "alias") == 0 || strcmp(text, "unalias") == 0 || strcmp(text, "setenv") == 0 || strcmp(text, "printenv") == 0 || strcmp(text, "unsetenv") == 0) //error
	{
		perror("Trying to make an alias out of a built-in command");
		printf("Error at line %d\n", __LINE__); 
		reset();
		return;
	}
	unalias_function(text);             /* Remove all occurrences */
	es = malloc(strlen(text) + strlen(text2) + 2);
	if (es == NULL) //error
	{
		perror("Error with memory allocation");
		printf("Error at line %d\n", __LINE__);
		reset();
		return;
	}
	strcpy(es, text); //copy variable
	strcat(es, "="); //copy =
	strcat(es, text2); //copy value
	newAliases = (char **) malloc((aliasCount+2)*sizeof(char *)); //null entry and new word
	if ( newAliases == (char **) NULL ) //no array created
	{
		perror("Array not created.");
		printf("Error at line %d\n", __LINE__);
		reset();
		return;
	}
	memcpy ((char *) newAliases, (char *) aliases, aliasCount*sizeof(char *)); //copy all entries from textArray into newTextArray
	newAliases[aliasCount] = es; //word
	newAliases[aliasCount + 1] = NULL; //null entry
	aliases = newAliases;
	aliasCount++; //increment index
	reset();
}


/*
alias The alias command with no arguments lists all of the current aliases.
*/
void alias_list_function()
{
	printf("Alias List:\n");
	int i;
	for(i = 0; i < aliasCount; i++)
	{
		printf("%s\n", aliases[i]); //print each alias line by line
	}
}


/*
unalias name The unalias command is used to remove the alias for name from the
alias list.
*/
void unalias_function(char *text)
{
	size_t length;
	if (text == NULL || text == '\0' || strchr(text, '=') != NULL) { //invalid
		perror("Entered an invalid alias");
		printf("Error at line %d\n", __LINE__);
		return;
	}
	length = strlen(text);
	int i;
	int j;
	for (i = 0; i < aliasCount; i++)
	{
		if (strncmp(aliases[i], text, length) == 0 && aliases[i][length] == '=') { //found match
			for (j = i; j < aliasCount; j++)
			{
				aliases[j] = aliases[j + 1]; //shift over
			}
			aliasCount--; //decrement count
		} 
	}
	reset();
}


int getAliasCount()
{
	return aliasCount;
}


char* aliasResolve(char* alias){//takes in name of alias and returns the final resolved value of that alias name or <LOOP> if it loops infinitely,
	//if string passed in argument is not an alias then it returns empty string
	char* name = malloc(300*sizeof(char)); //declares name and value strings used to resolve
	char* value;
	char* nameTracker[100]; //keeps track of alias names already encountered in order to detect infinite loops
	int trackSize = 0; //keeps track of size of names in the tracker
	strcpy(name, alias); //copies initial name into name string
	nameTracker[trackSize] = name;
	trackSize++;
	value = getAliasValue(name);//gets initial value
	if(strcmp(value, "") == 0)//if initial alias name does not resolve to anything(resolves to empty string), return empty string
		return value;
	while(value[0] != '\0'){ //loop runs until value cannot be further resolved into an additional alias
		int i;
		for(i = 0; i < trackSize; i++){
			if(strcmp(value, nameTracker[i]) == 0){ //returns "<LOOP>" if the alias generates an infinite loop
				strcpy(value, "<LOOP>");
				return value;
			}
		}
		nameTracker[trackSize] = value;//the alias value gets added to the tracking array if it's not in the array already
		trackSize++;
		name = value; //name now becomes the previous value
		value = getAliasValue(name); //get alias value connected to alias name
	}
	strcpy(value, name);
	free(name);
	return value;
}

char* getAliasValue(char* aliasName){//returns the value of an alias when given the name as an argument,returns empty string if the alias name does not exist
	int i = 0;
	char* value = malloc(300*sizeof(char));
	value[0] = '\0';
	for(i = 0; i < aliasCount; i++){//goes through aliases arary
		int j = 0;
		int eqindex = strlen(aliases[i]);
		for(j = 0; j < eqindex; j++){
			if(aliases[i][j] == '='){//finds the = character which separates name and value
				eqindex = j;
			}
		}
		char* possibleNameMatch = malloc(300*sizeof(char));
		strncpy(possibleNameMatch, aliases[i], eqindex);//copies everything up to the = value into possibleNameMatch
		if(strcmp(aliasName, possibleNameMatch) == 0){//if name is possibleNameMatch then copies everything after the = into the return value
			strcpy(value, &aliases[i][eqindex+1]);
			return value;
		}
		free(possibleNameMatch); //frees memory
	}
	return value;
}

