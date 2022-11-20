#include <stdio.h>
#include <stdlib.h>

int main()
{
    int RQ[100];
    int total_head_movement;
    int i , j;

    int n;
    printf("Enter the nuinber ot Requests \n");
    scanf("%d", &n);

    printf("Enter the Requests sequence \n");
    for ( i = 0; i < n; i++)
    {
        scanf("%d", &RQ[i]);
    }

    int initial;
    printf("Enter initial head position\n");
    scanf("%d", &initial);

    int size;
    printf("Enter total disk size \n");
    scanf("%d", &size);

    int move;
    printf("Enter the head movement direction for high 1 and for low O \n");
    scanf("%d", &move);

    for(i = 0 ; i < n ; i++)
    {
        for (j = 0; j < n- i - 1 ; j++)
        {
            if(RQ[j] > RQ[j+1])
            {
                int temp = RQ[j];
                RQ[j] = RQ[j+1];
                RQ[j+1] = temp;
            }
        }
    }

    int index;
    for(i = 0 ; i < n ; i++)
    {
        if(initial < RQ[i])
        {
            index = i;
            break;
        }
    }

    if(move == 1)
    {
        for(i = index ; i < n ; i++)
        {
            total_head_movement = total_head_movement + abs(RQ[i] - initial);
            initial = RQ[i];
        }

        total_head_movement = total_head_movement + abs(size - RQ[i-1] - 1);
        total_head_movement = abs(size-1);
        initial = 0;

        for(i = 0 ; i < index ; i++)
        {
            total_head_movement = total_head_movement + abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }

    else
    {
        for(i = index-1; i >= 0 ; i--)
        {
            total_head_movement = total_head_movement + abs(RQ[i] - initial);
            initial = RQ[i];
        }
        total_head_movement = total_head_movement + abs(RQ[i+1] - 0);
        total_head_movement = total_head_movement + abs(size - 1);
        initial = size - 1;

        for(i = n-1 ; i >= index ; i--)
        {
            total_head_movement = total_head_movement + abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }

    printf("Total head movement is : %d" , total_head_movement);
    return 0;

}

