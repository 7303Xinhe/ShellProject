void cd_home_function()
{
	int result = chdir(myHome); //get home directory and move to it
	if(result == -1) //error
	{
		perror("Directory not changed");
		printf("Error at line %d\n", __LINE__);
		return;
	}
	setenv_function("PWD", myHome, 0); //change PWD
}


void cd_function(char *text)
{
	changeGroupedSlashesIntoOneSlash(text); //alters the text so all grouped slashes now become one slash. ex. ////home///usr -> /home/usr
	char *directory = malloc(300 * sizeof(char));
	if (directory == (char *) NULL) //error
	{
		perror("Error with memory allocation.");
		printf("Error at line %d\n", __LINE__);
		reset();
		return;
	}
	strcpy(directory, getenv("PWD")); //start with current directory and see if it's relative or absolute
	if(directory[strlen(directory) - 1] != '/') //last character is not a slash
	{
		strcat(directory, "/"); //adds a slash
	}
	if(text[0] == '.')
	{
		if(strlen(text) == 1) //just a dot
		{
			strcpy(text, ""); //blank it
		}
		else if(strlen(text) == 2 && text[1] == '/') //just a dot-slash
		{
			strcpy(text, ""); //blank it
		}
		else if(strlen(text) > 2 && text[1] == '/')
		{
			strcpy(text, &text[2]);
		}
		else if(text[1] != '.') //append text after dot
		{
			strcpy(text, &text[1]);
		}
		else if(text[1] == '.' && strcmp(directory, "/") != 0)//go up a level (not in the root)
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
			}
			else if(lastSlashIndex == 0)
			{//if .. is returning up to the root directory
				directory[1] = '\0';//sets index 1 to null so the directory sets to the root
			}
			if(strlen(text) > 2)
			{
				strcat(directory, "/"); //add slash
				strcpy(text, &text[3]); //take everything after the slash
			}
			else //nothing
			{
				strcpy(text, ""); //blank it
			}
		}
		else if(strcmp(directory, "/") == 0)
		{//if it is in root
			strcpy(text,""); //change text to empty string so ".." is not concatenated to the directory later on
		}
	}
	if(text[0] == '/') //first character is slash
	{
		if(strlen(text) == 1 || (strlen(text) == 2 && text[1] == '.')) //just a slash or slash-dot
		{
			int result = chdir("/"); //move to slash directory
			if(result == -1)
			{
				perror("Directory not changed");
				printf("Error at line %d\n", __LINE__);
				reset();
				return;
			}
			setenv_function("PWD", "/", 0); //set to slash
			return;
		}
		else
		{
			char* text2 = malloc(300 * sizeof(char));
			if(text2 == (char *) NULL)
			{
				perror("Error with memory allocation.");
				printf("Error at line %d\n", __LINE__);
				reset();
				return;
			}
			strncpy(text2, text, strlen(text)); //copy everything after slash
			strcpy(text, text2); //copy back into text
			strcpy(directory, "");
		}
	}
	strcat(directory, text); //check if relative
	int result = chdir(directory); //move directory
	if (result == -1) //error, could be absolute, could be actual error
	{
		int result2 = chdir(text); //absolute
		if (result2 == -1) //error
		{
			perror("Directory not changed");
			printf("Error at line %d\n", __LINE__);
			reset();
			return;
		}
		setenv_function("PWD", text, 0); //change PWD to absolute
		return;
	}
	if(strncmp(&directory[strlen(directory) - 1], "/", 1) == 0 && strlen(directory) != 1) //last character is a slash and directory isn't just "/"
	{
		directory[strlen(directory) - 1] = '\0'; //remove slash
		setenv_function("PWD", directory, 0); //change PWD to absolute
	}
	else
	{
		setenv_function("PWD", directory, 0); //change PWD to absolute
	}
	reset();
}