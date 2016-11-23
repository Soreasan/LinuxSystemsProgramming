/*
Kenneth Adair
Equivalent to "ls | sort -r" 
Taken from Linux Systems Programming
Lists files in reverse alphabetical order
*/

#include <unistd.h>

void main()
{
    int p[2];

    pipe(p);    /* Create the pipe */
    if(fork() == 0){
        /* Child: connect stdout to pipe */
        dup2(p[1], 1);
        close(p[0]);
        //Execute ls
        execlp("ls", "ls", (char *)0);
    }
    /* Parent: connect stdin to pipe */
    dup2(p[0], 0);
    close(p[1]);
    execlp("sort", "sort", "-r", (char *)0);
}
