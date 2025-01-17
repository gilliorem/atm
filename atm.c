#include <stdio.h>

struct account {
	int id;
	char name[30];
	long balance;
};

void displayAccount(struct account acc)
{
	printf("Welcome %s\n", acc.name);
	printf("You have %lg$ in your account.\n");
	printf("Press 1 to withdraw.\n Press 2 to deposit.\n");
	scanf("%d");
}

int main()
{
	struct account myAccount = {1, "John Doe", 1042};
	displayAccount(myAccount);
	return 0;
}
