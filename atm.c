#include <stdio.h>
#include <string.h>

struct user {
	unsigned int id;
	char name[30];
	char pin[4];
	float balance;
}; 



unsigned int set_id(struct user* account)
{
	unsigned int new_id;
	unsigned int previous_id = account->id;
	printf("Enter your new id:");
	new_id = scanf("%u", &account->id);	
	if (new_id || account->id < 0)
	{
		printf("Error : id has to be greater than 0.\n");
		return previous_id;
	}
	new_id = account->id;
	return new_id;
}

void change_pin(struct user* account, char *new_pin)
{
	if (strlen(new_pin) != 4)
	{
		printf("Enter a 4 digit pin code\n");
		return;
	}
	strcpy(account->pin, new_pin);
}

void change_name(struct user* account, char *new_name)
{
	if (strlen(new_name) <= 1)
	{
		printf("Enter a valid name.\n");
		return;
	}
	strcpy(account->name, new_name);
}

void deposit(struct user* account, unsigned int amount)
{
	if (amount < 0)
	{
		printf("amount has to be greater than 0.\n");
		return ;
	}
	account->balance = account->balance + amount;
}

void withdraw(struct user* account, unsigned int amount)
{
	if (amount < 0)
	{
		printf("amount has to be greater than 0.\n");
		return ;
	}
	if (amount > account->balance)
	{
		printf("Sorry, the amount you wish to withdraw is greater than your current amount of money in your account.\n Please select an amount between $1 and $%f.", account->balance);
		return;
	}
	account->balance = account->balance - amount;
}

void display_menu()
{
	int fin = 0;
	while (!fin)
	{
		int c;
		printf("Press '1' to withdraw\n"
		"Press '2' to make a deposit.\n"
		"Press '3' to check balance.\n"
		"Press '4' to quit.\n");

		c = getchar();

}

int verify_pin(struct user *users)
{
	printf("Enter your PIN.\n");
	char pin[4];
	scanf("%s", pin);
	printf("PIN ENTER: %s\n", pin);
	for (int i = 0; i <= 3; i++)
	{
		if (strcmp(pin,users[i].pin) == 0)
		{
			printf("PIN Correct. \n");
			printf("Welcome, %s.It is a pleasure to see you :) \n", users[i].name);
			return 1;
		}
	}
	printf("PIN Incorrect.\n");
	return 0;

}


int main()
{
	struct user users[3];
	users[0].id = 1;
	strcpy(users[0].name, "Remi");
	strcpy(users[0].pin, "0000");
	users[0].balance = 10000;
	
	users[1].id = 2;
	strcpy(users[1].name, "Lisa");
	strcpy(users[1].pin, "1234");
	users[1].balance = 12150;

	users[2].id = 2;
	strcpy(users[2].name, "Romain");
	strcpy(users[2].pin, "1702");
	users[2].balance = 1000000;
	

	if (verify_pin(users))
		display_menu();

	return 0;
}

