/*
cd word directory name This command changes the current directory to the one
named. You must handle cd with no arguments, to take you back to the home
directory, i.e. it should have the same effect as cd ˜ (see Tilde Expansion).
*/
void cd_home_function() {
	
	int result = chdir(home); // move to home dir
	
	// error
	if(result == -1) {
		perror("Directory not changed");
		printf("Error at line %d\n", __LINE__);
		return;
	}

	setenv_function("PWD", home, 0); //change PWD
	printf("Current directory: %s\n", getenv("PWD"));
}

void cd_function(char *text) {
	shortenSlashes(text); 
	
	char *directory = malloc(300 * sizeof(char));
	
	if (directory == (char *) NULL) {
		perror("Error with memory allocation.");
		printf("Error at line %d\n", __LINE__);
		reset();
		return;
	}
	
	// start with current directory 
	strcpy(directory, getenv("PWD")); 
	
	// add slash to end if needed
	if(directory[strlen(directory) - 1] != '/') {
		strcat(directory, "/"); // adds a slash
	}


	// if text begins with a '.'
	if(text[0] == '.') {

		// just a dot and nothing else
		if(strlen(text) == 1) {
			strcpy(text, "");
			printf("Current directory: %s\n", getenv("PWD")); 
			return;
		}

		//just a dot-slash
		else if(strlen(text) == 2 && text[1] == '/') {
			strcpy(text, ""); 
			printf("Current directory: %s\n", getenv("PWD")); 
			return;
		}

		// (e.g.) ./blah
		else if(strlen(text) > 2 && text[1] == '/') {
			strcpy(text, &text[2]); // change starting point after the '/'
		}

		// '..' go up a level if not in the root
		else if((text[1] == '.') && (strcmp(directory, "/") != 0)) {
			int i;
			int lastSlashIndex = 1;

			// find second to last slash in directory 	
			for(i = strlen(directory) - 2; i >= 0; i--) {
				if(directory[i] == '/') {
					lastSlashIndex = i; 
					break;
				}
			}

			// doesn't return to root
			if(lastSlashIndex != 0) { 
				directory[lastSlashIndex] = '\0';
			}

			// return to the root directory
			else if(lastSlashIndex == 0) {
				// sets index 1 to null so the directory sets to the root
				directory[1] = '\0'; 
			}


			if(strlen(text) > 2) {
				strcat(directory, "/"); //add slash
				strcpy(text, &text[3]); //take everything after the slash
			}
			else //nothing
			{
				strcpy(text, ""); //blank it
			}
		}

		// append text after dot. relative cd
		else if(text[1] != '.') {
			strcpy(text, &text[1]);
		}

		// // if currently in root
		// else if(strcmp(directory, "/") == 0) {
		// 	strcpy(text,""); //change text to empty string so ".." is not concatenated to the directory later on
		// }

	}
	
	// if text begins with a '/'
	else if(text[0] == '/') {

		// just a slash or slash-dot
		if(strlen(text) == 1 || (strlen(text) == 2 && text[1] == '.')) {
			// move to slash directory	
			int result = chdir("/"); 
			if(result == -1) {
				perror("Directory not changed");
				printf("Error at line %d\n", __LINE__);
				reset();
				return;
			}
			setenv_function("PWD", "/", 0); //set to slash
			return;
		}
		else {
			// char* text2 = malloc(300 * sizeof(char));
			if(text2 == (char *) NULL) {
				perror("Error with memory allocation.");
				printf("Error at line %d\n", __LINE__);
				reset();
				return;
			}
			// strncpy(text2, text, strlen(text)); // copy everything after slash
			// strcpy(text, text2); 
			strcpy(directory, ""); // empty directory
		}
	}


	strcat(directory, text); // check if relative
	int result = chdir(directory); // move directory
	
	if (result == -1) {
		int result2 = chdir(text); // absolute
		if (result2 == -1) // error
		{
			perror("Directory not changed");
			printf("Error at line %d\n", __LINE__);
			reset();
			return;
		}
		setenv_function("PWD", text, 0); //change PWD to absolute
		return;
	}

	// last character is a slash and directory isn't just "/"
	if(strncmp(&directory[strlen(directory) - 1], "/", 1) == 0 && strlen(directory) != 1) {
		directory[strlen(directory) - 1] = '\0'; //remove slash
		setenv_function("PWD", directory, 0); //change PWD to absolute
	}

	else {
		setenv_function("PWD", directory, 0); //change PWD to absolute
	}
	printf("Current directory: %s\n", getenv("PWD"));
	reset();
}

// removes extra slashes in the beginning of a string so ////home -> /home, ./////home -> ./home
void shortenSlashes(char* string) { 
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