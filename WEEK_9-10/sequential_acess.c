#include <stdio.h>

typedef struct array
{
    char process_name[50];
    int startindex;
    int length;
} array;

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    array arr[n];
    int memoryblock[100] = {0}; 
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter process name: ");
        scanf("%s", arr[i].process_name);

        printf("Enter start index: ");
        scanf("%d", &arr[i].startindex);

        printf("Enter length: ");
        scanf("%d", &arr[i].length);

        int start = arr[i].startindex;
        int length = arr[i].length;

        if (start + length > 100)
        {
            printf(" Memory out of range for process %s!\n", arr[i].process_name);
            continue;
        }

        int freeFlag = 1;
        for (int j = start; j < start + length; j++)
        {
            if (memoryblock[j] == 1)
            {
                freeFlag = 0;
                break;
            }
        }

        if (freeFlag == 0)
        {
            printf("Blocks already allocated! Cannot allocate to process %s.\n", arr[i].process_name);
            continue;
        }

        for (int j = start; j <= start + length; j++)
        {
            memoryblock[j] = 1;
        }

        printf(" Allocated memory to process %s from index %d to %d.\n",
               arr[i].process_name, start, start + length  );
    }

    printf("\nMemory status (1 = allocated, 0 = free):\n");
    for (int i = 0; i < 100; i++)
    {
        printf("%d ", memoryblock[i]);
    }

    return 0;
}