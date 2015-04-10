/* setenv variable word - This command sets the value of the variable variable to be word. */
void setenv_function (char *variable, char *value, int flag) {

	condenseSlashes(value); 

	// for the variable=value pair
	char *pair;

	// check to see if inputs are valid
	if (variable == NULL || variable[0] == '\0' || strchr(variable, '=') != NULL || value == NULL) {
		perror("Invalid argument.");
		printf("Error at line %d\n", __LINE__);
		return;
	}

	// remove current assignment for the variable
	unsetenv_function(variable, 0);             
	
	// allocate +2 for '=' and null terminator 
	pair = malloc(strlen(variable) + strlen(value) + 2);
	if (pair == NULL) {
		perror("Error with memory allocation");
		printf("Error at line %d\n", __LINE__);
		return;
	}

	// setting path
	if(strcmp(variable, "PATH") == 0 || strcmp(variable, "ARGPATH") == 0) {

		// list of one or more currentDirectory names separated by colon
		char *valueToken = strtok(value, ":"); 

		// string used to build the final value
		char *path = malloc(500 * sizeof(char));
		if(path == (char *) NULL) {
			perror("Error with memory allocation.");
			printf("Error at line %d\n", __LINE__);
			return;
		}

		strcpy(path, "");

		// this loop puts the formatted tokens into the path string, seperated by colons
		while (valueToken != NULL) {

			char* currentDirectory = malloc(300 * sizeof(char));
			if(currentDirectory == (char*) NULL) {
				perror("Error with memory allocation.");
				printf("Error at line %d\n", __LINE__);
				return;
			}

			// get current directory
			strcpy(currentDirectory, getenv("PWD"));
			
			// input starts with '.'
			if(valueToken[0] == '.') {

				// just a dot or dot-slash
				if((strlen(valueToken) == 1) || (strlen(valueToken) == 2 && valueToken[1] == '/')) {
					strcat(path, currentDirectory); 
					strcat(path, ":");
				}
				
				// "./abc"
				else if(strlen(valueToken) > 2 && valueToken[1] == '/') {
					strcat(path, currentDirectory);
					strcat(path, &valueToken[2]);
					strcat(path, ":");
				}

				// ".abc"
				else if(valueToken[1] != '.') {
					strcat(path, currentDirectory);
					strcat(path, &valueToken[1]);
					strcat(path, ":");
				}
				
				// ".."
				else if(valueToken[1] == '.' && strcmp(currentDirectory, "/") != 0) {
					
					int i;
					int slashIndex = 1;

					// find last slash
					for(i = strlen(currentDirectory) - 2; i >= 0; --i) 
					{
						if(currentDirectory[i] == '/') {
							slashIndex = i; 
							break;
						}
					}

					// makes currentDirectory move up one
					if(slashIndex != 0) { 
						currentDirectory[slashIndex] = '\0';
						strncat(path, currentDirectory, slashIndex);
					}

					// currentDirectory now root
					else if(slashIndex == 0) {
						currentDirectory[1] = '\0';
						strcat(path, "/");
					}

					if(strlen(valueToken) > 2) {
						strcat(path, "/"); //add slash
						strcat(path, &valueToken[3]); //take everything after the slash
						strcat(path, ":");
					}
					else {
						strcat(path, "/"); 
						strcat(path, ":");
					}
				}

				else if(strcmp(currentDirectory, "/") == 0) {
					strcat(path,"/"); 
					strcat(path, ":");
				}
			} // end if(valueToken[0] == '.')

			// first character is slash (starting at root)
			else if(valueToken[0] == '/') {
				
				// just '/' || "/."
				if(strlen(valueToken) == 1 || (strlen(valueToken) == 2 && valueToken[1] == '.')) {
					strcat(path, "/");
					strcat(path, ":");
				} else {
					char* value = malloc(300 * sizeof(char));
					if(value == (char *) NULL) {
						perror("Error with memory allocation.");
						printf("Error at line %d\n", __LINE__);
						return;
					}
					// adding the absolute path
					strcat(path, valueToken);
					strcat(path, ":");
				}
			} 

			// relative path ~sjc/bin
			else {
				char* value = malloc(300 * sizeof(char));
				if(value == (char *) NULL) {
					perror("Error with memory allocation.");
					printf("Error at line %d\n", __LINE__);
					return;
				}
				strcat(value, currentDirectory);
				strcat(value, valueToken);
				strcat(path, value);
				strcat(path, ":");
			}

			// find next valueToken
			valueToken = strtok(NULL, ":");
		}

		// get rid of colon at the end
		path[strlen(path) - 1] = '\0';
		// put path into value 
		strcpy(value, path);

	} // end if PATH || ARGPATH


	// create the pair
	strcpy(pair, variable); 
	strcat(pair, "="); 
	strcat(pair, value); 
	
	// put into array
	if(putenv(pair) == -1) {
		perror("Error inserting element into environment variable array");
		printf("Error at line %d\n", __LINE__);
		return;
	}
	if(flag) {
		reset();
	}
}


/* unsetenv variable This command will remove the binding of variable. If the variable is unbound, the command is ignored. */
void unsetenv_function(char *variable, int flag) {
	
	 // check
	if (variable == NULL || variable == '\0' || strchr(variable, '=') != NULL) { 
		perror("Entered an invalid name");
		printf("Error at line %d\n", __LINE__);
		return;
	}

	// to temp array of string pairs
	char **environTemp;
	
	size_t length;
	length = strlen(variable);	

	// loop through all the env variables trying to find match
	for (environTemp = environ; *environTemp != NULL; ++environTemp) {

		// found match
		if (strncmp(*environTemp, variable, length) == 0 && (*environTemp)[length] == '=') { 
			
			// shift all the variables to the left
			while(*environTemp != NULL) {
				*environTemp = *(environTemp + 1); 
				++environTemp;
			}
			break;
		} 
		// increment 
	}

	if(flag) {
		reset();
	}
}

/* print all the environment variable pairs */
void printenv_function() {

	char ** environTemp;
	for(environTemp = environ; *environTemp!= NULL; environTemp++) {
		printf("%s\n", *environTemp); 
	}
}


