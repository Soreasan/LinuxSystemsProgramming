/*
Kenneth Adair 
Add up sizes of all files in the current directory 
Based on example from Linux Systems Programming course.
*/

#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>

void main()
{
  DIR *d;
  struct dirent *info; /* A directory entry */
  struct stat sb; /* the stat buffer */
  long total = 0; /* Total of file sizes */

  //Opens current directory
  d = opendir(".");

  //Goes from file to file until it has looped through every file.
  while((info = readdir(d)) != NULL){
    //Uses stat to get information about the file
    stat(info->d_name, &sb);
    //Retrieves the size of the file and adds it to the total
    total += sb.st_size;
  }

  closedir(d);

  printf("total size = %ld\n", total);
}
