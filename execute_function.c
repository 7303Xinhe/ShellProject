
void execute() {	
	// ignore
	if(strcmp(wordTable[0], "") == 0) {
		return;
	}




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
	if((child = fork()) == -1) {//error
		perror("Error forking");
		printf("Error at line %d\n", __LINE__);
		reset();
		exit(0);
		return;
	}	
	if(child != 0) { //in parent
		if(indexOfAmpersand == 0) {//wait for process to finish executing
			wait((int *) 0);
		}
		reset();
	}
	else {//in child
		if(strcmp(wordTable[0], "echo") == 0 && strcmp(wordTable[1], "-e") != 0) {//echo command without -e
			char* result = malloc((strlen(wordTable[1]) + 1) * sizeof(char));
			if(result == (char*)NULL) {
				perror("Memory allocation error.");
				printf("Error at line %d\n", __LINE__);
				reset();
				exit(0);
				return;
			}
			strcpy(result, fixText(wordTable[1], "\\\\", "\\"));
			strcpy(wordTable[1], result);
			strcpy(result, fixText(wordTable[1], "\\\"", "\""));
			strcpy(wordTable[1], result);
		}
		int* spaces = malloc(300 * sizeof(int));
		if(spaces == (int*) NULL) { //error
			perror("Memory allocation error.");
			printf("Error at line %d\n", __LINE__);
			reset();
			exit(0);
			return;
		}
		for(i = 0; i < wordCount; i++) {
			if(strchr(wordTable[i], ' ') != NULL) {//there's a space
				spaces[numberOfSpaces] = i;
				numberOfSpaces++;
			}
		}
		for(i = 0; i < numberOfSpaces; i++) {
			char ** ep;
			int index;
			int j;
			for(ep = environ; *ep!= NULL; ep++) {
				char* theVariable = malloc((strlen(*ep) + 1) * sizeof(char));
				if(theVariable == (char*) NULL) {//error
					perror("Memory allocation error.");
					printf("Error at line %d\n", __LINE__);
					reset();
					exit(0);
					return;
				}
				strcpy(theVariable, *ep); //copy environment variable
				for(j = 0; j < strlen(theVariable); j++) {
					if(theVariable[j] == '=') {//found =
						index = j;
						break;
					}
				}
				char* result = malloc((strlen(theVariable) - index + 1) * sizeof(char));
				if(result == (char*) NULL) {//error
					perror("Memory allocation error.");
					printf("Error at line %d\n", __LINE__);
					reset();
					exit(0);
					return;
				}
				strcpy(result, &theVariable[index + 1]); //take everything after =
				if(strcmp(wordTable[spaces[i]], result) == 0) { //there's a match
					textArrayAliasExpansion(wordTable[spaces[i] + addedWords], spaces[i] + addedWords); //expand to get rid of spaces
					break;
				}
			}
		}
		int* pipes = malloc(300 * sizeof(int));
		if(pipes == (int*) NULL) { //error
			perror("Memory allocation error.");
			printf("Error at line %d\n", __LINE__);
			reset();
			exit(0);
			return;
		}
		int* globs = malloc(300 * sizeof(int));
		if(globs == (int*) NULL) {//error
			perror("Memory allocation error.");
			printf("Error at line %d\n", __LINE__);
			reset();
			exit(0);
			return;
		}
		addedWords = 0;
		for(i = 0; i < wordCount; i++) {
			if(strcmp(wordTable[i], "|") == 0) { //it's a pipe
				pipes[numberOfPipes] = i;
				numberOfPipes++;
			}
		}
		numberOfCommands = numberOfPipes + 1;
		for(i = 0; i < numberOfCommands; i++) { //resolves aliases
			if(i == 0) {
				if(strcmp(aliasResolver(wordTable[i]), "<LOOP>") == 0) { //infinite alias expansion
					perror("Infinite alias expansion.");
					printf("Error at line %d\n", __LINE__);
					reset();
					exit(0);
					return;
				}
				
				else if(strcmp(aliasResolver(wordTable[i]), "") != 0) {//alias has a value
					char* resolved = malloc((strlen(aliasResolver(wordTable[i])) + 1) * sizeof(char));
					strcpy(resolved,aliasResolver(wordTable[i]));
					wordTable[i] = resolved;
					textArrayAliasExpansion(wordTable[i], i + addedWords);

				}
			}
			else{
				int j;
				if(strcmp(aliasResolver(wordTable[pipes[i - 1] + 1]), "<LOOP>") == 0) {//infinite alias expansion
					perror("Infinite alias expansion.");
					printf("Error at line %d\n", __LINE__);
					reset();
					exit(0);
					return;
				}
				else if(strcmp(aliasResolver(wordTable[pipes[i - 1] + 1 + addedWords]), "") != 0) {//alias has a value
					char* resolved = malloc((strlen(aliasResolver(wordTable[pipes[i - 1] + 1 + addedWords]) + 1) * sizeof(char)));
					strcpy(resolved,aliasResolver(wordTable[pipes[i - 1] + 1 + addedWords]));
					wordTable[pipes[i - 1] + 1 + addedWords] = resolved;
					textArrayAliasExpansion(wordTable[pipes[i - 1] + 1 + addedWords], pipes[i - 1] + 1 + addedWords);
				}
			}
		}
		numberOfGlobs = 0;
		addedWords = 0;
		for(i = 0; i < wordCount; i++) {
			if(strchr(wordTable[i], '*') != NULL || strchr(wordTable[i], '?') != NULL) { //contains a * or ?
				globs[numberOfGlobs] = i;
				numberOfGlobs++;
			}
		}
		char* saved3;
		for(i = 0; i < numberOfGlobs; i++) {//takes care of globbing
			if(i == 0) {
				printf(" ");
			}
			char* result = malloc((strlen(getDirectories(wordTable[globs[i] + addedWords])) + 1)* sizeof(char));
			if(result == (char*) NULL) { //error
				perror("Memory allocation error.");
				printf("Error at line %d\n", __LINE__);
				reset();
				exit(0);
				return;
			}
			strcpy(result, getDirectories(wordTable[globs[i] + addedWords]));
			if(strcmp(result, "") == 0) { //error
				perror("No matches, so not executing.");
				printf("Error at line %d\n", __LINE__);
				reset();
				exit(0);
				return;
			}
			word3_function(result, globs[i] + addedWords);
		}
		numberOfPipes = 0;
		for(i = 0; i < wordCount; i++) {
			if(strcmp(wordTable[i], "|") == 0) { //it's a pipe
				pipes[numberOfPipes] = i;
				numberOfPipes++;
			}
			if(strcmp(wordTable[i], "<") == 0) { //read in
				indexOfRead = i;
			}
			if(strcmp(wordTable[i], ">") == 0) {//write to
				indexOfWrite = i;
			}
			if(strcmp(wordTable[i], ">>") == 0) { //append
				indexOfAppend = i;
			}
			if(strcmp(wordTable[i], "2>&1") == 0) { //standard error redirect 2
				indexOfStandardError2 = i;
			}
			else if(strcmp(wordTable[i], "2>") == 0) { //standard error redirect 1
				indexOfStandardError1 = i;
			}
			if(strcmp(wordTable[i], "&") == 0) { //ampersand
				indexOfAmpersand = i;
			}
		}
		if(indexOfRead != 0) {//there's a read present
			int result = read_from_function(wordTable[indexOfRead + 1]); 
			if(result == -1) {
				reset();
				exit(0);
				return;
			}
		}
		if(indexOfWrite != 0) {//there's a write to present
			int result = write_to_function(wordTable[indexOfWrite + 1]);
			if(result == -1) {
				reset();
				exit(0);
				return;
			}
		}
		if (indexOfAppend != 0) {//there's an append present
			int result = append_function(wordTable[indexOfAppend + 1]);
			if(result == -1)
			{
				reset();
				exit(0);
				return;
			}
		}
		if(indexOfStandardError2 != 0) {//second standard error case present
			int result = standard_error_redirect_function();
			if(result == -1)
			{
				reset();
				exit(0);
				return;
			}
		}
		if(indexOfStandardError1 != 0) { //first standard error case present
			int result = standard_error_redirect_function2(wordTable[indexOfStandardError2]);
			if(result == -1) {
				reset();
				exit(0);
				return;
			}
		}
		numberOfCommands = numberOfPipes + 1;
		if(numberOfPipes == 0) { //no pipes, just this command
			if(indexOfRead != 0) { //take everything up until this 
				endOfCommand = indexOfRead;
			}
			else if(indexOfWrite != 0) { //no read from
				endOfCommand = indexOfWrite;
			}
			else if(indexOfAppend != 0) { //no read from
				endOfCommand = indexOfAppend;
			}
			else if(indexOfStandardError2 != 0) { //no other I/O redirection
				endOfCommand = indexOfStandardError2;
			}
			else if(indexOfStandardError1 != 0) { //no other I/O redirection
				endOfCommand = indexOfStandardError1;
			}
			else if(indexOfAmpersand != 0) { //no I/O redirection
				endOfCommand = indexOfAmpersand;
			}
			else { //just a command with no special components
				endOfCommand = wordCount;
			}
			char* result = malloc(300 * sizeof(char));
			if(result == (char*) NULL) { //error
				perror("Memory allocation error.");
				printf("Error at line %d\n", __LINE__);
				reset();
				exit(0);
				return;
			}
			char* arguments[endOfCommand + 1];
			int i;
			for(i = 0; i < endOfCommand; i++) {
				arguments[i] = wordTable[i]; //copy arguments
			}
			arguments[endOfCommand] = (char *)0; //null terminator
			int result2 = execvp(arguments[0], arguments);
			if(result2 == -1) { //error
				perror("Error executing.");
				printf("Error at line %d\n", __LINE__);
				reset();
				exit(0);
				return;
			}
		}
		else {//perform piping
			if(indexOfRead != 0) { //take everything up until this 
				endOfCommand = indexOfRead;
			}
			else if(indexOfWrite != 0) { //no read from
				endOfCommand = indexOfWrite;
			}
			else if(indexOfAppend != 0) { //no read from
				endOfCommand = indexOfAppend;
			}
			else if(indexOfStandardError2 != 0) { //no other I/O redirection
				endOfCommand = indexOfStandardError2;
			}
			else if(indexOfStandardError1 != 0) { //no other I/O redirection
				endOfCommand = indexOfStandardError1;
			}
			else if(indexOfAmpersand != 0) { //no I/O redirection
				endOfCommand = indexOfAmpersand;
			}
			else { //just a command with no special components
				endOfCommand = wordCount;
			}
			struct command* cmd = malloc(numberOfCommands * sizeof(struct command));
			for(i = 0; i < numberOfCommands; i++) {
				if(i == 0) { //first command
					char* arguments [pipes[0] + 1];
					int j = 0;
					for(j = 0; j < pipes[0]; j++) {
						arguments[j] = wordTable[j]; //copy arguments
					}
					arguments[pipes[0]] = (char*)0; //null terminator
					cmd[0].argv = malloc(j*sizeof(char*));
					if(cmd[0].argv == (char**)NULL) { //error
						perror("Memory allocation error.");
						printf("Error at line %d\n", __LINE__);
						reset();
						exit(0);
						return;
					}
					int k = 0;
					for(k = 0; k < j; k++) {
						cmd[0].argv[k] = malloc((strlen(arguments[k]) + 1) * sizeof(char));
						if(cmd[0].argv[k] == (char*) NULL) { //error
							perror("Memory allocation error.");
							printf("Error at line %d\n", __LINE__);
							reset();
							exit(0);
							return;
						}
						strcpy(cmd[0].argv[k], arguments[k]);
					}
					cmd[0].argv[j] = (char*) 0;
				}
				else if(i != (numberOfCommands - 1)) { //in the middle
					char* arguments[pipes[i] - pipes[i - 1]];
					int j;
					for(j = 0; j < pipes[i] - pipes[i - 1] - 1; j++) {
						arguments[j] = wordTable[pipes[i - 1] + 1 + j]; //copy arguments
					}
					arguments[pipes[i] - pipes[i - 1] - 1] = (char *)0; //null terminator
					cmd[i].argv = malloc(j*sizeof(char*));
					if(cmd[i].argv == (char**)NULL) {//error
						perror("Memory allocation error.");
						printf("Error at line %d\n", __LINE__);
						reset();
						exit(0);
						return;
					}
					int k = 0;
					for(k = 0; k < j; k++) {
						cmd[i].argv[k] = malloc((strlen(arguments[k]) + 1) * sizeof(char));
						if(cmd[i].argv[k] == (char*) NULL) { //error
							perror("Memory allocation error.");
							printf("Error at line %d\n", __LINE__);
							reset();
							exit(0);
							return;
						}
						strcpy(cmd[i].argv[k], arguments[k]);
					}
					cmd[i].argv[j] = (char*) 0;
				}
				else { //at the end
					char* arguments[endOfCommand - pipes[i - 1]];
					int j;
					for(j = 0; j < endOfCommand - pipes[i - 1] - 1; j++) {
						arguments[j] = wordTable[pipes[i - 1] + 1 + j]; //copy arguments
					}
					arguments[endOfCommand - pipes[i - 1] - 1] = (char *)0; //null terminator
					cmd[numberOfCommands - 1].argv = malloc(j*sizeof(char*));
					if(cmd[numberOfCommands - 1].argv == (char**) NULL) { //error
						perror("Memory allocation error.");
						printf("Error at line %d\n", __LINE__);
						reset();
						exit(0);
						return;
					}
					int k = 0;
					for(k = 0; k < j; k++) {
						cmd[numberOfCommands - 1].argv[k] = malloc((strlen(arguments[k]) + 1) * sizeof(char));
						if(cmd[numberOfCommands - 1].argv[k] == (char*) NULL) { //error
							perror("Memory allocation error.");
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
			if(result == -1) { //error
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