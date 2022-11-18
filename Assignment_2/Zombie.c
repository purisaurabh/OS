#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void bubble_sort(int arr[] , int n)
{
    for(int i = 0; i < n-1 ; i++)
    {
        for(int j = 0; j < n-i-1 ; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }


    printf("Sorted array will be in child process is : ");
    for(int i = 0 ; i < n; i++)
    {
        printf("%d " , arr[i]);
    }

    printf("\n");
}

void selection_sort(int arr[] ,int n)
{
    for(int i = 0 ; i <n-1 ; i++)
    {
        int min_index = i;
        for(int j = i+1 ; j < n ; j++)
        {
            if(arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }

        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }



    printf("Sorted array will be in child process is : ");
    for(int i = 0 ; i < n; i++)
    {
        printf("%d " , arr[i]);
    }

    printf("\n");
}

int main()
{
    pid_t pid;

    int n;
    printf("Enter the number of elements = ");
    scanf("%d" , &n);

    int arr[n];
    printf("Enter the array element : ");
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d" , &arr[i]);
    }

    pid = fork();
    if(pid == 0)
    {
        printf("--------------------Child Process--------------------\n");
        printf("It is the child process with pid = %d and ppid = %d  \n" ,getpid() , getppid());
        bubble_sort(arr , n);
        printf("---------------------Child Process Terminated-----------------\n");
        printf("\n");
    }

    else
    {
        wait(NULL);
        printf("--------------------Parent Process--------------------\n");
        printf("It is the parent process with pid = %d and ppid = %d \n" ,getpid() , getppid());
        bubble_sort(arr , n);
        printf("---------------------Parent Process Terminated-----------------\n");
    }

}