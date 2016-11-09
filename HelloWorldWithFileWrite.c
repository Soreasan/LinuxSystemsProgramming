/*
Kenneth Adair
This example is taken from the "Linux Systems Programming" by Chris Brown on Pluralsight.
 */

// This provides the symbolic constants
#include <fcntl.h>

// Main is the entry point for a C program
void main()
{
  int fd;
  /* 
     Open is a system call which takes a file name as an argument.
     In this case "foo" will be the file name
     O_WRONLY means write only
     O_CREATE means the file should be created if it doesn't exist
     0644 is the access permissions of the new file.  (rw-r--r--)
     These symbolic constants come from the header file
  */
  fd = open("foo", O_WRONLY | O_CREAT, 0644);
  write(fd, "hello world", 11);
  close(fd);
}
