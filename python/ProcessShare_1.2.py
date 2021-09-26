# References 
# https://www.geeksforgeeks.org/time-perf_counter-function-in-python/
# https://docs.python.org/3/library/multiprocessing.html
# https://zetcode.com/python/multiprocessing/
import multiprocessing

# This example shows that if I share a variable with the process it runs in its own memory space

def worker(myvar) -> None:
    print(f'[child] started')
    myvar = myvar + 1
    print(f'[child] Nr: value of myvar: {myvar}') # output 2
    

if __name__ == '__main__':

    myvar = 1
    process = multiprocessing.Process(target=worker, 
                                        args=(myvar,))
    process.start()  

    process.join()

    print(f'[parent] Nr: value of myvar: {myvar}') # output 1
    