#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>

int main()
{
    char buff[100];

    // create shared memory segment with key 2345 having size 1024 bytes. IPC_CREATE is used to create shared segment if it does not exits 0666 are the permissions on the shared segment
    int shmid;
    shmid = shmget((key_t)2345 , 1024 , 0666 | IPC_CREAT);
    printf("Key of the shared memory is : %d" , shmid);

    void *shared_memory;
    shared_memory= shmat(shmid , NULL , 0);

    // process attached to the shared memory segment 
    printf("Process attached at %p \n" , shared_memory);

    printf("Enter some data to write to shared memory \n");
    read( 0 , buff , 100); // get some input from user

    strcpy(shared_memory , buff); // data written to shared memory
    printf("You wrote : %s \n" , (char *) shared_memory);
}