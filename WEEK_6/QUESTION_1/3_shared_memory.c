#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

int main() {
    // Create a unique key
    key_t key = ftok("shmfile", 65);

    // Create shared memory segment
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    // Fork to create parent and child
    if (fork() == 0) {
        // Child process - Write into shared memory
        char *str = (char*) shmat(shmid, NULL, 0);
        strcpy(str, "Hello from Child");
        printf("Child wrote data to shared memory.\n");
        shmdt(str);
    } else {
        sleep(1);  // wait for child to write
        // Parent process - Read from shared memory
        char *str = (char*) shmat(shmid, NULL, 0);
        printf("Parent read from shared memory: %s\n", str);
        shmdt(str);
        shmctl(shmid, IPC_RMID, NULL); // delete memory segment
    }

    return 0;
}
