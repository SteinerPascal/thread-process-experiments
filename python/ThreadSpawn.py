# References 
# https://www.geeksforgeeks.org/time-perf_counter-function-in-python/
# https://docs.python.org/3/library/threading.html
# https://realpython.com/intro-to-python-threading/

import threading
# Python program to show time by perf_counter()
from time import perf_counter

def thread_function(name):
    print("[child] Thread %s: starting", name)

if __name__ == "__main__":
    threads = []
    nr = 1000
     # Start the stopwatch / counter
    t1_start = perf_counter()
    for i in range(nr):
        x = threading.Thread(target=thread_function, args=(i,))
        x.start()
        threads.append(x)

    for i in range(len(threads)):
        x = threads[i]
        x.join()

    # Stop the stopwatch / counter
    t1_stop = perf_counter()
 
    print("Elapsed time:", t1_stop, t1_start)
 
    print("Elapsed time during the whole program in seconds:",
                                        t1_stop-t1_start)
    elapsed = t1_stop-t1_start
    print("time per process: ", elapsed / nr )
    print("finish")