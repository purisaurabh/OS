#include <stdio.h>
#include<stdbool.h>


int in[100];
int p[50];
int hit = 0;
int page_fault_count = 0;
int no_of_frames;
int n;

void get_data()
{
    printf("\nEnter length of page reference sequence:");
    scanf("%d", &n);

    printf("\nEnter the page reference sequence:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &in[i]);
    }

    printf("\nEnter no of frames:");
    scanf("%d", &no_of_frames);
}


void initialize()
{
    page_fault_count = 0;
    for (int i = 0; i < no_of_frames; i++)
    {
        p[i] = 9999;
    }
}


bool is_hit(int data)
{
    for (int j = 0; j < no_of_frames; j++)
    {
        if (p[j] == data)
        {
            return true;
        }
    }
    return false;
}


int get_hit_index(int data)
{
    int hit_index;
    for (int k = 0; k < no_of_frames; k++)
    {
        if (p[k] == data)
        {
            hit_index = k;
            break;
        }
    }
    return hit_index;
}


void disp_page()
{
    for (int k = 0; k < no_of_frames; k++)
    {
        if (p[k] != 9999)
        {
            printf(" %d", p[k]);
        }
    }
}

void disp_page_fault()
{
    printf("\nTotal no of page faults:%d", page_fault_count);
}

void fifo()
{
    initialize();
    for (int i = 0; i < n; i++)
    {
        printf("\nFor %d :", in[i]);
        if (is_hit(in[i]) == 0)
        {
            int k;
            for (k = 0; k < no_of_frames - 1; k++)
                p[k] = p[k + 1];

            p[k] = in[i];
            page_fault_count++;
            disp_page();
        }

        else
        {
            printf("No page fault");
        }
    }
    disp_page_fault();
}


void optimal()
{
    initialize();
    int near[50];
    for (int i = 0; i < n; i++)
    {
        printf("\nFor %d :", in[i]);
        if (is_hit(in[i]) == 0)
        {
            for (int j = 0; j < no_of_frames; j++)
            {
                int pg = p[j];
                int found = 0;
                for (int k = i; k < n; k++)
                {
                    if (pg == in[k])
                    {
                        near[j] = k;
                        found = 1;
                        break;
                    }
                    else
                    {
                        found = 0;
                    }
                }

                if (!found)
                {
                    near[j] = 9999;
                }
            }
            int max = -9999;
            int rep_index;

            for (int j = 0; j < no_of_frames; j++)
            {
                if (near[j] > max)
                {
                    max = near[j];
                    rep_index = j;
                }
            }
            p[rep_index] = in[i];
            page_fault_count++;
            disp_page();
        }
        else
        {
            printf("No page fault");
        }
    }
    disp_page_fault();
}

void lru()
{
    initialize();
    int least[50];

    for (int i = 0; i < n; i++)
    {
        printf("\nFor %d :", in[i]);
        if (is_hit(in[i]) == 0)
        {
            for (int j = 0; j < no_of_frames; j++)
            {
                int pg = p[j];
                int found = 0;
                for (int k = i - 1; k >= 0; k--)
                {
                    if (pg == in[k])
                    {
                        least[j] = k;
                        found = 1;
                        break;
                    }
                    else
                    {
                        found = 0;
                    }
                }
                if (!found)
                {
                    least[j] = -9999;
                }
            }

            int min = 9999;
            int rep_index;
            for (int j = 0; j < no_of_frames; j++)
            {
                if (least[j] < min)
                {
                    min = least[j];
                    rep_index = j;
                }
            }
            p[rep_index] = in[i];
            page_fault_count++;
            disp_page();
        }
        
        else
        {
            printf("No page fault!");
        }
    }
    disp_page_fault();
}


int main()
{
    int choice;
    while(1)
    {
        printf("\n Page Replacement Algorithms\n 1.Enter data\n 2.FIFO \n 3.Optimal\n 4.LRU\n Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                get_data();
                break;

            case 2:
                fifo();
                break;

            case 3:
                optimal();
                break;

            case 4:
                lru();
                break;

            default:
                return 0;
                break;
        }
    }
}