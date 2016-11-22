/*
Kenneth Adair
Monitors specific files for changes using inotify.  Only works on Linux, not OSX. 
*/

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/inotify.h>
#endif
#include <limits.h>

/* A bugger big enough to read 100 events in one go */
#define BUFSIZE(100 * (sizeof(struct inotify_event) + NAME_MAX + 1))

void main()
{
	FILE *fconfig; /* Descriptor for config file */
	FILE *fout; /* Descriptor for output file */
	/* Just a buffer to hold filenames in. */
	char watchname[PATH_MAX];
	/* stat gets information about each file */
	struct stat sb;
	int notifyfd, watchfd;
	char eventbuf[BUFSIZE]; /* Events are read into here */
	int n;
	char *p;
	struct inotify_event *event;

	/* An array of pathnames */
	/* Here we hold the names of the watched files, indexed by the watch descriptor. */
	char watchednames[100][NAME_MAX+1];

	notifyfd = inotify_init(); /* Not checked for error */

	/* Open the config file */
	if((fconfig = fopen("monitor.conf", "r")) == NULL){
		printf("unable to open the config file; giving up!\n");
		exit(1);
	}

	/* Read all watched file names from config file */
	while(fgets(watchname, PATH_MAX, fconfig) != NULL){
		/* Get rid of the newline */
		watchname[strlen(watchname) - 1] = '\0';

		if(stat(watchname, &sb) < 0){
			printf("Cannot stat %s, ignored\n", watchname);
			continue; 
		}

		if(S_ISREG(sb.st_mode)){
			/* Regular file, so add to watch list */
			if((watchfd = inotify_add_watch(notifyfd, watchname, IN_MODIFY | IN_DELETE_SELF)) < 0){
				printf("error adding watch for %s\n", watchname);
			}else{
				printf("added %s to watch list on descriptor %d\n", watchname, watchfd);
				/* Record the file we're watching on this watch descriptor */
				strcpy(watchednames[watchfd], watchname);
			}
		}else{ /* probably a directory */
			printf("%s is not a regular file, ignored\n", watchname);
		}
	}

	/* All our watches are in place, so just read and report events */
	fout = fopen("monitor.out", "a");

	while(1){
		n = read(notifyfd, eventbuf, BUFSIZE);
		/* Loop over all events and report them.  This is a little tricky
			because the event records are not of fixed length
		*/
		
		for(p = eventbuf; p < eventbuf + n;){
			event = (struct inotify_event) + event->len;
			/* Display the event */
			if(event->mask & IN_MODIFY) fprintf(fout, "%s was modified\n", watchnames[event->wd]);
			if(event->mask & IN_DELETE_SELF) fprintf(fout, "%s was deleted\n", watchnames[event->wd]);
			fflush(fout);
		}
	}
}
		}
