#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NODE struct node

struct node
{
	char name[20];
	int number;
	NODE *next;
};

NODE *head=NULL;
NODE *tail=NULL;

void insert ()
{
	int same, numbertemp;
	char nametemp[20];
	NODE *current=head;
	NODE *temp;

	
        if((temp=(NODE *)malloc(sizeof(NODE)))==(NODE*)NULL)
        {
                printf("Can't do it.");
                return;
        }

	printf("Enter name: ");
	scanf("%s", nametemp);
        printf("Enter party size: ");
        scanf("%d", &numbertemp);

	strcpy(temp->name,nametemp);
	temp->number=numbertemp;

	if(head==NULL)
        {
		temp->next=NULL;
                head=temp;
                tail=temp;
		tail->next=NULL;
		return;
        }


	while(current!=NULL)
	{
		if(strcmp(nametemp, current->name)==0)
		{
			printf("Name is already taken!\n");
			return;
		}	
		current=current->next;
	}

	temp->next=NULL;
	tail->next=temp;
	tail=temp;
	tail->next=NULL;
}

void delete()
{
	int tablesize;
	NODE *current=head;

	printf("Enter size of party ready to be seated: ");
	scanf("%d", &tablesize);
	if(tablesize==tail->number)
	{
		
	}
	
}

void display()
{
	NODE *current=head;

	while(current != NULL)
	{
		printf("Name: %s Party Size: %d\n", current->name, current->number);
		current = current->next;
	}
	
}

int main()
{
	int option;

	while(1)
	{

		printf("Please enter an option:\n 1. Add\n 2. Remove\n 3. Display\n 4. Quit\n");
		scanf("%d", &option);
		switch(option)
		{
			case 1:
			insert();
			break;

			case 2:
			delete();
			break;
	
			case 3:
			display();
			break;

			case 4:
			return 0;
		}
	}
} 
