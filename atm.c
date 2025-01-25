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

void set_id(struct user* account)
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

void deposit(struct user* account)
{
	account->balance = 0;
	char buffer[10];
	printf("Current balance : $%.2f\n", account->balance);
	printf("Enter deposit amount:\n");
	fgets(buffer,10,stdin);
	buffer[strcspn(buffer, "\n")] = '\0';
	int i = 0;
	if (buffer[0] == '\n')
	{
		printf("no back to line char\n");
		return;
	}
	while (buffer[i] != '\0')
	{
		if (buffer[i] < '0' || buffer[i] > '9')
		{
			printf("Error : input has to be numeric value.\n");
			return;
		}
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
	unsigned int amount = 0;
	amount = atoi(buffer);
	account->balance = amount;
	printf("Amount converted in int : %d \n", amount);
	if (amount < 0)
	{
		printf("amount has to be greater than 0.\n");
		return ;
	}
	else if (amount %10 != 0)
	{
		printf("Error : Deposit amount must be a mutliple of ten.\n");
		return;
	}
	account->balance = account->balance + amount;
}

void withdraw(struct user* account)
{
	char buffer[10];
	printf("Current balance : $%.2f\n", account->balance);
	printf("Enter withdraw amount:\n");
	fgets(buffer,10,stdin);
	buffer[strcspn(buffer, "\n")] = '\0';
	int i = 0;
	if (buffer[0] == '\n')
	{
		printf("no back to line char\n");
		return;
	}
	while (buffer[i] != '\0')
	{
		if (buffer[i] < '0' || buffer[i] > '9')
		{
			printf("Error : withdraw amount has to be numerical value.\n");
			return;
		}
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
	unsigned int amount = 0;
	amount = atoi(buffer);
	account->balance = amount;
	printf("Amount converted in int : %d \n", amount);
	if (amount < 0)
	{
		printf("amount has to be greater than 0.\n");
		return ;
	}
	else if (amount %10 != 0)
	{
		printf("Error : withdraw amount must be a mutliple of ten.\n");
		return;
	}
	else if (amount > account->balance)
	{
		printf("Error: the amount to withdraw can't be greater that your current balance.\n");
	return;
	}
	account->balance -= amount;
}


void display_menu(struct user* account)
{
	int choice = -1;
	
	printf("Press '1' to withdraw\n"
			"Press '2' to make a deposit.\n"
			"Press '3' to set a new ID.\n"
			"Press '4' to change PIN.\n"
			"Press '5' to change name.\n"
			"Press '6' to quit.\n");
	int flag = 0;
	while (!flag)
	{
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				withdraw(account);
				break;
			case 2:
				deposit(account);
				break;
			case 3:
				set_id(account);
				break;
			case 4:
				change_pin(account);
				break;
			case 5:
				change_name(account);
				break;
			case 6:
				flag = 1;
				return;
			default:
			printf("Invalid input.\n");
			break;
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

	display_menu(&remi);
	
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

	return 0;
}

