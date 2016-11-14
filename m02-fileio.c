/*
Kenneth Adair
Based on an example from Linux Systems Programming course by Chris Brown.
Taken from the "Demo: File Copy 1" section of the course.
 */

/* Trivial file copy program using low-level I/O */
#include <fcntl.h>
#include <stdlib.h>
//Buffer size, size of the chunks that we'll use to read/write the chunks of the file.
#define BSIZE 16384

void main()
{
  int fin, fout; /* input and output handles */
  //Here we declare the buffer
  char buf[BSIZE];
  int count;

  //open the input file
  if((fin = open("foo", O_RDONLY)) < 0){
    perror("foo");
    exit(1);
  }
  //open the file called bar for writing
  //mode 644 (permissions)
  if((fout = open("bar", O_WRONLY | O_CREAT, 0644)) < 0){
    perror("bar");
    exit(2);
  }
  /*perform, assign, test idiom...
  We're reading BSIZE bytes into the buffer, assign the count back to see if it's positive
  If it is we write that to the output file.
  We loop until we reach the end of the file.
  Once we finish we close it.
  */
  while((count = read(fin, buf, BSIZE)) > 0)
    write(fout, buf, count);

  close(fin);
  close(fout);
}
