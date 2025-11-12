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

    // Input details for each file
    for (int i = 0; i < n; i++) {
        getchar(); // clear buffer
        printf("\nEnter file %d name: ", i + 1);
        scanf("%c", &files[i].name);

        printf("Enter starting block of file %d: ", i + 1);
        scanf("%d", &files[i].start_block);

        printf("Enter number of blocks in file %d: ", i + 1);
        scanf("%d", &files[i].no_of_blocks);

        printf("Enter blocks for file %d: ", i + 1);
        for (int j = 0; j < files[i].no_of_blocks; j++) {
            int b;
            while (1) {
                scanf("%d", &b);
                if (blocks[b] == false) {
                    printf("Block already occupied, enter another block: ");
                } else {
                    files[i].blocks[j] = b;
                    blocks[b] = false; // mark block as used
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
            printf("\nFile Name\tStart Block\tNo. of Blocks\tBlocks Occupied\n");
            printf("---------------------------------------------------------------\n");
            printf("   %c\t\t%d\t\t%d\t\t", 
                   files[i].name, files[i].start_block, files[i].no_of_blocks);

            for (int j = 0; j < files[i].no_of_blocks; j++) {
                printf("%d", files[i].blocks[j]);
                if (j != files[i].no_of_blocks - 1)
                    printf(", ");
            }
            printf("\n");
            found = true;
            break;
        }
    }

    if (!found) {
        printf("\nFile not found\n");
    }

    return 0;
}
