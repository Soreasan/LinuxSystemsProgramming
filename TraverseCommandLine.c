/*
Kenneth Adair 
This program gets the commandline arguments and prints them back out. 
Taken from Linux Systems Programming course.
*/

#include  <stdio.h>

int main(int argc, char *argv[])
{
	int i;

	for(i = 0; i < argc; i++)
		printf("%s\n", argv[i]);
}
