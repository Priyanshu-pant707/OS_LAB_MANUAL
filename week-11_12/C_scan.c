#include <stdio.h>
#include <stdlib.h>

#define LOW 0
#define HIGH 199

int main() {
    int queue[20];
    int head, q_size, temp;
    int total_movement = 0;
    int dloc; // location of disk head in array

    printf("Input number of disk locations: ");
    scanf("%d", &q_size);

    printf("Enter head position: ");
    scanf("%d", &head);

    printf("Input elements into disk queue:\n");
    for (int i = 0; i < q_size; i++) {
        scanf("%d", &queue[i]);
    }

    // Add head into queue
    queue[q_size] = head;
    q_size++;

    // Sort the array
    for (int i = 0; i < q_size; i++) {
        for (int j = i + 1; j < q_size; j++) {
            if (queue[i] > queue[j]) {
                temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }

    // Find location of head in sorted queue
    for (int i = 0; i < q_size; i++) {
        if (head == queue[i]) {
            dloc = i;
            break;
        }
    }

    printf("\nDisk sequence (C-SCAN order):\n");

    // Move from head toward HIGH, then jump to LOW, then to just before head
    for (int j = dloc; j < q_size; j++) {
        printf("%d --> ", queue[j]);
    }

    // After reaching HIGH, jump to LOW (circular return)
    printf("%d --> ", HIGH);
    printf("%d --> ", LOW);

    for (int j = 0; j < dloc; j++) {
        printf("%d --> ", queue[j]);
    }

    // Calculate total head movement
    total_movement = (HIGH - head) + (HIGH - LOW) + (queue[dloc - 1] - LOW);

    printf("\nTotal head movement: %d\n", total_movement);

    return 0;
}
