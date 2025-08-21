#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

struct process_struct
{
    int pid;
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

    printf("Enter total number of processes: ");
    scanf("%d", &n);

    // 🔹 Input in single loop
    for (int i = 0; i < n; i++)
    {
        ps[i].pid = i + 1;
        printf("\nEnter AT, BT and Priority for Process %d: ", i + 1);
        scanf("%d %d %d", &ps[i].at, &ps[i].bt, &ps[i].priority);
        bt_remaining[i] = ps[i].bt;
    }

    printf("\n--- Execution Log ---\n");

    while (completed != n)
    {
        int max_index = -1;
        int maximum = INT_MIN;

        // 🔹 Find process with highest priority
        for (int i = 0; i < n; i++)
        {
            if (ps[i].at <= current_time && is_completed[i] == false)
            {
                if (ps[i].priority > maximum)
                {
                    maximum = ps[i].priority;
                    max_index = i;
                }
                else if (ps[i].priority == maximum)
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

                printf("P%d finished at time %d\n", ps[max_index].pid, ps[max_index].ct);
            }
        }
    }

    // 🔹 Final Table
    printf("\nPID\tAT\tBT\tPR\tST\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               ps[i].pid, ps[i].at, ps[i].bt, ps[i].priority,
               ps[i].start_time, ps[i].ct, ps[i].tat, ps[i].wt, ps[i].rt);
    }

    // 🔹 Final Averages
    printf("\nAverage Turnaround Time = %.2f", sum_tat / n);
    printf("\nAverage Waiting Time    = %.2f", sum_wt / n);
    printf("\nAverage Response Time   = %.2f\n", sum_rt / n);

    return 0;
}
