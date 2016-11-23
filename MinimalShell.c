/*
Kenneth Adair
A simple shell that uses execlp to simply run the commandline stuff
that the user types in.  
Taken from Linux Systems Programming course.
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/* A minimal shell */
int main()
{
	char line[100];

	/* Main command loop */
	while(printf("> "), gets(line) != NULL){
		if(fork() == 0){ /* child */
			execlp(line, line, (char *)0);

			/* Don't come here unless execlp fails */
			printf("%s: not found\n", line);
			exit(1);
		}
		else wait(0); /* parent */

		/* Now loop back and prompt again */
	}

}
