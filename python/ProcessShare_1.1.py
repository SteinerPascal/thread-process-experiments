# References 
# https://www.geeksforgeeks.org/time-perf_counter-function-in-python/
# https://docs.python.org/3/library/multiprocessing.html
# https://zetcode.com/python/multiprocessing/
import multiprocessing

# This example doesn't even work since global myvar isn't accessible in def worker

def worker(name: str) -> None:
    print(f'[child] Nr: {name} started')
    global myvar
    myvar = myvar + 1
    print(f'[child] Nr: value of myvar: {myvar}')

if __name__ == '__main__':

    myvar = 1
    process = multiprocessing.Process(target=worker, 
                                        args=(f'computer_{1}',))
    process.start()  

    process.join()

    print(f'[parent] Nr: value of myvar: {myvar}')