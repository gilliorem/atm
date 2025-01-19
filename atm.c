#include <stdio.h>
#include <string.h>

struct user {
	unsigned int id;
	char pin[4];
	float balance;
}; 

struct user users[3];


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
	char c;
	while ((c = getchar()) != EOF)
	{
		printf("Press 1 to withdraw.\n");
		printf("Press 2 to deposit.\n");
	}
}

int verify_user_pin(struct user users[], char* pin)
{
	int i = 0;
	//users[user.pin] == pin
	if (strcmp(users->pin, pin) == 0)
	{
		printf("PIN Correct. \n");
		return 1;
	}
	else
	{
		printf("PIN Incorrect. \n");
		return 0;
	}
}


int main()
{
	struct user remi;
	remi.id = 1;
	strcpy(remi.pin, "0000");
	remi.balance = 0;

	struct user lisa;
	lisa.id = 2;
	strcpy(lisa.pin, "1234");
	lisa.balance = 0;
	
	struct user romain;
	romain.id = 3;
	strcpy(romain.pin, "0123");
	romain.balance = 0;

	char *pins[3] = {remi.pin, lisa.pin, romain.pin};

	char pin[4] = "0000";

	for (int i = 0; i < 3; i++)
	{
		users[i].id = i + 1;
		strcpy(users[i].pin, "0000");
		users[i].balance = 0;
	}
	for (int i = 0; i < 3; i++)
	{
		printf("Users :\n User %d\n id : %d.\n pin : %s.\n balance : %f.\n", users[i].id, users[i].id, users[i].pin, users[i].balance);
	}
			
}

