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

NODE * search(NODE *head, int data)
{
	NODE *previous=NULL;
	NODE *current=head;

	while(current!=NULL && current->number>data)
        {
		previous=current;
		current=current->next;
        }

	return previous;
}


void insert()
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
	NODE *previous, *temp;

	printf("Enter size of party ready to be seated: ");
	scanf("%d", &tablesize);

	if(tablesize>=head->number)
	{
		printf("Now Seating %s\n", head->name);
		temp=head;
		head=head->next;
		free(temp);
		printf("Party Successfully Seated!"); 
		return;
	}

	previous=search(head, tablesize);

        NODE *p=previous->next;
	
	if(p==NULL)
	{
		printf("No party can be found");
		return;
	}

	else

	{
		printf("Now Seating %s\n", p->name);
		previous->next=p->next;
		free(p);
		printf("Party Successfully Seated!");
		return;
	}
}

void display()
{
	NODE *current=head;

	while(current != NULL)
	{
		printf("Name: %s ||  Party Size: %d\n", current->name, current->number);
		current = current->next;
	}
	
}

int main()
{
	int option;

	printf("Welcome to the Hao Kitchen Seating Menu\n");

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
