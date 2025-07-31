#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Executing ls command using execlp()...\n");

    execlp("ls", "ls", "-l", (char *)NULL);

    return 0;
}
