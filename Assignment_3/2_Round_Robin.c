#include <stdio.h>

int main()
{
    int arrival_time[10];
    int burst_time[10];
    int temp[10];
    int wt = 0;
    int tat = 0;
    float avg_wt, avg_tat;
    int sum = 0;
    int count = 0;

    
    int NOP;
    printf(" Total number of process in the system = ");
    scanf("%d", &NOP);

    int quant;
    printf("Enter the Time Quantum for the process = ");
    scanf("%d", &quant);

    for (int i = 0; i < NOP; i++)
    {
        printf("\nEnter the Arrival and Burst time of the Process[%d] \n", i + 1);

        printf("Arrival time is = ");
        scanf("%d", &arrival_time[i]);

        printf("Burst time is = ");
        scanf("%d", &burst_time[i]);

        temp[i] = burst_time[i];
    }

    int y = NOP;

    printf("\n Process No \t\t Burst Time \t TAT \t\t Waiting Time ");
    int i;
    for (sum = 0, i = 0; y != 0;)
    {
        if (temp[i] <= quant && temp[i] > 0)
        {
            sum = sum + temp[i];
            temp[i] = 0;
            count = 1;
        }

        else if (temp[i] > 0)
        {
            temp[i] = temp[i] - quant;
            sum = sum + quant;
        }

        if (temp[i] == 0 && count == 1)
        {
            y--; // decrement the process no.
            printf("\nProcess No[%d] \t\t %d\t\t %d\t\t %d", i + 1 , burst_time[i] , sum - arrival_time[i] , sum - arrival_time[i] - burst_time[i]);
            wt = wt + sum - arrival_time[i] - burst_time[i];
            tat = tat + sum - arrival_time[i];
            count = 0;
        }

        if (i == NOP-1)
            i = 0;

        else if(arrival_time[i + 1] <= sum)
            i++;

        else
            i = 0;
    }

    avg_wt = wt * 1.0 / NOP;
    avg_tat = tat * 1.0 / NOP;

    printf("\n\nAverage Turn Around Time = %f", avg_wt);
    printf("\nAverage Waiting Time = %f", avg_tat);
}