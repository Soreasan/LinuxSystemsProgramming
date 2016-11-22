/*
Kenneth Adair
Command line argument processing using getopt()
Usage example: argdemo -a -b -n 400 -t purple
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int c;
	int aflag = 0;
	int bflag = 0;
	int numoption = 0;
	char txtoption[200] = "default";

	opterr = 0; /* Delete this to see getopt's own error messages */

	while((c = getopt(argc, argv, "abn:t:")) != EOF){
		switch(c){
			case 'a':
				aflag = 1;
				break;
			case 'b':
				bflag = 1;
				break;
			case 'n':
				numoption = atoi(optarg);
				break;
			case 't':
				strcpy(txtoption, optarg);
				break;
			case '?':
				fprintf(stderr, "invalid option: -%c\n", optopt);
			}
	}

	if(aflag) printf("Option a is set\n");
	if(bflag) printf("Option b is set\n");
	printf("Numeric option value is %d\n", numoption);
	printf("Text    option value is %s\n", txtoption);

	/* OK, now we have finished dealing with the options, argv has been 
	   re-ordered so that all have the non-option arguments come at the end
	   optind is now the index in argv of the first non-option argument. */

	argv += optind; /* Adjust to move past the options */
	argc -= optind;

	while(argc--) { /* print the non-option arguments */
		printf("arg: %s\n", *argv++);
	}
	return 0;
}
