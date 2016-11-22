/*
Kenneth Adair
This program takes a commandline argument and then searches to see
if there is a matching environment variable.
Taken from Linux Systems Programming course
Run it with: ./a.out HOME LOGNAME FOO
*/

/* Show value of a specified environment variables */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int i;
	char *val;

	for(i = 1; i < argc; i++){
		if((val = getenv(argv[i])) != NULL)
			printf("%s: %s\n", argv[i], val);
		else
			printf("%s: not in environment\n", argv[i]);
	}
}
