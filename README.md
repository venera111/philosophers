# philosophers

### Introduction
This project is about learning the basics of threading a process, learning how to make threads and discover the mutex.

### Overview
Here are the things you need to know if you want to succeed this assignment:
- One or more philosophers sit at a round table.
There is a large bowl of spaghetti in the middle of the table.
- The philosophers alternatively eat, think, or sleep.
While they are eating, they are not thinking nor sleeping;
while thinking, they are not eating nor sleeping; and, of course, while sleeping, they are not eating nor thinking.
- There are also forks on the table. There are as many forks as philosophers.
- Because serving and eating spaghetti with only one fork is very inconvenient, a philosopher takes their right and their left forks to eat, one in each hand.
- When a philosopher has finished eating, they put their forks back on the table and start sleeping. Once awake, they start thinking again. The simulation stops when a philosopher dies of starvation.
- Every philosopher needs to eat and should never starve.
- Philosophers don’t speak with each other.
- Philosophers don’t know if another philosopher is about to die.
- No need to say that philosophers should avoid dying!

### Usage
```
git clone https://github.com/venera111/philosophers.git
make
cd philosophers/philo
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

### External functions
name  | prototype | description |
---|------|------|
[**usleep**](https://man7.org/linux/man-pages/man3/usleep.3.html) | int usleep(useconds_t usec); |shall cause the calling thread to be suspended from execution until either the number of realtime microseconds specified by the argument useconds has elapsed or a signal is delivered to the calling thread and its action is to invoke a signal-catching function or to terminate the process. The suspension time may be longer than requested due to the scheduling of other activity by the system.			|
[**gettimeofday**](https://c-for-dummies.com/blog/?p=4236) | int gettimeofday( struct timeval *, struct tzp * ); | fills two structures with details about the current time of day	|
[**pthread_create**](https://man7.org/linux/man-pages/man3/pthread_create.3.html) | int pthread_create(pthread_t * restrict thread, const pthread_attr_t * restrict attr, void *(* start_routine)(void *), void * restrict arg);| create a new thread |
[**pthread_detach**](https://man7.org/linux/man-pages/man3/pthread_detach.3.html) | int pthread_detach(pthread_t thread); | marks the thread identified by thread as detached.  When a detached thread terminates, its resources are automatically released back to the system without    the need for another thread to join with the terminated thread. Attempting to detach an already detached thread results in unspecified behavior.|
[**pthread_join**](https://man7.org/linux/man-pages/man3/pthread_join.3.html) | int pthread_join(pthread_t thread, void ** retval); | join with a terminated thread. The function waits for the thread specified by thread to terminate.  If that thread has already terminated, then      pthread_join() returns immediately.  The thread specified by thread must be joinable. |
[**pthread_mutex_init**](https://pubs.opengroup.org/onlinepubs/7908799/xsh/pthread_mutex_init.html) | int pthread_mutex_init(pthread_mutex_t * mutex, const pthread_mutexattr_t * attr); | initialises the mutex referenced by mutex with attributes specified by attr. If attr is NULL, the default mutex attributes are used; the effect is the same as passing the address of a default mutex attributes object. Upon successful initialisation, the state of the mutex becomes initialised and unlocked.	|
[**pthread_mutex_destroy**](https://pubs.opengroup.org/onlinepubs/7908799/xsh/pthread_mutex_init.html) | int pthread_mutex_destroy(pthread_mutex_t * mutex); |destroys the mutex object referenced by mutex; the mutex object becomes, in effect, uninitialised.|
[**pthread_mutex_lock**](https://pubs.opengroup.org/onlinepubs/7908799/xsh/pthread_mutex_lock.html) | int pthread_mutex_lock(pthread_mutex_t * mutex); | locks the object referenced by mutex. If the mutex is already locked, the calling thread blocks until the mutex becomes available. This operation returns with the mutex object referenced by mutex in the locked state with the calling thread as its owner			|
[**pthread_mutex_unlock**](https://pubs.opengroup.org/onlinepubs/7908799/xsh/pthread_mutex_lock.html) | int pthread_mutex_unlock(pthread_mutex_t * mutex); |releases the mutex object referenced by mutex.	|

### Resources
- Многопоточное программирование в Linux. Programming C/Linux [YouTube](https://www.youtube.com/watch?v=uFQwXtHsO4w)
- POSIX Threads [csc.villanova.edu](http://www.csc.villanova.edu/~mdamian/threads/posixthreads.html#applications)

