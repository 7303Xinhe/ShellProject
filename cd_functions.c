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
void cd_function(char *text){

	condenseSlashes(text); 

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

	if(text[0] == '.') {
		if(strlen(text) == 1) {//just a dot
			strcpy(text, ""); //blank it
		}
		else if(strlen(text) == 2 && text[1] == '/') { //just a dot-slash
			strcpy(text, ""); //blank it
		}
		else if(strlen(text) > 2 && text[1] == '/') {
			strcpy(text, &text[2]);
		}
		else if(text[1] != '.') {//append text after dot
			strcpy(text, &text[1]);
		}
		else if(text[1] == '.' && strcmp(currentDirectory, "/") != 0) {//go up a level (not in the root)
			int i;
			int lastSlashIndex = 1;
			for(i = strlen(currentDirectory) - 2; i >= 0; i--) {//find occurence of last slash
				if(currentDirectory[i] == '/') {
					lastSlashIndex = i; //found last slash
					break;
				}
			}
			if(lastSlashIndex != 0) { //if .. does not return to the root currentDirectory
				currentDirectory[lastSlashIndex] = '\0';//sets the second to last slash to a null character
			}
			else if(lastSlashIndex == 0) {//if .. is returning up to the root currentDirectory
				currentDirectory[1] = '\0';//sets index 1 to null so the currentDirectory sets to the root
			}
			if(strlen(text) > 2) {
				strcat(currentDirectory, "/"); //add slash
				strcpy(text, &text[3]); //take everything after the slash
			}
			else { //nothing
				strcpy(text, ""); //blank it
			}
		}
		else if(strcmp(currentDirectory, "/") == 0) {//if it is in root
			strcpy(text,""); //change text to empty string so ".." is not concatenated to the currentDirectory later on
		}
	}
	if(text[0] == '/') {//first character is slash
		if(strlen(text) == 1 || (strlen(text) == 2 && text[1] == '.')) {//just a slash or slash-dot
			int result = chdir("/"); //move to slash currentDirectory
			if(result == -1) {
				perror("currentDirectory not changed");
				printf("Error at line %d\n", __LINE__);
				reset();
				return;
			}
			setenv_function("PWD", "/", 0); //set to slash
			return;
		}
		else {
			char* text2 = malloc(300 * sizeof(char));
			if(text2 == (char *) NULL) {
				perror("Error with memory allocation.");
				printf("Error at line %d\n", __LINE__);
				reset();
				return;
			}
			strncpy(text2, text, strlen(text)); //copy everything after slash
			strcpy(text, text2); //copy back into text
			strcpy(currentDirectory, "");
		}
	}
	strcat(currentDirectory, text); //check if relative
	int result = chdir(currentDirectory); //move currentDirectory
	if (result == -1) { //error, could be absolute, could be actual error
		int result2 = chdir(text); //absolute
		if (result2 == -1) { //error
			perror("currentDirectory not changed");
			printf("Error at line %d\n", __LINE__);
			reset();
			return;
		}
		setenv_function("PWD", text, 0); //change PWD to absolute
		return;
	}
	if(strncmp(&currentDirectory[strlen(currentDirectory) - 1], "/", 1) == 0 && strlen(currentDirectory) != 1) {//last character is a slash and currentDirectory isn't just "/"
		currentDirectory[strlen(currentDirectory) - 1] = '\0'; //remove slash
		setenv_function("PWD", currentDirectory, 0); //change PWD to absolute
	}
	else{
		setenv_function("PWD", currentDirectory, 0); //change PWD to absolute
	}
	reset();
}
