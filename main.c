#include"stdio.h"
#include"string.h"

#define Max_WORD_SIZE 1000

void concat(char* name, char* end)
{
	int i = 0;

	
	while (name[i] != '\0')
		i++;

	
	int j = 0;
	while (end[j] != '\0') {
		name[i] = end[j];
		i++;
		j++;
	}

	name[i] = '\0';
}
int main()
{
	
	while(1) {
		int choice = 0;
		
		printf("hello and welcome to my file manger\n");
		printf("there are a few options for you to choose from\n");
		printf("1. create a file\n");
		printf("2. read a file\n");
		printf("3. write to a file\n");
		printf("4. append to a file\n");
		printf("5. find a word in a file\n");
		printf("6. exit\n");

		while (scanf("%d", &choice) != 1) {
			printf("please enter a valid option");
			while (getchar() != '\n');
		}
		printf(" you selected %d\n",choice);
		while (getchar() != '\n');

		switch (choice)
		{
		case 1: {
			//this is for creating a file
			char name[100];
			printf("please enter a file name you want to create\n");
			while (scanf("%96s", &name) != 1)
			{
				printf("please enter a valid file name\n");
				while (getchar() != '\n');
			}

			concat(name, ".txt");
			FILE* file = fopen(name, "w");
			if (file == NULL)
			{
				printf("file could not be created");
				return -1;
			}
			else
			{
				printf("file created\n");
				fclose(file);
			}
			break;
		}
		case 2:
		{
			//this is for reading from a file
			char name[100];
			char letter;
			printf("please enter a file name you want to read from\n");
			while (scanf("%96s", &name) != 1)
			{
				printf("please enter a valid file name");
				while (getchar() != '\n');
			}

			concat(name, ".txt");
			FILE* file = fopen(name, "r");
			if (file == NULL)
			{
				printf("There was a error reading from the file");
				return -1;
			}
			else
			{
				while ((letter = fgetc(file)) != EOF) {
					printf("%c", letter);
				}
				
			}
			fclose(file);
			break;
		}
		case 3:
		{
			//this is writing from a file
			char name[100];
			printf("please enter a file name you want to write to: \n");
			while (scanf("%96s", &name) != 1)
			{
				printf("please enter a valid file name");
				while (getchar() != '\n');
			}

			concat(name, ".txt");
			FILE* file = fopen(name, "w");
			if (file != NULL)
			{
				char word[Max_WORD_SIZE];
				printf("please enter a words you want to write to the file: ");
				while (getchar() != '\n'); //clear the buffer

				if (fgets(word, sizeof(word), stdin) != NULL) {
				fprintf(file, "%s", word);
				printf("your file has been written to\n");
				}
				else {
					printf("There was an error writing to the file");
				}
			}
			else {
				printf("There was an error opening the file");
			}

			fclose(file);
			printf("\n");
			break;
		}
		case 4:
		{
			//this is for appending to a file
			char name[100];
			printf("please enter a file name you want to to append to: \n");
			while (scanf("%96s", &name) != 1)
			{
				printf("please enter a valid file name");
			}

			concat(name, ".txt");
			FILE* file = fopen(name, "a");
			if (file != NULL)
			{
				char word[Max_WORD_SIZE];
				printf("please enter a words you want to append to the file: ");
				while (getchar() != '\n'); //clear the buffer

				
				if (fgets(word, sizeof(word), stdin) != NULL) {
					fprintf(file, "%s", word);
					printf("your file has been written to\n");
				}
			}
			else {
				printf("There was an error opening the file");
			}
			fclose(file);

			break;
		}
		case 5:
		{
			//this is for finding a word in a file
			char name[100];
			printf("please enter a file name you want to find a word in:\n");
			while (scanf("%96s", &name) != 1)
			{
				printf("please enter a valid file name");
			}

			concat(name, ".txt");
			char line[Max_WORD_SIZE];
			char word[100];
			printf("please enter a file name you want to create");
			while (scanf("%96s", &word) != 1)
			{
				printf("please enter a valid word");
			}
			int line_number = 0;
			int found = 0;
			FILE* file = fopen(name, "r");
			while (fgets(line, sizeof(line), file)) {
				line_number++;
				if (strstr(line, word) != NULL)
				{
					printf("Found '%s' on line %d: %s",word, line_number,line);
					found = 1;
				}
			}

			fclose(file);
			break;
		}
		case 6:
			printf("thank you for your vist");
			return 0;
		default:
		{
			printf("that is not a vaule option");
		}
		}

	}

	printf("thank you for playing around");
	return 0;
}