// FIFO.c
#include <stdio.h>

int main()
{
    int n;
    printf("enter the size of the array ");
    scanf("%d", &n);

    int original[n];

    int m;
    printf("enter the size of the lru");
    scanf("%d", &m);

    int lru[m];

    printf("enter the elements in the array : \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &original[i]);
    }

    int hit = 0;
    int miss = 0;
    int k = 0;

    for (int i = 0; i < m; i++)
    {
        lru[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        int val = original[i];
        int found = 0;

        int arr[m];
        for (int h = 0; h < m; h++)
        {
            arr[h] = lru[h];
        }

        printf("pintinf the lru chache for %d :\n", i);
        for (int t = 0; t < m; t++)
        {
            printf("%d ", arr[t]);
        }
        printf("\n");

        for (int j = 0; j < m; j++)
        {
            if (val == lru[j] && lru[0] != 0)
            {
                hit++;
                found = 1;
                break;
            }
        }
        if (found == 0)
        {
            miss++;
            k = k % m;
            lru[k] = val;
            k++;
        }
    }

    printf("performing lru cache:\n");

    printf("hit : %d\n", hit);
    printf("miss : %d\n", miss);

    return 0;
}

