#include <stdio.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int           soft_nofile;
    int           hard_nofile;
    int           ref_nofile = 2048;
    int           MAX_NOFILE = 65535;
    struct rlimit rl;

    /* obtain the current limits. */
    getrlimit(RLIMIT_NOFILE, &rl);
    soft_nofile = rl.rlim_cur;
    printf("The current number of open files is: %d\n", soft_nofile);
    
    if (soft_nofile < ref_nofile) {
        printf("Current number of open files is not satisfied\n");
        printf("It will be changed to %d.\n", MAX_NOFILE);
        rl.rlim_cur = MAX_NOFILE / 2;
        rl.rlim_max = MAX_NOFILE;
        setrlimit(RLIMIT_NOFILE, &rl);
    } else {
        printf("nofile is passed\n");
    }

    /* check again */
    getrlimit(RLIMIT_NOFILE, &rl);
    printf("nofile is %ld\n", rl.rlim_cur);
    
    return 0;
}
