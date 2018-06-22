#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NODE struct node

void insertmod(char *array, int num);

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

void read_file(char *fname)
{
	FILE *thing;
	int size;
	char name[20];
	thing=fopen(fname, "r");
	if(thing==NULL)
	{
		printf("Nah!\n");
		return;
	}
	fseek(thing, 14, SEEK_SET);
	while(fscanf(thing, "%s\t %d", name, &size)!=EOF)
	{
		insertmod(name, size);
	}
	fclose(thing);
	return;
}

void write_file(char *fname)
{
	FILE *thing;
	NODE *p=head;
	thing=fopen(fname, "w");
	if(thing==NULL)
	{
		printf("Nah!\n");
		return;
	}
	
	fprintf(thing, "Name\t Group Size\n\n");
	
	while(p!=NULL)
	{
		fprintf(thing, "%s\t %d\n", p->name, p->number);
		p=p->next;
	}
	
	fclose(thing);
	return;
}

void insertmod(char *array, int num)
{
	NODE *current=head;
        NODE *temp;


        if((temp=(NODE *)malloc(sizeof(NODE)))==(NODE*)NULL)
        {
                printf("Can't do it.");
                return;
        }

	strcpy(temp->name,array);
        temp->number=num;

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
                if(strcmp(array, current->name)==0)
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

int main(int argc, char *argv[])
{
	FILE *thing;
        int size;
        char name[20];
        thing=fopen(argv[1], "r");
        if(thing==NULL)
        {
                printf("Nah!\n");
                return 0;
        }
        fseek(thing, 14, SEEK_SET);
        while(fscanf(thing, "%s\t %d", name, &size)!=EOF)
	{
		printf("%s\t %d\n", name, size);
	}

	read_file(argv[1]);

        thing=fopen(argv[1], "r");
        if(thing==NULL)
        {
                printf("Nah!\n");
                return 0;
        }
        fseek(thing, 14, SEEK_SET);
        while(fscanf(thing, "%s\t %d", name, &size)!=EOF)
	{
		printf("%s\t %d\n", name, size);
	}

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
			write_file(argv[1]);
			printf("List Successfully Saved!\n");
			return 0;
		}
	}
} 

