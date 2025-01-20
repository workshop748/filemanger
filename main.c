#include"stdio.h"
#include"string.h"


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
		}
		printf(" you selected %d",choice);
		break; 

		switch (choice)
		{
		case 1: {
			char name[100];
			printf("please enter a file name you want to create");
			while (scanf("%96s", &name) != 1)
			{
				printf("please enter a valid file name");
			}

			concat(name, ".txt");
			FILE* file = fopen(name, "w");
			if (file == NULL)
			{
				printf("file could not be created");
			}
			else
			{
				printf("file created");
				fclose(file);
			}
			break;
		}
		case 2:
		{
			char name[100];
			char letter;
			printf("please enter a file name you want to create");
			while (scanf("%96s", &name) != 1)
			{
				printf("please enter a valid file name");
			}

			concat(name, ".txt");
			FILE* file = fopen(name, "r");
			if (file == NULL)
			{
				printf("file could not be created");
			}
			else
			{
				while ((letter = fgetc(file)) != EOF) {
					printf("%c", letter);
				}
				flose(file);
			}
			break;
		}
		case 3:
		{
			char name[100];
			printf("please enter a file name you want to create");
			while (scanf("%96s", &name) != 1)
			{
				printf("please enter a valid file name");
			}

			concat(name, ".txt");
			break;
		}
		case 4:
		{
			char name[100];
			printf("please enter a file name you want to create");
			while (scanf("%96s", &name) != 1)
			{
				printf("please enter a valid file name");
			}

			concat(name, ".txt");
			break;
		}
		case 5:
		{
			char name[100];
			printf("please enter a file name you want to create");
			while (scanf("%96s", &name) != 1)
			{
				printf("please enter a valid file name");
			}

			concat(name, ".txt");
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