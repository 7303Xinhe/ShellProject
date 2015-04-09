// used for the just "cd" command 
void cd_home_function() {

	// change to home currentDirectory
	int flag = chdir(myHome); 
	
	// error
	if(flag == -1) { 				
		printf("Error at line %d\n", __LINE__);
		return;
	}

	// change the value of the PWD variable
	setenv_function("PWD", myHome, 0); 
}


// normal cd function "cd word"
void cd_function(char *inputDirectory){

	condenseSlashes(inputDirectory); 

	char *currentDirectory = malloc(300 * sizeof(char));
	
	if (currentDirectory == (char *) NULL) {
		perror("Memory allocation error.\n");
		printf("Error at line %d\n", __LINE__);
		reset();
		return;
	}

	// get current directory
	strcpy(currentDirectory, getenv("PWD")); 

	// if last character is not a slash then adds a slash
	if(currentDirectory[strlen(currentDirectory) - 1] != '/') { 
		strcat(currentDirectory, "/"); 
	}

	// input starts with '.'
	if(inputDirectory[0] == '.') {

		// just dot
		if(strlen(inputDirectory) == 1) {
			return;
		}

		// just a dot slash
		else if(strlen(inputDirectory) == 2 && inputDirectory[1] == '/') { 
			return;
		}

		// dot slash with more
		else if(strlen(inputDirectory) > 2 && inputDirectory[1] == '/') {
			// remove the "./"
			strcpy(inputDirectory, &inputDirectory[2]);
		}

		// '.' then something
		else if(inputDirectory[1] != '.') {
			strcpy(inputDirectory, &inputDirectory[1]);
		}

		// just ".." and at root 
		else if(inputDirectory[1] == '.' && strcmp(currentDirectory, "/") == 0) {
			return;
		}

		// starting with ".."
		else if(inputDirectory[1] == '.' && strcmp(currentDirectory, "/") != 0) {
			
			int i;
			int lastSlashIndex = 1;
			// -2 to start at the last char, since we added a '/' in the end
			for(i = strlen(currentDirectory) - 2; i != -1; --i) {
				if(currentDirectory[i] == '/') {
					lastSlashIndex = i; 
					break;
				}
			}

			// changing currentDirectory path
			// pushes currentDirectory up a level
			if(lastSlashIndex != 0) { 
				// moves null char to previous slash
				currentDirectory[lastSlashIndex] = '\0'; 
			}

			// returning up to the root 
			else if(lastSlashIndex == 0) {
				currentDirectory[1] = '\0';
			}

			// if more than just ".."
			if(strlen(inputDirectory) > 2) {
				// add a slash to currentDirectory
				strcat(currentDirectory, "/"); 
				// remove the "../"
				strcpy(inputDirectory, &inputDirectory[3]); 
			}
			else { 
				strcpy(inputDirectory, ""); 
			}
		}

		// if currentDirectory is root
		else if(strcmp(currentDirectory, "/") == 0) {
			// change inputDirectory to empty string so ".." is not concatenated to the currentDirectory later on 
			strcpy(inputDirectory, ""); 
		}
	}


	// first character is slash (starting at root)
	else if(inputDirectory[0] == '/') {

		// just a slash or slash-dot
		if(strlen(inputDirectory) == 1 || (strlen(inputDirectory) == 2 && inputDirectory[1] == '.')) {
			// go to root
			int flag = chdir("/"); 
			if(flag == -1) {
				perror("Directory not changed");
				printf("Error at line %d\n", __LINE__);
				reset();
				return;
			}
			// change variable
			setenv_function("PWD", "/", 0); 
			return;
		} else {			
			strcpy(currentDirectory, "");
		}
	}


	// combines current with the input
	// check if relative
	strcat(currentDirectory, inputDirectory); 
	int flag = chdir(currentDirectory); 
	
	//error check absolute path
	if (flag == -1) { 
		int result2 = chdir(inputDirectory); 
		if (result2 == -1) {
			perror("currentDirectory not changed");
			printf("Error at line %d\n", __LINE__);
			reset();
			return;
		}
		setenv_function("PWD", inputDirectory, 0); //change PWD to absolute
		return;
	}

	// last character is a slash and currentDirectory isn't "/"
	if(strncmp(&currentDirectory[strlen(currentDirectory) - 1], "/", 1) == 0 && strlen(currentDirectory) != 1) {
		currentDirectory[strlen(currentDirectory) - 1] = '\0'; //remove slash
		setenv_function("PWD", currentDirectory, 0); //change PWD to absolute
	} else {
		setenv_function("PWD", currentDirectory, 0); //change PWD to absolute
	}
	reset();
}





