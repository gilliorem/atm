#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct user {
	unsigned int id;
	char name[30];
	char pin[4];
	float balance;
}; 


// notre programme de la maniere suivante : press '1' to set/change your ID.
// pouvoir verifier que l'id est unique. 

void set_id2(struct user* account)
{
	account->id = 0;
	char buffer[10];
	printf("current id : %d\n", account->id);
	printf("Enter you new ID:");
	fgets(buffer,10,stdin);
	int i = 0;
	if (buffer[0] == '\n')
	{
		printf("no back to line char\n");
		return;
	}
	while (buffer[i] != '\0')
	{
		switch (buffer[i])
		{
			case ' ':
			case '\t':
				printf("no white space\n");
				return;
		}
		i++;
	}
	printf("string that needs to be converted into unsigned int:%s\n", buffer);
	unsigned int new_id = 0;
	new_id = atoi(buffer);
	account->id = new_id;
	printf("New ID converted in int : %d \n", new_id);
}

void change_pin(struct user* account)
{
	char pin[100] = "0000";
	strcpy(account->pin, "0000");
	printf("Current Pin is %s\n",account->pin);
	printf("Enter new PIN\n");
	fgets(pin,sizeof(pin),stdin);
	pin[strcspn(pin, "\n")] = '\0';
	
	int i = 0;
	while (pin[i] != '\0')
	{
		if (pin[i] < '0' || pin[i] > '9')
		{
			printf("Error : PIN has to be a 4-digit format.\n");
			return;
		}
		i++;
	}
	if (strlen(pin) != 4)
	{
		printf("Error: PIN has to be 4-digit format.\n");
		return;
	}
	strcpy(account->pin, pin);
	printf("PIN changed Successfully.\nNew PIN :%s\n", account->pin);
}

void change_name(struct user* account)
{
	char name[100];
	strcpy(account->name, "user");
	printf("Current Username : %s\n", account->name);
	printf("Enter new Username :\n");
	fgets(name,sizeof(name), stdin);
	name[strcspn(name, "\n")] = '\0';
	int i = 0;
	while (name[i] != '\0') 
	{
		if ((name[i] < 'A'|| name[i] > 'z')||(name[i] > 'Z' && name[i] < 'a'))
		{
			printf("Error : Name only can contain alphabetic characters\n");
			return;
		}
		i++;
	}
	
	if (strlen(name) <= 1)
	{
		printf("Error : Name needs to contain more than 1 character.\n");
		return;
	}
	else if (strlen(name) > 30)
	{
		printf("Error : Name cannot exceed 30 characters\n");
		return;
	}
	strcpy(account->name, name);
	printf("User's new name : %s\n",account->name);
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
	struct user users[3];

	struct user remi;

	printf("User Name : %s\n",remi.name);
	change_name(&remi);
	printf("New user Name : %s\n",remi.name);

	
	//printf("remi's balance : $%.2f\n", remi.balance);
//	deposit(&remi, 300);
//	printf("remi's balance : $%.2f\n", remi.balance);
//	withdraw(&remi, 140);
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

