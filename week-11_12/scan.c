#include <stdio.h>
#include <stdlib.h>

#define LOW 0
#define HIGH 199

int main() {
    int queue[20];
    int head, max, q_size, temp, sum;
    int dloc; // location of disk head in the array

    printf("Input number of disk locations: ");
    scanf("%d", &q_size);

    printf("Enter head position: ");
    scanf("%d", &head);

    printf("Input elements into disk queue:\n");
    for (int i = 0; i < q_size; i++) {
        scanf("%d", &queue[i]);
    }

    // Add read/write head into queue
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

    max = queue[q_size - 1];

    // Find head location in sorted queue
    for (int i = 0; i < q_size; i++) {
        if (head == queue[i]) {
            dloc = i;
            break;
        }
    }

    printf("\nDisk sequence (SCAN order):\n");

    // Determine direction: move toward lower end first or higher end
    if (abs(head - LOW) <= abs(head - HIGH)) {
        // Move toward LOW end first
        for (int j = dloc; j >= 0; j--) {
            printf("%d --> ", queue[j]);
        }
        for (int j = dloc + 1; j < q_size; j++) {
            printf("%d --> ", queue[j]);
        }
    } else {
        // Move toward HIGH end first
        for (int j = dloc + 1; j < q_size; j++) {
            printf("%d --> ", queue[j]);
        }
        for (int j = dloc; j >= 0; j--) {
            printf("%d --> ", queue[j]);
        }
    }

    sum = head + max;  // This is not actual seek time; just a placeholder sum
    printf("\nTotal head movement (approx): %d\n", sum);

    return 0;
}
