/*
 * using the system call
 */
#include <stdio.h>

int main(int argc, char *argv[])
{
    int return_value;
    return_value = system("ls -l /");
    
    return return_value;
}
