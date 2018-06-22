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

void insert(NODE **head, NODE **tail)
{
	int same, numbertemp, index, i;
	char nametemp[20];
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
	strcpy(temp->name, nametemp);
	temp->number=numbertemp;

	if(temp->number<=2)
	{
		index=0;
	}
	else if(temp->number==3 || temp->number==4)
	{
		index=1;
	}
	else if(temp->number==5 || temp->number==6)
	{
		index=2;
	}
	else if(temp->number>=7)
	{
		index=3;
	}

		if(head[index]==NULL)
		{
			temp->next=NULL;
			head[index]=temp;
			tail[index]=temp;
			tail[index]->next=NULL;
			return;
		}

	for(i=0; i<4; i++)
        {
                NODE *current=head[i];

		while(current!=NULL)
		{
			if(strcmp(nametemp, current->name)==0)
			{
				printf("Name is already taken!\n");
				return;
			}
			current=current->next;
		}
	}
	
	temp->next=NULL;
	tail[index]->next=temp;
	tail[index]=temp;
	tail[index]->next=NULL;
		
}

void delete(NODE **head, NODE **tail)
{
	int tablesize, index, i;
	NODE *temp;

	printf("Enter size of party ready to be seated: ");
	scanf("%d", &tablesize);

	if(tablesize<=2)
        {
                index=0;
        }
        else if(tablesize==3 || tablesize==4)
        {
                index=1;
        }
        else if(tablesize==5 || tablesize==6)
      	{
                index=2;
        }
        else if(tablesize>=7)
        {
		index=3;
        }	

	int num=index;
	
	while(head[index]==NULL)
	{
		num--;
		
		if(head[num]!=NULL)
			break;
	}

	NODE *previous=head[num];
	NODE *current=previous->next;
	for(i=num; i>=0; i--)
	{
		while(current!=NULL && current->number<=tablesize)
		{
			previous=previous->next;
			current=current->next;
		}
		
		if(head[i]!=NULL && head[i]->number<=tablesize)
		{
			printf("%s shall now be seated!\n", head[i]->name);
			previous=head[i];
			head[i]=head[i]->next;
			free(previous);
			printf("...\nSuccessfully seated!\n");
			return;
		}
	
		while(current!=NULL)
		{
			if(current->number<=tablesize)
			{
				printf("%s shall now be seated!\n", previous->name);
				previous->next=current->next;
				free (current);
				printf("...\nSuccessfully seated!\n");
				return;
			}
		}
	}
	
	return;
		
}


void display(NODE **head)
{	
	int i;
	for(i=0; i<4; i++)
	{
		NODE *current=head[i];
		
		printf("List %d Contains\n ---------------\n", i+1);

		while(current!=NULL)
		{
			printf("Name: %s || Party Size: %d\n\n", current->name, current->number);
			current=current->next;
		}
	}
}

int main()
{
	int option;
	NODE *head[4]={NULL, NULL, NULL, NULL};
	NODE *tail[4]={NULL, NULL, NULL, NULL};

	printf("Welcome to the Hao Kitchen Seating Menu\n");

	while(1)
	{
		printf("Please enter an option:\n 1. Add\n 2. Remove\n 3. Display\n 4. Quit\n");
		scanf("%d", &option);
		switch(option)
		{
			case 1:
			insert(head, tail);
			break;

			case 2:
			delete(head, tail);
			break;
	
			case 3:
                        display(head);
                        break;

			case 4:
                        return 0;
		}
	}
}
