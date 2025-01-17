#include <stdio.h>
#include <string.h>

struct user {
	unsigned int id;
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
		printf("Sorry, the montant you wish to withdraw is greater than your current amount of money in your account.\n Please select an amount between $1 and $%f.", account->balance);
		return;
	}
	account->balance = account->balance - amount;
}

int main()
{
	struct user remi;
	remi.id = 1;
	strcpy(remi.pin, "0000");
	remi.balance = 0;
	
	printf("Remi's current balance : $%f \n", remi.balance);
	deposit(&remi, 42);
	printf("Remi's current balance : $%f \n", remi.balance);

	withdraw(&remi, 40);
	printf("Remi's current balance : $%f \n", remi.balance);

	
}

