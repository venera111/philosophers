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
cd philosophers/philo
make
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

### Resources
- Многопоточное программирование в Linux. Programming C/Linux [YouTube](https://www.youtube.com/watch?v=uFQwXtHsO4w)
- POSIX Threads [csc.villanova.edu](http://www.csc.villanova.edu/~mdamian/threads/posixthreads.html#applications)

