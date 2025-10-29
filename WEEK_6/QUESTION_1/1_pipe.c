#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int p[2];
    pid_t pid;
    char msg[] = "Hello from child";
    char buffer[50];

    if (pipe(p) == -1) {
        printf("Pipe creation failed!\n");
        return 1;
    }

    pid = fork();  // create child process

    if (pid == 0) {
        // Child Process
        close(p[0]); // Close unused read end
        write(p[1], msg, strlen(msg) + 1);
        printf("Child: message sent to parent.\n");
        close(p[1]);
    } else {
        // Parent Process
        close(p[1]); // Close unused write end
        read(p[0], buffer, sizeof(buffer));
        printf("Parent: received message: %s\n", buffer);
        close(p[0]);
    }

    return 0;
}
