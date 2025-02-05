#include <string.h>
#include <stdio.h>

int main ()
{
	char name[10] = "remi";
	printf("%s\n", name);
	strcpy(name, "lisa");
	printf("%s\n", name);
}
