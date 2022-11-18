#include <stdio.h>
int arrival_time[100];
int burst_time[100];
int completion_time[100];
int temp[100];

int main()
{
    int n;
    printf("Enter the number of process : ");
    scanf("%d" , &n);

    printf("\nEnter the details of precess : \n" , n);
    for(int i = 0 ; i < n ; i++)
    {
        printf("Enter the arrival time for process %d : " , i+1);
        scanf("%d" , &arrival_time[i]);

        printf("Enter the burst time for process %d : " , i+1);
        scanf("%d" , &burst_time[i]);

        temp[i] = burst_time[i];
    }

    burst_time[99] = 1000;

    int count = 0;
    double average_waiting_time = 0;
    double average_turn_around_time = 0;


    for(int i = 0 ; count != n ; i++)
    {
        int small = 99;
        for(int j = 0; j < n ; j++)
        {
            if(arrival_time[j] <= i && burst_time[j] < burst_time[small] && burst_time[j] > 0)
            {
                small = j;
            }
        }

        burst_time[small]--;

        if(burst_time[small] == 0)
        {
            count++;
            completion_time[small] = i+1;
        }
    }


    for(int i = 0 ; i < n ; i++)
    {
        int total = completion_time[i] - arrival_time[i];
        average_turn_around_time += total;
        average_waiting_time += (total - temp[i]);
    }


    printf("\n Average turn around time is : %lf\n " , average_turn_around_time);
    printf("\n Average waiting time %lf" , average_waiting_time);
}