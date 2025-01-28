#include <stdio.h>

/*void read_file(FILE *ifp)
{
	ifp = fopen(ifp, "r");
	int c;
	while((c = getc(ifp)) != EOF)
		putc(c, stdout);
}
*/

void set_id_file()
{
	
	printf("enter new ID:");
	char id[5];
	FILE *fp = fopen("users.txt","w");
	scanf("%s",id);
	fprintf(fp,"%s", id);
	fclose(fp);
}

void write_file(FILE *fp, char *file, char *content)
{
	fp = fopen(file, "w");
	fprintf(fp, "%s", content);
	fclose(fp);
}

int main()
{
	set_id_file();
	return 0;
}

