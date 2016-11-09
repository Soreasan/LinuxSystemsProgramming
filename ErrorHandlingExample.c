/*
Kenneth Adair
This example does error handling for if a file fails to be created.
A way to force it to fail is to create the "foo" file and then change
its permissions to be unable to update and then run this program, then
you can force it to have an error.
Based on an example from the Linux Systems Programming course by Chris Brown on Pluralsight.  
 */

#include <fcntl.h>
//errno defines what the errors in errno are.
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

void main()
{
  int fd;
  //If system calls fail the return value is -1, if it succeeds it's a positive integer.
  fd = open("foo", O_WRONLY | O_CREAT, 0644);
  if(fd < 0){
    /*
      If there's an error in a c program there's
      a global variable that gives the actual error
      called errno.  For example 13 means permission denied.
      errno only gets set if there's an error.
     */
    printf("error number %d\n", errno);
    perror("foo");
    exit(1);
  }
}
