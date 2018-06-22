#include <stdio.h>
#include <string.h>

void insert();
void delete();
void show();

union status
{
    char school[20];
    float salary;
    int retire;
};

struct person
{
    char name[20];
    int age;
    union status report;
};

void add(struct person *info, int *counter)
{
    char temp[20];

	printf("Enter name: ");
	scanf("%s", temp);

    strcpy(info[*counter].name, temp);

    printf("Enter age: ");
    scanf("%d", &info[*counter].age);

    if(info[*counter].age<=21)
    {
        printf("Enter name of school you currently attend: ");
        scanf("%s", info[*counter].report.school);
    }
    else if(21<info[*counter].age && info[*counter].age<65)
    {
        printf("Enter annual salary: $");
        scanf("%f", &info[*counter].report.salary);
    }
    else if(65<=info[*counter].age)
    {
        printf("Enter years of retirement: ");
        scanf("%d", &info[*counter].report.retire);
    }
    (*counter)++;
    return;
}

void delete(struct person *info, int *counter)
{
    int same=1;
   	int number = 0;
	char nametemp[20];
	int i;

	printf("Enter name of person's info to delete: ");
	scanf("%s", nametemp);

	for(i=0; i<*counter; i++)
		{
		    same=strcmp(info[i].name, nametemp);

			if(same==0)
			{
				number=i;
				break;
			}

		}

	for(i=number; i<*counter; i++)
			{
				strcpy(info[i].name,info[i+1].name);
				info[i].age = info[i+1].age;
				info[i].report = info[i+1].report;
			}

	printf("Personal info successfully removed.\n");

	(*counter)--;
}

void display(struct person *info, int *counter)
{
    int i;
	printf("Personal Information:\n");
	for (i = 0; i < *counter; i++)
	{
		printf("Name: %s Age: %i \n", info[i].name, info[i].age);

		if(info[i].age<=21)
        {
            printf("School: %s \n", info[i].report.school);
        }
        else if(21<info[i].age && info[i].age<65)
        {
            printf("Salary: $ %f \n", info[i].report.salary);
        }
        else if(65<=info[i].age)
        {
            printf("Years of retirement: %d years\n", info[i].report.retire);
        }
	}
}


int main()
{
	struct person list[20];
	int counter=0;
    int option;

    printf("Welcome to the personal information storing center.\n\n");

	while(1)
	{
		printf("Please enter an option:\n 1. Add\n 2. Remove\n 3. Display\n 4. Quit\n");
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
