#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *hostname = getenv("HOSTNAME");
    char *user_name = getenv("USER");
    char *user_shell = getenv("SHELL");
    char *user_home = getenv("HOME");

    if (hostname == NULL) {
        hostname = "unknown hostname";
    }

    if (user_name == NULL) {
        user_name = "unknown user";
    }

    if (user_shell == NULL) {
        user_shell = "unknown shell";
    }

    if (user_home == NULL) {
        user_home = "unknown home";
    }

    printf("The hostname is: %s\n", hostname);
    printf("The current user is: %s\n", user_name);
    printf("The current user login shell is: %s\n", user_shell);
    printf("The current user home is: %s\n", user_home);
    
    return 0;
}
