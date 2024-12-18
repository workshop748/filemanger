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
		printf("hello and welcome to my file manger");
		printf("there are a few options for you to choose from");
		printf("1. create a file");
		printf("2. read a file");
		printf("3. write to a file");
		printf("4. append to a file");
		printf("5. find a word in a file");
		printf("6. exit");

		scanf("%d", choice);

		switch (choice)
		{
		case 1:
			printf("please enter a file name you want to create");
		case 2:
			printf("please enter a file name you want to read");
		case 3:
			printf("please enter a file name you want to write to");
		case 4:
			printf("please enter a file name you want to append to");
		case 5:
			printf("please enter a file name you want to append to");
		case 6:
			printf("thank you for your vist");
			break;
		default:
		{
			printf("that is not a vaule option");
		}
		}

	}

	printf("thank you for playing aroubd");
	return 0;
}