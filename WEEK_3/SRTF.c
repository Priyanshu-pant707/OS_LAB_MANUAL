#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

struct process_struct
{
    int pid;
    int at;
    int bt;
    int ct, wt, tat, rt, start_time;
} ps[100];

int findmax(int a, int b) { return a > b ? a : b; }
int findmin(int a, int b) { return a < b ? a : b; }

int main()
{
    int n;
    int bt_remaining[100];
    bool is_completed[100] = {false}, is_first_process = true;
    int current_time = 0, completed = 0, prev = 0;
    float sum_tat = 0, sum_wt = 0, sum_rt = 0, total_idle_time = 0, length_cycle;
    float cpu_utilization;
    int max_completion_time, min_arrival_time;

    printf("Enter total number of processes: ");
    scanf("%d", &n);

    // 🔹 Input AT + BT ek hi sath
    for (int i = 0; i < n; i++)
    {
        ps[i].pid = i + 1;
        printf("\nEnter AT and BT for Process %d: ", i + 1);
        scanf("%d %d", &ps[i].at, &ps[i].bt);
        bt_remaining[i] = ps[i].bt;
    }

    while (completed != n)
    {
        int min_index = -1;
        int minimum = INT_MAX;

        // 🔹 Find process with minimum remaining burst time
        for (int i = 0; i < n; i++)
        {
            if (ps[i].at <= current_time && is_completed[i] == false)
            {
                if (bt_remaining[i] < minimum)
                {
                    minimum = bt_remaining[i];
                    min_index = i;
                }
                if (bt_remaining[i] == minimum)
                {
                    if (ps[i].at < ps[min_index].at)
                    {
                        minimum = bt_remaining[i];
                        min_index = i;
                    }
                }
            }
        }

        if (min_index == -1)
        {
            current_time++;
        }
        else
        {
            if (bt_remaining[min_index] == ps[min_index].bt)
            {
                ps[min_index].start_time = current_time;
                total_idle_time += (is_first_process == true) ? 0 : (ps[min_index].start_time - prev);
                is_first_process = false;
            }

            bt_remaining[min_index] -= 1;
            current_time++;
            prev = current_time;

            if (bt_remaining[min_index] == 0)
            {
                ps[min_index].ct = current_time;
                ps[min_index].tat = ps[min_index].ct - ps[min_index].at;
                ps[min_index].wt = ps[min_index].tat - ps[min_index].bt;
                ps[min_index].rt = ps[min_index].start_time - ps[min_index].at;

                sum_tat += ps[min_index].tat;
                sum_wt += ps[min_index].wt;
                sum_rt += ps[min_index].rt;

                completed++;
                is_completed[min_index] = true;
            }
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

    // 🔹 Output
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               ps[i].pid, ps[i].at, ps[i].bt,
               ps[i].ct, ps[i].tat, ps[i].wt, ps[i].rt);
    }

    cpu_utilization = (float)(length_cycle - total_idle_time) / length_cycle;

    printf("\nAverage Turn Around Time = %.2f", (float)sum_tat / n);
    printf("\nAverage Waiting Time     = %.2f", (float)sum_wt / n);
    printf("\nAverage Response Time    = %.2f", (float)sum_rt / n);
    printf("\nThroughput               = %.2f", n / (float)length_cycle);
    printf("\nCPU Utilization (%%)      = %.2f\n", cpu_utilization * 100);

    return 0;
}
