/*
Kenneth Adair
Enumerates through user accounts and get passwd objects.
Lists accounts with uid >= 1000
Results are generally the word "nobody" twice.
*/

#include <stdio.h>
#include <pwd.h>

int main(int argc, char *argv[])
{
    struct passwd *u;

    while((u = getpwent()) != NULL){
        if(u->pw_uid >= 1000)
            printf("%s\n", u->pw_name);
    }
    return 0;
}
