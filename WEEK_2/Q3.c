/*
 Write a program to read a file and store your details in that file. Your program should also create
 one more file and store your friends details in that file. Once both files are created, print lines
 which are matching in both files.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

int main() {
    FILE *myFile, *friendFile;
    char myLine[MAX_LINE_LENGTH];
    char friendLine[MAX_LINE_LENGTH];

    // Step 1: Create and write your details to "mydetails.txt"
    
    myFile = fopen("mydetails.txt", "w");
    if (myFile == NULL) {
        perror("Failed to create mydetails.txt");
        return 1;
    }
    fprintf(myFile, "Name: Priyanshu Pant\n");
    fprintf(myFile, "University: Graphic Era Hill University\n");
    fprintf(myFile, "Location: Dehradun\n");
    fprintf(myFile, "Hobby: Coding\n");
    fclose(myFile);

    // Step 2: Create and write friend's details to "friendsdetails.txt"
    friendFile = fopen("friendsdetails.txt", "w");
    if (friendFile == NULL) {
        perror("Failed to create friendsdetails.txt");
        return 1;
    }
    fprintf(friendFile, "Name: Deepanshu\n");
    fprintf(friendFile, "University: Graphic Era Hill University\n");
    fprintf(friendFile, "Location: Bihar\n");
    fprintf(friendFile, "Hobby: Coding\n");
    fclose(friendFile);

    // Step 3: Read both files and print matching lines
    myFile = fopen("mydetails.txt", "r");
    friendFile = fopen("friendsdetails.txt", "r");

    if (myFile == NULL || friendFile == NULL) {
        perror("Failed to open one of the files for reading");
        return 1;
    }

    printf("\nMatching lines in both files:\n");

    // Read each line from mydetails.txt
    while (fgets(myLine, sizeof(myLine), myFile) != NULL) {
        // Reset friend's file pointer to beginning for each line
        fseek(friendFile, 0, SEEK_SET);

        // Read each line from friendsdetails.txt
        while (fgets(friendLine, sizeof(friendLine), friendFile) != NULL) {
            // Remove trailing newline characters
            myLine[strcspn(myLine, "\n")] = '\0';
            friendLine[strcspn(friendLine, "\n")] = '\0';

            if (strcmp(myLine, friendLine) == 0) {
                printf("%s\n", myLine);
            }
        }
    }

    fclose(myFile);
    fclose(friendFile);

    return 0;
}
