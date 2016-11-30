/*
Kenneth Adair
This program makes some files and then uses ls to see the permissions.
Taken from Linux Systems Programming course.

Output looks something like this:
-rwxr-xr-x  1 kennethadair  staff  0 Nov 29 16:56 f1
-rwxr-x---  1 kennethadair  staff  0 Nov 29 16:56 f2
-rw-------  1 kennethadair  staff  0 Nov 29 16:56 f3
*/

#include <sys/stat.h>

void main()
{
    umask(0);
    creat("f1", 0755);

    umask(007);
    creat("f2", 0755);

    creat("f3", 0);
    chmod("f3", S_IRUSR | S_IWUSR);
    
    //Displays all files that start with "f" and have a single symbol after it.  
    //This means it displays only the three files even if it's in a folder with lots of files.
    system("ls -l f?");
}
