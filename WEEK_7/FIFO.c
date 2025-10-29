#include <stdio.h>

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int original[n];

    int m;
    printf("Enter the size of the FIFO cache: ");
    scanf("%d", &m);

    int lru[m];

    printf("Enter the elements in the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &original[i]);
    }

    int hit = 0;
    int miss = 0;
    int k = 0;

    // initialize cache as empty (-1 means empty)
    for (int i = 0; i < m; i++)
    {
        lru[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        int val = original[i];
        int found = 0;

        printf("\nBefore accessing %d, cache state: ", val);
        for (int t = 0; t < m; t++)
        {
            if (lru[t] == -1)
                printf("_ ");
            else
                printf("%d ", lru[t]);
        }
        printf("\n");

        // Check if page is already in cache (hit)
        for (int j = 0; j < m; j++)
        {
            if (val == lru[j])
            {
                hit++;
                found = 1;
                break;
            }
        }

        // If not found, it's a miss → replace using FIFO
        if (found == 0)
        {
            miss++;
            lru[k] = val;
            k = (k + 1) % m; // move FIFO pointer circularly
        }

        printf("After accessing %d, cache: ", val);
        for (int t = 0; t < m; t++)
        {
            if (lru[t] == -1)
                printf("_ ");
            else
                printf("%d ", lru[t]);
        }
        printf("\n");
    }

    printf("\nFinal Results:\n");
    printf("Hits : %d\n", hit);
    printf("Miss : %d\n", miss);

    return 0;
}
