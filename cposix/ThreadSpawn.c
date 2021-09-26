
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS     1000


/**
    References
    compile error
    https://stackoverflow.com/questions/1662909/undefined-reference-to-pthread-create-in-linux

    Code to create Threads
    https://www.cs.cmu.edu/afs/cs/academic/class/15492-f07/www/pthreads.html
     https://stackoverflow.com/questions/1662909/undefined-reference-to-pthread-create-in-linux
**/


// print out the id of the thread
void *PrintId(void *threadid)
{
   long tid;
   tid = (long)threadid;
   printf("Hello World! It's me, thread #%ld!\n", tid);
   pthread_exit(NULL);
}
     
int main (int argc, char *argv[])
{

     double time1 = (double) clock();     /* get initial time */
     time1 = time1 / CLOCKS_PER_SEC;      /*in seconds*/
   int rc;
   long t;
   pthread_t threads[NUM_THREADS];
   // create the number of required threads
   for(long i=0; i<NUM_THREADS; i++){
      printf("In main: creating thread %ld\n", i);
      pthread_t thread;
      rc = pthread_create(&threads[i], NULL, PrintId, (void *)i);
      if (rc){
         printf("ERROR; return code from pthread_create() is %d\n", rc);
         exit(-1);
      }
      
   }
     /* call clock a second time */
    double timedifL = ( ((double) clock()) / CLOCKS_PER_SEC) - time1;
    printf("[loose] The elapsed time is %f seconds\n", timedifL);

    double timeperL = timedifL / NUM_THREADS; // time taken per process
    printf("[loose] Time taken per process: %f in seconds\n", timeperL);

     // wait for all threads to return
   for(int i=0; i<NUM_THREADS;i++){
        pthread_join( threads[i], NULL);
   }

   /* call clock a second time */
    double timedifJ = ( ((double) clock()) / CLOCKS_PER_SEC) - time1;
    printf("[joined] The elapsed time is %f seconds\n", timedifJ);

    double timeperJ = timedifJ / NUM_THREADS; // time taken per process
    printf("[joined] Time taken per process: %f in seconds\n", timeperJ);

   pthread_exit(NULL);
}
