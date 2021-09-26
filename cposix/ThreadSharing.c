#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/**
    References
    compile error
    https://stackoverflow.com/questions/1662909/undefined-reference-to-pthread-create-in-linux

    Code to create Threads
    https://www.cs.cmu.edu/afs/cs/academic/class/15492-f07/www/pthreads.html
     https://stackoverflow.com/questions/1662909/undefined-reference-to-pthread-create-in-linux
**/

int myvar = 1; // var under observation

void *PrintIdChangeVar()
{   
    myvar++;
    printf("[child] value of myvar %d \n", myvar);
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
      
    int rc;
    pthread_t thread;  // create thread
    rc = pthread_create(&thread, NULL, PrintIdChangeVar, NULL);
    if (rc)
    {
        printf("ERROR; return code from pthread_create() is %d\n", rc);
        exit(-1);
    }

    pthread_join(thread, NULL);

    printf("[parent] value of myvar %d \n",myvar);

    return 0;
}