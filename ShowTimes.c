/*
Kenneth Adair

A simple use of stat, doesn't have error chac
 */

#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

void main()
{
  struct stat sb; /* the stat buffer */

  //foo is a hardcoded file name
  stat("foo", &sb);

  //The information from the file goes into the stat object.
  printf("last accessed: %s", ctime(&sb.st_atime));
  printf("last modified: %s", ctime(&sb.st_mtime));
  printf("last change:   %s", ctime(&sb.st_ctime));
}
