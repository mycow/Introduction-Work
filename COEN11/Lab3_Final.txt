#include <stdio.h>
#include <string.h>


void add();
void delete();
void display();

struct customer
{
	char names[20];
	int size;
};

//function adds customer name and size of party into arrays

void add(struct customer *party, int *counter)
{
	int same=-1, number;
	char temp[10];
	printf("Enter name: ");
	scanf("%s", temp);

	for(int i=0; i<*counter; i++)
	{
		same=strcmp(temp,party[i].names);

    	if(same==0)
		{
			printf("Name already exists.\n");
			return;
		}

	}


		strcpy(party[*counter].names, temp);
		printf("Enter size of party: ");
		scanf("%d", &party[*counter].size);
		(*counter)++;
		return;



}

//function deletes names and size of party from arrays and moves everything up the list
void delete(struct customer *party, int *counter)
{
	int same=1;
   	int number = 0;
	int tablesize;

	printf("Enter size of table availible: ");
	scanf("%d", &tablesize);

	for(int i=0; i<*counter; i++)
		{
			if(party[i].size<=tablesize)
			{
				number=i;
			}

		}

	for(int i=number; i<*counter; i++)
			{
				strcpy(party[i].names,party[i+1].names);
				party[i].size = party[i+1].size;
			}

	printf("Party successfully seated.");

	(*counter)--;

}

//function displays the entire list with party name next to party size

void display(struct customer *party, int *counter)
{
	printf("Guest list:\n");
	for (int i = 0; i < *counter; i++)
	{
		printf("Name: %s Party Size: %i\n", party[i].names, party[i].size);
	}
}


int main()
{
	struct customer list[10];
	int counter=0;
    int option;
	char name;

	while(1)
	{
		printf("Enter Option:\n 1. Add\n 2. Remove\n 3. Display\n 4. Quit\n");
		scanf("%d", &option);
		switch(option)
		{
			case 1:
			 add(list, &counter);
			 break;

			case 2:
			delete(list, &counter);
			break;

			case 3:
			display(list, &counter);
			break;

			case 4:
			return 0;
		}
	}
}