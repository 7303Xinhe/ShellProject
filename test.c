void execute() {

	if(strcmp(wordArray[0], "") == 0) {
		return;
	}

	int child;
	if((child = fork()) == -1) {
		perror("Error forking");
		printf("Error at line %d\n", __LINE__);
		reset();
		exit(0);
		return;
	}	

	// in parent
	if(child != 0) { 
		// wait for process to finish executing
		if(ampersandIndex == 0) {
			wait((int *) 0);
		}
		reset();
	}

	else {
		
		char* previous = malloc(500 * sizeof(char));
		int i;
		for(i = 0; i < wordCount; ++i) {
			if( strcmp(wordArray[i], "<") == 0 ) {
				if(i == 0) {
					return;
				}

			}
			else if( strcmp(wordArray[i], ">") == 0 ) {
				if(i == 0) {
					return;
				}
				
			}
			else if( strcmp(wordArray[i], "|") == 0 ) {
				if(i == 0) {
					return;
				}

			}
			else if( strcmp(wordArray[i], "&") == 0 ) {

			}
			else if( strcmp(wordArray[i], "2>&1") == 0 ) {

			}
			else if( strcmp(wordArray[i], "2>") == 0 ) {

			}
			else {

			}

		}
	}




}