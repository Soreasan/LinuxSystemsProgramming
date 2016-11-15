/*
Kenneth Adair
Linux Systems Programming course, Chris Brown
Example from "Random Access" section
 */

#include <unistd.h>
#include <fcntl.h>

//Record structure
struct record{
  int id;
  char name[80];
};

void main()
{
  //the size contains the size in bytes of the record structure
  int fd, size = sizeof(struct record);
  struct record info;
  //open the file for reading and writing
  fd = open("datafile", O_RDWR);

  //Seeks one record along from the beginning of the file.
  //effectively skipping one record.
  lseek(fd, size, SEEK_SET);
  //Read the second record
  read(fd, &info, size);
  //changing data in the record
  info.id = 99;
  //read automaticaly moves our pointer thing forward so we use lseek to
  //move back one record, we're effectively backspacing back to the previous record
  lseek(fd, -size, SEEK_CUR);
  // Writes the modified record back into its original position
  write(fd, &info, size);
  close(fd);
  
}
