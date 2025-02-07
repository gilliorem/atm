#include <unistd.h>
#include <stdio.h>

int main()
{
	for (int i = 0; i < 3; i++)
	{
		sleep(1);
		//write(1, ".",1);
		putchar('.');
		fflush(stdout);
	}
	return 0;
}
