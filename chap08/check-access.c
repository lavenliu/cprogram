/*
 * Check File Access Permissions
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char *path = argv[1];
    int rval;

    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        exit(1);
    }
    /* check file existence */
    rval = access(path, F_OK);
    if (rval == 0) {
        printf("%s exists\n", path);
    } else {
        if (errno == ENOENT) {
            printf("%s does not exist\n", path);
        } else if (errno == EACCES) {
            printf("%s is not accessible\n", path);
        }
        return 0;
    }

    /* check read access */
    rval = access(path, R_OK);
    if (rval == 0) {
        printf("%s is readable\n", path);
    } else {
        printf("%s is not readable (access denied)\n", path);
    }

    /* check write access */
    rval = access(path, W_OK);
    if (rval == 0) {
        printf("%s is writeable\n", path);
    } else if (errno == EACCES) {
        printf("%s is not writable (access denied)\n", path);
    } else if (errno == EROFS) {
        printf("%s is not writable (read-only filssytem)\n", path);
    }

    return 0;
}
