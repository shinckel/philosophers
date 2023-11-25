# Philosophers

# Minishell
This project was developed for 42 school. For comprehensive information regarding the requirements, please consult the PDF file in the subject folder of the repository. Furthermore, I have provided my notes and a concise summary below.
``` diff
+ keywords: basic unit of execution / thread
+ how to organize the eating action of the philosophers
+ race conditions
+ lightweight process
```

## High-level Overview

Resources and data can be shared between threads. Each thread has its own stack and context switching is fast. A fork() induces a parent-child relationship between two processes. Thread creation induces a peer relationship between all the threads of a process.

1. check valid arguments: philosophers number? time to die? time to eat? time to sleep? number os times each philosopher must eat?
2. init program, assign user's input to data struct;
3. create threads;
4. clean and destroy all;

```c
int	main(int argc, char **argv)
{
	pthread_t   t1;
	pthread_t   t2;
	int	value0 = 1;
	int	value1 = 2;

    // NULL default attributes, otherwise insert value
    // if threads return value != 0 an error occured
    if (pthread_create(&t1, NULL, routine, (void *)&value0))
        return (ERROR);
    if (pthread_create(&t2, NULL, routine2, (void *)&value1))
        return (ERROR);

    // wait for thread to terminate
    if (pthread_join(t1, NULL))
        return (ERROR);
    if (pthread_join(t2, NULL))
        return (ERROR);
	return (0);
}

// establish the routine
// function for thread to execute
// sleep() shows that both are executing at the same time

// global var
// threads change data in both will have output 2
int x = 1;

void    *routine(void *add)
{ 
    int nbr;

    nbr = *(int *)add;
    printf("Hello from thread %i\n", nbr);
    sleep(3);
    printf("Bye from thread %i\n", nbr);
    printf("x = %i\n", x);
    return (NULL);
}

void    *routine2(void *add)
{ 
    int nbr;

    nbr = *(int *)add;
    x++;
    printf("Hello from thread %i\n", nbr);
    sleep(3);
    printf("Bye from thread %i\n", nbr);
    printf("x = %i\n", x);
    return (NULL);
}
```
```c
// processes can contain multiple threads
// address space: fork duplicates all data
// all threads can access all variables(common address space)
int main(int argc, char **argv)
{
    int x = 2;
    int pid = fork();
    if (pid == -1)
        return (ERROR);
    if (pid == 0)
        x++;
    sleep(2);
    // x will change only in the child process
    printf("Hello from processes. Process id: %d %d\n", getpid(), x);
    if (pid)
        wait(NULL);
    return(0);
}
```
### Race conditions

```c
int mails = 0;

void    *routine()
{ 
	for (int i = 0; i < 100000; i++)
    	mails++;
    return (NULL);
}

int	main(int argc, char **argv)
{
	pthread_t   t1;
	pthread_t   t2;
    pthread_create(&t1, NULL, routine, (void *)&value0);
    pthread_create(&t2, NULL, routine, (void *)&value1);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

	printf("Total mails: %d\n", mails);
	return (0);
} // Total mails: 100947

/*SOLUTION*/
int mails = 0;
pthread_mutex_t mutex;

void    *routine()
{ 
	for (int i = 0; i < 100000; i++)
	{
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);
	}
    return (NULL);
}

int	main(int argc, char **argv)
{
	pthread_t   t1;
	pthread_t   t2;
    // initialize mutex
	pthread_mutex_init(&mutex, NULL);
    pthread_create(&t1, NULL, routine, (void *)&value0);
    pthread_create(&t2, NULL, routine, (void *)&value1);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    // free memory
	pthread_mutex_destroy(&mutex);

	printf("Total mails: %d\n", mails);
	return (0);
} // Total mails: 200000
```

### References:
[Philosophers 42 Guide— “The Dining Philosophers Problem”](https://medium.com/@ruinadd/philosophers-42-guide-the-dining-philosophers-problem-893a24bc0fe2)<br />
[Short introduction to threads (pthreads)](https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2)<br />
[How to create threads in a loop (pthread_create)](https://www.youtube.com/watch?v=xoXzp4B8aQk&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&index=5)

## Concepts

| Task | Prototype | Description |
|:----|:-----:|:--------:|
| **Threads** | | Thread is a basic unit of execution (CPU utilization). Multiple threads - perform multiple tasks at a time: e.g. download a file from a web page. One thread is displaying the page, other thread is downloading the file. |
| **Process** | | Program under execution - process. a program may have a number of processes associated with it... each process can have a number of threads executing in its thread ID, program counter, register set, stack. Threads share resources with other threads belonging to the same process (e.g. open files, signals, code, data). However, registers and stack are not shared. |
| **Parallel execution** | | Program continue running even if you has one task not completed, resource sharing (code, data, files), economy of memory (context switch threads), multi-CPU machine, ultilization of multiprocessor architectures. |
| **Concurrent execution** | | |
| **Mutexes** |  | Lock a block of code (it can only be executed by the lock owner until it unlocks the lock). Therefore, thread 2 will have to wait until thread 1 is done. `ONLY MULTI-CORE PROCESSORS` |
| **Race conditions** |  | Two or more threads concurrently accessing a location of memory. The faster process will execute the task (the other one not). With big numbers we are going to have issues! To solve this issue, you must use `mutexes`. |
| **Check arguments** | | 4 arguments - n philosophers, time will die, time to eat, time to sleep, number of times for eating before program stops(optional) |
| **Compile into assembly**| `gcc -S main.c` | Output `main.s`. Interesting to check how many actions were done behind the scene. |
| **threas in a loop**| `for loop {pthread_create(), pthread_join()}` | Threads wouldn't run in parallel. To solve this problem: two loops, one for create and one for join instructions. |
| **pthread_join()** | `int pthread_join(pthread_t thread, void **retval)` | Execution pauses until thread is done. Second argument is a reference to a pointer `(void **)` (then you can typecasted to wherever data type needed). In the example `pthread_join(thread1, NULL)`, NULL is the returned value of the routine created in `pthread_create(&thread1, NULL, computation, (void *)&value1);` |
| **pass arguments** | | Pass unique arguments to threads, default value is `NULL`. |
| **time** | `time ./a.out` | Time to run the executable. |






