/* 
Kenneth Adair
This program does a loop in which a parent and child both 
iterate through a loop.  This demonstrates that the parent/child
stuff means that his program isn't deterministic.  That means the
output will be different each time.
File fork_loop.c 
Taken from Linux Systems Programming course
*/

#include <stdio.h>

void main()
{
	int i;
	if(fork()){
		for(i = 0; i < 100000; i++)
			printf("**    PARENT  %d\n", i);
	}else{
		for(i = 0; i < 100000; i++)
			printf("  **  CHILD   %d\n", i);
	}
}

/*
	The key point is that the parent and child output will be interweaved in
	a non-deterministic way.  If you run the program several times, this
	behavior shows up clearly.  Occasionally you may see child output appearing
	AFTER the prompt.  This is expected behavior.
*/
