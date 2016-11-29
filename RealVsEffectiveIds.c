/*
Kenneth Adair
Program that demonstrates real and effective ids with different privileges
Taken from Linux Systems Programming course

To force the program to be more interesting do this:
sudo chown root ~/bin/uid
sudo chmod u+s ~/bin/uid
ls -l ~/bin/uid
gcc RealVsEffectiveIds.c -o RealVsEffectiveId
RealVsEffectiveId

The output should be something like this:
Real UID = 1000
Effective UID = 0
open: 3
access: -1
Real UID = 1000
Effective UID = 1000
open: -1
access: -1
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void main()
{
    printf("Real      UID = %d\n", getuid());
    printf("Effective UID = %d\n", geteuid());

    /* See if we can open hosts file for writing */
    printf("open: %d\n", open("/etc/hosts", O_RDWR));

    /* access() tests what the real user can do  */
    printf("access %d\n", access("/etc/hosts", W_OK));

    /* Now drop our root privilege and try again */
    seteuid(getuid());

    printf("Real      UID = %d\n", getuid());
    printf("Effective UID = %d\n", geteuid());

    /* See if we can open hosts file for writing */
    printf("open: %d\n", open("/etc/hosts", O_RDWR));

    /* access() tests what the real user can do */
    printf("access: %d\n", access("/etc/hosts", W_OK));
}
