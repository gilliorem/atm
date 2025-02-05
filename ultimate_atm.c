#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct user 
{
	unsigned int id;
	unsigned int pin;
	char name[64];
};

struct user users[3];

struct user* active_user = NULL;

void display_user_menu()
{
	printf("Welcome %s\n", active_user->name);
}

void display_main_menu()
{
	printf("Enter your ID:\n");
	int asked_id = 0;
	scanf("%d",&asked_id);
	for (int i = 0; i < 3; i++)
	{
		if (asked_id == users[i].id)
		{
			active_user = &users[i];
			display_user_menu();
			return;
		}
		else
			printf("User with ID %d not found. \n", asked_id);  
	}
}

int main ()
{
	for (int i = 0; i < 3; i++)
		users[i].id = i+1;
	strcpy (users[0].name, "Remi");
	strcpy(users[1].name, "Romain");
	strcpy(users[2].name,"Lisa");
	display_main_menu();
}

