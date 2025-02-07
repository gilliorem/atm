#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct user 
{
	unsigned int id;
	unsigned int pin;
	float balance;
	char name[64];
};

struct user users[3];

struct user* active_user = NULL;

void display_user_menu()
{
	printf("Welcome %s\n", active_user->name);
	printf("Enter your PIN:");

	unsigned int asked_pin = 0;
	unsigned int choice = 0;
	scanf("%d", &asked_pin);
	if (asked_pin == active_user->pin)
	{
		printf("Press 1 to see current balance.\n");
		scanf("%d", &choice);
		if (choice == 1)
		{
			printf("PIN Correct.\n");
			printf("ID %d\nYour current balance is :$%.2f\n", active_user->id, active_user->balance);
			return;
		}
	}
	else
		printf("Wrong PIN.\n");

	
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
	}
	printf("User with ID %d not found. \n", asked_id);  
}

int main ()
{
	for (int i = 0; i < 3; i++)
		users[i].id = i+1;
	strcpy (users[0].name, "Remi");
	strcpy(users[1].name, "Romain");
	strcpy(users[2].name,"Lisa");
	users[0].pin = 1234;
	users[1].pin = 5678;
	users[2].pin = 9012;

	users[0].balance = 23142;
	users[1].balance = 10000;
	users[2].balance = 1000000;
	display_main_menu();
}

