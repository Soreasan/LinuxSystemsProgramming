/*
Kenneth Adair
Lists the environment variables.
*/

#include <stdio.h>

extern char **environ;

int main(int argc, char *argv[])
{
	char **p;

	for(p=environ; *p != NULL; p++)
		printf("%s\n", *p);
}
