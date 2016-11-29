/*
Kenneth Adair
Mimics functionality of the linux command "id"
Taken from Linux Systems Programming course.
*/

#include <stdio.h>
#include <pwd.h>
#include <grp.h>

int main(int argc, char *argv[])
{
    //Initialize variables
    uid_t uid;
    gid_t gid;
    struct passwd *u;
    struct group *g;
    char *member;

    //Return the user id of a running process
    uid = getuid();
    printf("uid=%d", uid);
    
    //Map numeric user id to a user name
    u = getpwuid(uid);
    printf("(%s) ", u->pw_name);

    gid = getgid();
    printf("gid=%d", gid);

    g = getgrgid(gid);
    printf("(%s) ", g->gr_name);

    //Looping over all groups
    while((g = getgrent()) != NULL){
        //printf("%s\n", g->gr_name);
        //Looping through members of the group
        while((member = *(g->gr_mem)++) != NULL)
            if(strcmp(member, u->pw_name) == 0)
                printf("%d(%s),", g->gr_gid, g->gr_name);
    }
    printf("\n");
}
