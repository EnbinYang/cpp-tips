# deadlock

Compile files

```main
g++ main.cpp -o main -std=c++11 -lpthread
```

Running

```bash
gdb ./main
```

`set pagination off` help us close the pagination. `set scheduler-locking on` start scheduler locks to prevent gdb debugging interfering with multi-threaded execution.

```bash
set pagination off
set scheduler-locking on
```

Start gdb debugging and it will stop at the point where the mutex lock is acquired.

```bash
run
```

Show all thread information

```bash
info threads
```

Enter thread #2 and use `bt` to view the stack information. You will observe that the `futex_wait` function is waiting to acquire a lock. Enter thread #3 and you will observe a similar result. This shows that the two threads have been waiting for each other's mutex locks.

```bash
thread 2
bt
```

Exit gdb

```bash
quit
```