#include <stdio.h>

int main()
{
    int n, i, j, temp;
    int bt[20], wt[20], tat[20], p[20];
    int twt = 0, ttat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter burst time of process %d: ", i + 1);
        scanf("%d", &bt[i]);
        p[i] = i + 1;
    }

    /* Sort processes by burst time (SJF) */
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (bt[i] > bt[j])
            {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    /* Calculate waiting time and turnaround time */
    for (i = 0; i < n; i++)
    {
        if (i == 0)
            wt[i] = 0;
        else
            wt[i] = wt[i - 1] + bt[i - 1];

        tat[i] = wt[i] + bt[i];

        twt += wt[i];
        ttat += tat[i];
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", (float)twt / n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)ttat / n);

    return 0;
}
