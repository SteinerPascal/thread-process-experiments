#include<stdio.h> 
#include <sys/types.h>
#include <stdlib.h>

/**
    References
    measure time
    https://www.ibm.com/docs/en/zos/2.2.0?topic=functions-clock-determine-processor-time

    creating forks
    https://stackoverflow.com/questions/55873277/creating-n-child-process-in-c-using-fork

    sharing variable
    https://stackoverflow.com/questions/4298678/after-forking-are-global-variables-shared
**/

int main()
{
    // fork new process
    pid_t c=fork();
    int myvar = 0;
    if (c== 0)
    {   // message from child
        printf("[child] pid %d from [parent] pid %d\n",getpid(),getppid()); 
        myvar++;
        printf("[child] myvar value: %d \n",myvar);
        // child exits
        exit(0); 
    }
    else
    {
        wait(NULL); // wait till child has "changed" variable
        printf("[parent] myvar value: %d \n",myvar);
        // message from parent
        printf("[parent] child has terminated\n");
    }
}