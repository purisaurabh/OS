#include <stdio.h>
#include <stdlib.h>

int main()
{
    int total_head_movement = 0;

    int n;
    printf("\nEnter the number of request : ");
    scanf("%d" , &n);

    int RQ[100];
    printf("\nEnter the request sequence :");
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d" , &RQ[i]);
    }

    int initial;
    printf("\nEnter the initial head position :");
    scanf("%d" , &initial);


    int count = 0;

    while(count != n)
    {
        int min = 1000;
        int d;
        int index;
        for(int i = 0 ; i < n ; i++)
        {
            d = abs(RQ[i] - initial);
            if(min > d)
            {
                min = d;
                index = i;
            }
        }

        total_head_movement = total_head_movement + min;
        initial = RQ[index];
        RQ[index] = 1000;
        count++;
    }


    printf("Total head movement is : %d " , total_head_movement);
    return 0;
}