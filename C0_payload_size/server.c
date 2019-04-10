#include <door.h>
#include <stdio.h>
#include <unistd.h>
#include <stropts.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <err.h>

#include "common.h"

void handle(void* cookie, char* args, size_t nargs, door_desc_t* descriptors, uint_t ndescriptors) {
	door_return(cookie, nelem * elsize, NULL, 0);
}

int main() {
        struct stat buf;

	char* path = "server.door";

        int door = door_create(&handle, calloc(nelem, elsize), 0);
        if (door == -1) err(1, "Handle cannot be attached to door");

        if (stat(path, &buf) < 0) {
                int newfd;
                if ((newfd = creat(path, 0600)) < 0) err(1, "creat");
                close(newfd);
        }

        fdetach(path);

        int attachment = fattach(door, path);
        if (attachment == -1) err(1, "Could not attach door to server.door");

        printf("%s will remain attached to this process for 1 hour\n", path);

	sleep(3600);

	return 0;
}
