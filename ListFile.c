/*
Kenneth Adair
Lists details about a file
From Linux Systems Programming course
 */

#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char * argv[])
{
  //We begin by allocating a stat structure
  struct stat sb; /* the stat buffer */
  
  /* Array of file types, indexed by the top four bits of st_mode */

  char *filetype[] = { "unknown", "FIFO", "character device", "unknown", "directory",
		       "unknown", "block device", "unknown", "file",
		       "unknown", "symlink", "unknown", "socket" };
  //This lets us get the filename from the commandline rather than hardcoding it into the code.
  if(argc != 2){
    fprintf(stderr, "usage: listfile filename\n");
    exit(1);
  }

  //This gets the stats for the file and tests for errors
  if(stat(argv[1], &sb) < 0){
    perror(argv[1]);
    exit(2);
  }

  printf("file type: %s\n", filetype[(sb.st_mode >> 12) & 017]);
  /*
    CODE BELOW IS NOT IN ORIGINAL SAMPLE CODE
    CODE BELOW IS NOT IN ORIGINAL SAMPLE CODE
    CODE BELOW IS NOT IN ORIGINAL SAMPLE CODE
  */
  //Not in original sample code, didn't understand bitwise operators
  /*
    So after tinkering I've determined that the sb.st_mode returns
    a number and the S_IRUSR also returns a number.  The "&" is a 
    bitwise AND operator.  (& is an "ampersand")  This bitwise operator
    checks each individual bit and if they are both 1/true then that
    bit becomes 1.  If one bit is 1 and the other is 0 then it becomes 0.
    Similarly if both bits are 0 then it becomes zero as well.  Our program
    below is using this bitwise operators to check if the AND/& operator
    returns a non-zero.  If it does then that means we have a permission.
    If it returns 0/false then that means we don't have that permission.
   */
  printf("sb.st_mode is: %i and S_IRUSR is: %i.\n", sb.st_mode, S_IRUSR);
  printf("sb.st_mode & S_IRUSR is: %i\n", (sb.st_mode & S_IRUSR));
  printf("sb.st_mode is: %i and S_IXUSR is: %i.\n", sb.st_mode, S_IXUSR);
  printf("sb.st_mode & S_IXUSR is: %i\n", (sb.st_mode & S_IXUSR));
  /*
    ABOVE CODE IS NOT IN ORIGINAL SAMPLE CODE
    ABOVE CODE IS NOT IN ORIGINAL SAMPLE CODE
    ABOVE CODE IS NOT IN ORIGINAL SAMPLE CODE
  */

  //Gets the filetype
  /* If we take sb.st_mode and shift it right by 12 bits and 
     mask everything off but bottom 4 bits we end up with a 
     number in between 0 and 15, we use that to index into the
     array of strings (*filetype) that specifies the type of the file
     Then we pluck out the appropriate filetype description which we
     print out using printf */
  printf("permissions: %c%c%c%c%c%c%c%c%c\n",
	 (sb.st_mode & S_IRUSR) ? 'r' : '-',
	 (sb.st_mode & S_IWUSR) ? 'w' : '-',
	 (sb.st_mode & S_IXUSR) ? 'x' : '-',
	 (sb.st_mode & S_IRGRP) ? 'r' : '-',
	 (sb.st_mode & S_IWGRP) ? 'w' : '-',
	 (sb.st_mode & S_IXGRP) ? 'x' : '-',
	 (sb.st_mode & S_IROTH) ? 'r' : '-',
	 (sb.st_mode & S_IWOTH) ? 'w' : '-',
	 (sb.st_mode & S_IXOTH) ? 'x' : '-');

  printf("last accessed: %s", ctime(&sb.st_atime));
  printf("last modified: %s", ctime(&sb.st_mtime));
  printf("last change:   %s", ctime(&sb.st_ctime));
}
