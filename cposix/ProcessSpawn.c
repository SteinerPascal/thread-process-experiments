#include <stdio.h>
#include <sys/types.h>
#include <time.h>
#include <stdlib.h>

/**
    References
    measure time
    https://www.ibm.com/docs/en/zos/2.2.0?topic=functions-clock-determine-processor-time

    creating forks
    https://stackoverflow.com/questions/55873277/creating-n-child-process-in-c-using-fork
**/

int main()
{

    double time1 = (double)clock(); /* get initial time */
    time1 = time1 / CLOCKS_PER_SEC; /*in seconds*/

    int cnt = 0; // counter variable
    int loops = 100;

    for (int i = 0; i < loops; i++)
    {

        printf("processNr: %d   ", cnt);
        // fork new process
        pid_t c = fork();

        if (c == 0)
        { // message from child
            printf("[child] pid %d from [parent] pid %d\n", getpid(), getppid());
            // child exits
            exit(0);
        }
        else
        {
            wait(NULL);
            // message from parent
            printf("[parent] child has terminated\n");
        }
        cnt++; // increment counter
    }

    /* call clock a second time */
    double timedif = (((double)clock()) / CLOCKS_PER_SEC) - time1;
    printf("The elapsed time is %f seconds\n", timedif);

    double timeper = timedif / loops; // time taken per process
    printf("Time taken per process: %f in seconds\n", timeper);

    return 0;
}
