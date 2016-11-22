/* 
Kenneth Adair
Simple fork example 
Taken from Linux Systems Programming course
*/

#include <stdio.h>

//Added a declaration to get rid of a warning.  It isn't actually necessary though.
int fork();

int main()
{
	if(fork())
		printf("I am the parent\n");
	else
		printf("I am the child\n");
	
	return 0;
}
