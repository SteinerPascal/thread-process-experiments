# References 
# https://www.geeksforgeeks.org/time-perf_counter-function-in-python/
# https://docs.python.org/3/library/multiprocessing.html
# https://zetcode.com/python/multiprocessing/
import multiprocessing
# Python program to show time by perf_counter()
from time import perf_counter



def worker(name: str) -> None:
    print(f'[child] Nr: {name} started')

if __name__ == '__main__':
    processes = []
    # Start the stopwatch / counter
    t1_start = perf_counter()
    nrproc = 100
    for i in range(nrproc):
        process = multiprocessing.Process(target=worker, 
                                          args=(f'computer_{i}',))
        processes.append(process)
        process.start()  

    for proc in processes:
        proc.join()
    
    # Stop the stopwatch / counter
    t1_stop = perf_counter()
 
    print("Elapsed time:", t1_stop, t1_start)
 
    print("Elapsed time during the whole program in seconds:",
                                        t1_stop-t1_start)
    elapsed = t1_stop-t1_start
    print("time per process: ", elapsed / nrproc )