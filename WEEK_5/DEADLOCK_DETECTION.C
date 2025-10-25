#include <stdio.h>

int main() {
    int p, r;
    printf("Enter number of processes : ");
    scanf("%d", &p);
    printf("Enter number of resources : ");
    scanf("%d", &r);

    int max[p][r], alloc[p][r], need[p][r];
    int total[r], avail[r], finish[p];

    printf("Enter maximum requirement : \n");
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < r; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter allocated matrix : \n");
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < r; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Resource Vector : ");
    for (int j = 0; j < r; j++) {
        scanf("%d", &total[j]);
    }

    // Calculate available resources
    for (int j = 0; j < r; j++) {
        int sum = 0;
        for (int i = 0; i < p; i++) {
            sum += alloc[i][j];
        }
        avail[j] = total[j] - sum;
    }

    // Calculate need matrix
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < r; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
        finish[i] = 0; // Initially, none finished
    }

    int count = 0;
    int changed = 1;

    // Deadlock detection loop
    while (changed) {
        changed = 0;
        for (int i = 0; i < p; i++) {
            if (!finish[i]) {
                int canFinish = 1;
                for (int j = 0; j < r; j++) {
                    if (need[i][j] > avail[j]) {
                        canFinish = 0;
                        break;
                    }
                }
                if (canFinish) {
                    for (int j = 0; j < r; j++) {
                        avail[j] += alloc[i][j];
                    }
                    finish[i] = 1;
                    count++;
                    changed = 1;
                }
            }
        }
    }

    // Check if any process couldn't finish
    if (count == p) {
        printf("No deadlock detected\n");
    } else {
        printf("Deadlock detected\n");
    }

    return 0;
}
