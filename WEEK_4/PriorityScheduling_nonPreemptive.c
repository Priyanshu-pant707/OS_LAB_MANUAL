#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

struct process_struct
{
    int pid;
    int at;      // Arrival Time
    int bt;      // Burst Time
    int priority;
    int ct, wt, tat, rt, start_time;
} ps[100];

int findmax(int a, int b) { return a > b ? a : b; }
int findmin(int a, int b) { return a < b ? a : b; }

int main()
{
    int n;
    bool is_completed[100] = {false}, is_first_process = true;
    int current_time = 0, completed = 0, total_idle_time = 0, prev = 0, length_cycle;
    float cpu_utilization;
    int max_completion_time, min_arrival_time;
    float sum_tat = 0, sum_wt = 0, sum_rt = 0;

    printf("Enter total number of processes: ");
    scanf("%d", &n);

    // 🔹 Input ek hi loop me
    for (int i = 0; i < n; i++)
    {
        ps[i].pid = i + 1;
        printf("\nEnter AT, BT and Priority for Process %d: ", i + 1);
        scanf("%d %d %d", &ps[i].at, &ps[i].bt, &ps[i].priority);
    }

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
            ps[max_index].start_time = current_time;
            ps[max_index].ct = ps[max_index].start_time + ps[max_index].bt;
            ps[max_index].tat = ps[max_index].ct - ps[max_index].at;
            ps[max_index].wt = ps[max_index].tat - ps[max_index].bt;
            ps[max_index].rt = ps[max_index].start_time - ps[max_index].at;

            total_idle_time += (is_first_process == true) ? 0 : (ps[max_index].start_time - prev);

            sum_tat += ps[max_index].tat;
            sum_wt += ps[max_index].wt;
            sum_rt += ps[max_index].rt;

            completed++;
            is_completed[max_index] = true;
            current_time = ps[max_index].ct;
            prev = current_time;
            is_first_process = false;
        }
    }

    // 🔹 Calculate Length of Process completion cycle
    max_completion_time = INT_MIN;
    min_arrival_time = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        max_completion_time = findmax(max_completion_time, ps[i].ct);
        min_arrival_time = findmin(min_arrival_time, ps[i].at);
    }

    length_cycle = max_completion_time - min_arrival_time;
    cpu_utilization = (float)(length_cycle - total_idle_time) / length_cycle;

    // 🔹 Final Output Table
    printf("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               ps[i].pid, ps[i].at, ps[i].bt, ps[i].priority,
               ps[i].ct, ps[i].tat, ps[i].wt, ps[i].rt);
    }

    printf("\nAverage Turn Around Time = %.2f", sum_tat / n);
    printf("\nAverage Waiting Time     = %.2f", sum_wt / n);
    printf("\nAverage Response Time    = %.2f", sum_rt / n);
    printf("\nThroughput               = %.2f", n / (float)length_cycle);
    printf("\nCPU Utilization (%%)      = %.2f\n", cpu_utilization * 100);

    return 0;
}
