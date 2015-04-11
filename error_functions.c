int standard_error_redirect_function() {
	savedError = dup(2); //get current standard error
	//redirect output to standard error
	if (dup2(1, 2) == -1) {//error
		perror("Standard error not redirected to output");
		printf("Error at line %d\n", __LINE__);
		return -1;
	}
	return 0;
}

int standard_error_redirect_function2(char *text) {
	char* copyText = malloc(300 * sizeof(char));
	if (copyText == (char *)NULL) { //error
		perror("Memory allocation error.");
		printf("Error at line %d\n", __LINE__);
		return -1;
	}
	strcpy(copyText, &text[2]); //get everything after >
	int out = open(copyText, O_WRONLY | O_CREAT | O_TRUNC | S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR); //open file
	if(out == -1) {//error
		perror("File not created");
		printf("Error at line %d\n", __LINE__);
		return -1;
	}
	savedError = dup(2); //get current standard error 
	//redirect standard error to output file
	if (dup2(out, 2) == -1) {//error
		perror("Standard error not redirected");
		printf("Error at line %d\n", __LINE__);
		return -1;
	}
	return 0;
}