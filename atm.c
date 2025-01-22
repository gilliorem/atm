#include <stdio.h>
#include <string.h>

struct user {
	unsigned int id;
	char name[30];
	char pin[4];
	float balance;
}; 


// notre programme de la maniere suivante : press '1' to set/change your ID.
// pouvoir verifier que l'id est unique. 
void set_id(struct user* account)
{
	account->id = 0;
	printf("Your current ID is : %d \n", account->id);
	printf("Please Enter your New ID:\n");
	unsigned int id = 0;
	scanf("%d", &id);
	if (id < 0)
	{
		printf("Error : id has to be greater than 0.\n");
		return;
	}
	account->id = id;
	printf("Your new ID is : %d.\n", account->id);
}

// faire un return 0 qui return au menu ?

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
	else if (amount %10 != 0)
	{
		printf("Amount has to mutiple of 10. \n");
		return;
	}
	else if (amount > account->balance)
	{
		printf("Sorry, the amount you wish to withdraw is greater than your current amount of money in your account.\n Please select an amount between $1 and $%f.", account->balance);
		return;
	}
	account->balance -= amount;
}

void display_menu(struct user* account)
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
		if (c != '\n' && c != EOF)
		{
			switch(c)
			{
				case '1':
					//withdraw(account->balance);
					break;
				case '4':
					fin = 1;
					break;
				default:
					printf("choix errone.\n");
			}
		}
	}

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
			printf("Wedome, %s.It is a pleasure to see you :) \n", users[i].name);
			return 0;
		}
	}
	printf("PIN Incorrect.\n");
	return 1;

}


int main()
{
	// initialisation d'un tableau de users;
	struct user users[3];
	//cree 3 users 

	struct user remi;
	set_id(&remi);
	printf("Remi new ID : %d. \n", remi.id);

	change_pin(&remi, "0123");

	
	//printf("remi's balance : $%.2f\n", remi.balance);
	deposit(&remi, 300);
//	printf("remi's balance : $%.2f\n", remi.balance);
	withdraw(&remi, 140);
//	printf("remi's balance : $%.2f\n", remi.balance);

	
	users[1].id = 2;
	strcpy(users[1].name, "Lisa");
	strcpy(users[1].pin, "1234");
	users[1].balance = 12150;

	users[2].id = 2;
	strcpy(users[2].name, "Romain");
	strcpy(users[2].pin, "1702");
	users[2].balance = 1000000;
	

	//if (!verify_pin(users))
	//	display_menu(users[0]);

	return 0;
}

