# high-cpu

compile files

```bash
g++ main.cpp -o main -std=c++11 -lpthread
```

running

```bash
./main
```

start gdb and load the executable file

```bash
gdb ./main $(pidof main)
```

show all thread information

```bash
info threads
```

switch to thread #2

```bash
thread 2
```

view stack information for thread #2. You will see that function `compute_task()` has been running the computation task

```bash
bt
```