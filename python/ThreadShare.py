# References 
# https://www.geeksforgeeks.org/time-perf_counter-function-in-python/
# https://docs.python.org/3/library/threading.html
# https://realpython.com/intro-to-python-threading/
import threading
# Python program to show time by perf_counter()


myvar = 1 # var under observation

def thread_function(name):
    print("[child] Thread %s: starting", name)
    global myvar
    myvar = myvar + 1
    print(f'[child] value of myvar: {myvar}')

if __name__ == "__main__":
    
    x = threading.Thread(target=thread_function, args=(1,))
    x.start()

    x.join()
    print(f'[parent] value of myvar: {myvar}') # output 2 
