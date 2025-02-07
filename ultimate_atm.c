#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

struct user 
{
	unsigned int id;
	unsigned int pin;
	float balance;
	char name[64];
};

struct user users[3];
void display_main_menu();
struct user* active_user = NULL;

void display_users(struct user users[], int max_users)
{
	FILE *file = fopen("users", "r");

	unsigned int i = 0;
	while (i < max_users && fscanf(file, "%d", &users[i].id == 4))
		i++;
}


void display_user_menu()
{
	printf("Welcome %s\n", active_user->name);

	unsigned int asked_pin = 0;
	unsigned int choice = 0;
	unsigned wrong_pin_counter = 3;
	while (choice != 6)
	{
		printf("Enter your PIN:");
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
		{
			--wrong_pin_counter;
			printf("Wrong PIN.\n%d tries left before logout\n",wrong_pin_counter);
			if (wrong_pin_counter == 0)	
			{
				write(1,"Logout",6);
				for (int i = 0; i < 3; i++)
				{
					sleep(1);
					write(1,".",1);
				}
				printf("\n");
				display_main_menu();
			}
		}
	}
}

void display_main_menu()
{
	int asked_id = 0;
	while (1)
	{
		printf("Enter your ID:\n");
		scanf("%d",&asked_id);
		for (int i = 0; i < 3; i++)
		{
			if (asked_id == users[i].id)
			{
				active_user = &users[i];
				display_user_menu();
				sleep(10);
				printf("Exit.\n");
			}
		}
		printf("User with ID %d not found. \n", asked_id);  
	}
}

int main ()
{
	return 0;
}

