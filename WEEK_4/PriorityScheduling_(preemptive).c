#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

struct process_struct
{
    int at;   // Arrival Time
    int bt;   // Burst Time
    int priority;
    int ct, wt, tat, rt, start_time;
} ps[100];

int main()
{
    int n;
    bool is_completed[100] = {false};
    int bt_remaining[100];
    int current_time = 0;
    int completed = 0;
    float sum_tat = 0, sum_wt = 0, sum_rt = 0;

    scanf("%d", &n);

    // Arrival Times
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ps[i].at);
    }

    // Burst Times
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ps[i].bt);
        bt_remaining[i] = ps[i].bt;
    }

    // Priorities
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ps[i].priority);
    }

    while (completed != n)
    {
        // Find process with maximum priority in ready queue at current time
        int max_index = -1;
        int maximum = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            if (ps[i].at <= current_time && is_completed[i] == false)
            {
                if (ps[i].priority > maximum)
                {
                    maximum = ps[i].priority;
                    max_index = i;
                }
                if (ps[i].priority == maximum)
                {
                    if (ps[i].at < ps[max_index].at)
                    {
                        maximum = ps[i].priority;
                        max_index = i;
                    }
                }
            }
        }

        if (max_index == -1)
        {
            current_time++;
        }
        else
        {
            if (bt_remaining[max_index] == ps[max_index].bt)
            {
                ps[max_index].start_time = current_time;
            }

            bt_remaining[max_index]--;
            current_time++;

            if (bt_remaining[max_index] == 0)
            {
                ps[max_index].ct = current_time;
                ps[max_index].tat = ps[max_index].ct - ps[max_index].at;
                ps[max_index].wt = ps[max_index].tat - ps[max_index].bt;
                ps[max_index].rt = ps[max_index].start_time - ps[max_index].at;

                sum_tat += ps[max_index].tat;
                sum_wt += ps[max_index].wt;
                sum_rt += ps[max_index].rt;

                completed++;
                is_completed[max_index] = true;

                printf("Process completed at time = %d\n", ps[max_index].ct);
            }
        }
    }

    // Print Completion Times
    printf("\nCompletion Times: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ps[i].ct);
    }

    printf("\nAverage Turnaround Time = %.2f", sum_tat / n);
    printf("\nAverage Waiting Time    = %.2f", sum_wt / n);
    printf("\nAverage Response Time   = %.2f", sum_rt / n);

    return 0;
}
