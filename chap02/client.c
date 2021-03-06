#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *server_name = getenv("SERVER_NAME");
    if (server_name == NULL) {
        /* The SERVER_NAME environment variable was not set. Use
         * the default. */
        server_name = "server.lavenliu.com";
    }

    printf("accessing server %s\n", server_name);
    
    return 0;
}
