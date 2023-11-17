# Philosophers
[42 SCHOOL - LEVEL 3] Learn the basics of threading a process.

// Philosophers with threads and mutexes
// how to organize the eating action of the philosophers

// race conditions 
// two or more threads concurrently accessing a location of memory
// the faster process will execute the task (the other one not)

// mutex
// lock a block of code
// it can only be executed by the lock owner until he onlocks the lock
// thread 2 will have to wait until thread 1 is done

/* check arguments
4 arguments - n philosophers, time will die, time to eat, time to sleep,
number of times for eating before program stops*/

// thread is a basic unit of execution (CPU utilization)
// program under execution - process
a program may have a number of processes associated with it... each process can have a number of threads executing in it
thread ID, program counter, register set, stack
it share resources with other threads belonging to the same process (e.g. open files, signals, code, data)
registers and stack are not shared
Multiple threads - perform multiple tasks at a time
e.g.: download a file from a web page. One thread is displaying the page, other
thread is downloading the file

program continue running even if you has one task not completed
resource sharing (code, data, files)
economy of memory (context switch threads)
multi-CPU machine, ultilization of multiprocessor architectures

parallel execution
concurrent but not parallel execution (depends on the architecture... performance)

pthread_join execution pauses until thread is done

I can set attributes to the thread

void pointer - I could pass a value via struct, as an arg







