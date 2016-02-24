#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    char *file = argv[1];
    int fd;
    struct flock lock;

    if (argc !=2 ) {
        printf("Usage: %s <file>\n", argv[0]);
        exit(1);
    }

    printf("opening %s\n", file);

    /* open a file descriptor to the file. */
    fd = open(file, O_WRONLY);
    
    printf("locking\n");

    /* initialize the flock structure */
    memset(&lock, 0, sizeof(lock));
    lock.l_type = F_WRLCK;

    /* place a write lock on the file */
    fcntl(fd, F_SETLKW, &lock);
    printf("locked; hit Enter to unlock...");
    /* waiting for the user to hit Enter */
    getchar();

    printf("unlocking\n");
    /* release the lock */
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLKW, &lock);

    close(fd);
    
    return 0;
}
