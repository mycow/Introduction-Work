#include <stdio.h>
#include <string.h>
	
int counter=0;
char names[10][20];
char size[10];

int add()
{
	int same=0, number;
	char temp[10];
	printf("Enter name: ");
	scanf("%s", temp);
	if(counter==0)
	{
		strcpy(names[0], temp);
		printf("Enter size of party: ");
		scanf("%d", &number);
	}

	else

	{
		for(int i=0; i<counter; i++)
		{
			same=strcmp(names[i], temp);
		}
	}

	if(same!=0)
	{
		strcpy(names[counter], temp);
		printf("Enter size of party: ");
		scanf("%d", &number);
	}

	else

	if(same==0)
	{
		printf("Name already exists.");
	}

	counter++;

}

int delete()
{
	int same=1,  tablesize;

	printf("Enter size of table availible: ");
	scanf("%d", tablesize);

//	same=strcmp(number, tablesize)

	for(int i=0; i<counter; i++)
		{
			if(same!=0)
			{
				
			}
		}
}

int display()
{

}


int main()
{
        int option;
	char name;
	char names[10][20];
	
	while(1)
	{
		printf("Enter Option:\n 1. Add\n 2. Remove\n 3. Display\n 4. Quit");
		scanf("%d", &option);
		
		switch(option)
		{
			case 1:
			 add();
			 break;

			case2: 
	//		remove();
			break;

			case 3:
	//		display();
			break;

			case 4: 
			return 0;
		}
	}
}
