#include <stdio.h>
#include <stdbool.h>

typedef struct file {
    char name;
    int start_block;
    int blocks[100];
    int no_of_blocks;
} file;

int main() {
    bool blocks[1000];
    
    // Initialize all blocks as free
    for (int i = 0; i < 1000; i++) {
        blocks[i] = true;
    }

    int n;
    printf("Enter number of files: ");
    scanf("%d", &n);

    file files[n];

    for (int i = 0; i < n; i++) {
        getchar(); // to clear buffer
        printf("\nEnter file %d name: ", i + 1);
        scanf("%c", &files[i].name);

        printf("Enter starting block of file %d: ", i + 1);
        scanf("%d", &files[i].start_block);

        printf("Enter number of blocks in file %d: ", i + 1);
        scanf("%d", &files[i].no_of_blocks);

        printf("Enter blocks for file %d:\n", i + 1);
        for (int j = 0; j < files[i].no_of_blocks; j++) {
            int b;
            while (1) {
                scanf("%d", &b);
                if (blocks[b] == false) {
                    printf("Block is already occupied, enter another block: ");
                } else {
                    files[i].blocks[j] = b;
                    blocks[b] = false; // mark as occupied
                    break;
                }
            }
        }
    }

    // Search a file
    char ch;
    getchar();
    printf("\nEnter the file name to be searched: ");
    scanf("%c", &ch);

    bool found = false;

    for (int i = 0; i < n; i++) {
        if (files[i].name == ch) {
            printf("\nFile Found!\n");
            printf("File Name: %c\n", files[i].name);
            printf("Start Block: %d\n", files[i].start_block);
            printf("No. of Blocks: %d\n", files[i].no_of_blocks);
            printf("Blocks Occupied (Linked): ");

            for (int j = 0; j < files[i].no_of_blocks; j++) {
                printf("%d -> ", files[i].blocks[j]);
            }
            printf("NULL\n");

            found = true;
            break;
        }
    }

    if (!found) {
        printf("\nFile not found\n");
    }

    return 0;
}
