#include <stdio.h>
#include <stdlib.h>

#define LOW 0
#define HIGH 199

int main() {
    int queue[20], head, q_size, temp, sum = 0;
    int dloc; // head index in the queue

    printf("Enter number of disk requests: ");
    scanf("%d", &q_size);

    printf("Enter head position: ");
    scanf("%d", &head);

    printf("Enter disk requests:\n");
    for (int i = 0; i < q_size; i++) {
        scanf("%d", &queue[i]);
    }

    // Add head to the queue and sort
    queue[q_size] = head;
    q_size++;

    for (int i = 0; i < q_size; i++) {
        for (int j = i + 1; j < q_size; j++) {
            if (queue[i] > queue[j]) {
                temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }

    // Find head index
    for (int i = 0; i < q_size; i++) {
        if (queue[i] == head) {
            dloc = i;
            break;
        }
    }

    printf("\nDisk sequence (SCAN order):\n");

    // Assuming SCAN moves toward HIGH end first
    for (int i = dloc; i < q_size; i++) {
        printf("%d --> ", queue[i]);
    }

    // Go till the highest cylinder (199)
    if (queue[q_size - 1] != HIGH) {
        printf("%d --> ", HIGH);
    }

    // Then reverse direction and move toward LOW end
    for (int i = dloc - 1; i >= 0; i--) {
        printf("%d --> ", queue[i]);
    }

    // Calculate total seek movement
    // Move from head → highest request → HIGH → lowest request
    sum = (HIGH - head) + (HIGH - queue[0]);

    printf("\nTotal seek movement: %d\n", sum);
    return 0;
}
