/*
Kenneth Adair
Children of a fork often go off and execute a separate program.
exec goes off and executes separate code.
Taken from Linux Systems Programming course.  
*/

#include <stdio.h>
#include <unistd.h>

int main()
{
	static char *cmd[] = {"ps", "ls", "date", "goof"};
	int i;

	printf("0=ps, 1=ls, 2=date, 3=goof : ");
	scanf("%d", &i);

	execlp(cmd[i], cmd[i], NULL);

	printf("command not found\n");
	return 0;
}
