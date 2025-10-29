#include <stdio.h>

int main()
{

    int n;
    printf("Enter the number of memory Blocks :");
    scanf("%d", &n);

    int blockSize[n];

    printf("Enter the size of each memory block : \n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter the size of block %d :", i + 1);
        scanf("%d", &blockSize[i]);
    }

    int m;
    printf("Enter the number of processes : ");
    scanf("%d", &m);

    int processSize[m];
    int allocated[m];
    printf("Enter the size of each process :\n");
    for (int i = 0; i < m; i++)
    {
        printf("Enter the size of process %d :", i + 1);
        scanf("%d", &processSize[i]);
        allocated[i] = -1;
    }

    // now implementing the best fit algorithms :

    for (int i = 0; i < m; i++)
    {
        int bestIndex = -1;
        for (int j = 0; j < n; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (bestIndex == -1)
                {
                    bestIndex = j;
                }
                else if (blockSize[j] < blockSize[bestIndex])
                {
                    bestIndex = j;
                }
            }
        }

        if (bestIndex != -1)
        {
            allocated[i] = bestIndex;
            blockSize[bestIndex] -= processSize[i];
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < m; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocated[i] != -1)
        {
            printf("%d\n", allocated[i] + 1);
        }
        else
        {
            printf("Not Allocated\n");
        }
    }

    return 0;
}