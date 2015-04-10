char** aliases; 	// alias names and values
// char** aliasesTemp;	// copied aliases
int aliasCount = 0; // number of aliases

/* This alias command adds a new alias to the shell. An alias is
essentially a shorthand form of a long command. */
void alias_function(char *name, char *word) {

	// check
	if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL || word == NULL) {
		perror("Invalid argument");
		printf("Error at line %d\n", __LINE__);
		reset();
		return;
	}

	// remove current assignment for the name
	unalias_function(name, 0);          

	char *pair;

	// allocate +2 for '=' and null terminator 
	pair = malloc(strlen(name) + strlen(word) + 2);

	if (pair == NULL) {
		perror("Error with memory allocation");
		printf("Error at line %d\n", __LINE__);
		reset();
		return;
	}

	// create the pair
	strcpy(pair, name); 
	strcat(pair, "="); 
	strcat(pair, word);

	char** aliasesTemp;
	aliasesTemp = (char **) malloc((aliasCount+2) * sizeof(char *)); 
	if(aliasesTemp == (char **) NULL) {
		perror("Array not created.");
		printf("Error at line %d\n", __LINE__);
		reset();
		return;
	}

	int i;
	for(i = 0; i < aliasCount; ++i) {
		aliasesTemp[i] = aliases[i];
	}
	aliasesTemp[aliasCount] = pair; 
	aliasesTemp[aliasCount + 1] = NULL; 

	aliases = aliasesTemp;
	++aliasCount; 
	reset();
}

void unalias_function(char *name, int flag)
{
	size_t length;
	if (name == NULL || name == '\0' || strchr(name, '=') != NULL) { //invalid
		perror("Entered an invalid alias");
		printf("Error at line %d\n", __LINE__);
		return;
	}
	length = strlen(name);
	int i;
	int j;
	for (i = 0; i < aliasCount; i++)
	{
		if (strncmp(aliases[i], name, length) == 0 && aliases[i][length] == '=') { //found match
			for (j = i; j < aliasCount; j++)
			{
				aliases[j] = aliases[j + 1]; //shift over
			}
			aliasCount--; //decrement count
		} 
	}
	if(flag == 1){
		reset();
	}
}

char* getAliasValue(char* aliasName)
{//returns the value of an alias when given the name as an argument,returns empty string if the alias name does not exist
	int i = 0;
	char* value = malloc(300*sizeof(char));
	value[0] = '\0';
	for(i = 0; i < aliasCount; i++)
	{//goes through aliases arary
		int j = 0;
		int eqindex = strlen(aliases[i]);
		for(j = 0; j < eqindex; j++)
		{
			if(aliases[i][j] == '=')
			{//finds the = character which separates name and value
				eqindex = j;
			}
		}
		char* possibleNameMatch = malloc(300*sizeof(char));
		strncpy(possibleNameMatch, aliases[i], eqindex);//copies everything up to the = value into possibleNameMatch
		if(strcmp(aliasName, possibleNameMatch) == 0)
		{//if name is possibleNameMatch then copies everything after the = into the return value
			strcpy(value, &aliases[i][eqindex+1]);
			return value;
		}
		free(possibleNameMatch); //frees memory
	}
	return value;
}

char* aliasResolve(char* alias)
{//takes in name of alias and returns the final resolved value of that alias name or <LOOP> if it loops infinitely,
	//if string passed in argument is not an alias then it returns empty string
	char* name = malloc(500*sizeof(char)); //declares name and value strings used to resolve
	char* value = malloc(500*sizeof(char));
	char* nameTracker[100]; //keeps track of alias names already encountered in order to detect infinite loops
	int trackSize = 0; //keeps track of size of names in the tracker
	strcpy(name, alias); //copies initial name into name string
	nameTracker[trackSize] = name;
	trackSize++;
	strcpy(value,getAliasValue(name));//gets initial value
	if(strcmp(value, "") == 0)
	{//if initial alias name does not resolve to anything(resolves to empty string), return empty string
		return value;
	}
	while(value[0] != '\0')
	{ //loop runs until value cannot be further resolved into an additional alias
		int i;
		for(i = 0; i < trackSize; i++)
		{
			if(strcmp(value, nameTracker[i]) == 0)
			{ //returns "<LOOP>" if the alias generates an infinite loop
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


void textArrayAliasExpansion(char* name, int position)
{
	char* saved3;
	char* result = malloc((strlen(name) + 1) * sizeof(char)); //allocate space
	if(result == (char*) NULL) //error
	{
		perror("Error with memory allocation.");
		printf("Error at line %d\n", __LINE__);
		return;
	}
	strcpy(result, name); //copy name over
	char* result2 = malloc((strlen(name) + 1) * sizeof(char));
	if(result2 == (char*) NULL) //error
	{
		perror("Error with memory allocation.");
		printf("Error at line %d\n", __LINE__);
		return;
	}
	strcpy(result2, result); //copy another one since strtok_r changes actual name
	char* pch = strtok_r(result, " ", &saved3); //parse to get each indiviual file
	int tokens = 0; //how many positions we add
	while(pch != NULL)
	{
		tokens++;
		pch = strtok_r(NULL, " ", &saved3);
	}
	newTextArray = (char **) malloc((words+tokens)*sizeof(char *)); //null entry and new words
	if ( newTextArray == (char **) NULL ) //no array created
	{
		perror("Array not created");
		printf("Error at line %d\n", __LINE__);
		return;
	}
	memcpy ((char *) newTextArray, (char *) textArray, position*sizeof(char *)); //copy all entries from 0 to position of textArray into newTextArray
	char** textForLater = malloc((words - position) * sizeof(char *)); //name we add at the end of the textArray
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
	char* pch2 = strtok_r(result2, " ", &saved4);
	int j = 0;
	words--; //since we are overwriting an entry, need to decrement words beforehand
	while(pch2 != NULL)
	{
		char* pair;
		pair = malloc(strlen(pch2) + 1); //allocate space for word and terminating character
		if (pair == NULL) //error
		{
			perror("Error with memory allocation.");
			printf("Error at line %d\n", __LINE__);
			return;
		}
		strcpy(pair, pch2); //copy name into pointer
		newTextArray[position + j] = pair; //word
		j++; //move forward
		words++; //added another word
		pch2 = strtok_r(NULL, " ", &saved4);
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
char *fixText(char *orig, char *rep, char *with) {
    char *result; // the return string
    char *ins;    // the next insert point
    char *tmp;    // varies
    int len_rep;  // length of rep
    int len_with; // length of with
    int len_front; // distance between rep and end of last rep
    int count;    // number of replacements
    if (!orig)
	{
        return NULL;
	}
    if (!rep)
	{
        rep = "";
	}
    len_rep = strlen(rep);
    if (!with)
	{
        with = "";
	}
    len_with = strlen(with);
    ins = orig;
    for (count = 0; tmp = strstr(ins, rep); ++count) 
	{
        ins = tmp + len_rep;
    }
    // first time through the loop, all the variable are set correctly
    // from here on,
    // tmp points to the end of the result string
    // ins points to the next occurrence of rep in orig
    // orig points to the remainder of orig after "end of rep"
    tmp = result = malloc(strlen(orig) + (len_with - len_rep) * count + 1);
    if (!result)
	{
        return NULL;
	}
    while (count--) 
	{
        ins = strstr(orig, rep);
        len_front = ins - orig;
        tmp = strncpy(tmp, orig, len_front) + len_front;
        tmp = strcpy(tmp, with) + len_with;
        orig += len_front + len_rep; // move to next "end of rep"
    }
    strcpy(tmp, orig);
    return result;
}

/* print each alias line by line */
void alias_print_function() {
	int i;
	for(i = 0; i < aliasCount; ++i) {
		printf("%s\n", aliases[i]); 
	}
}

