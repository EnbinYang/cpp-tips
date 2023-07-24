# high-cpu

Compile files

```bash
g++ main.cpp -o main -std=c++11 -lpthread
```

Running

```bash
./main
```

Start gdb and load the executable file

```bash
gdb ./main $(pidof main)
```

Show all thread information

```bash
info threads
```

Switch to thread #2

```bash
thread 2
```

View stack information for thread #2. You will see that function `compute_task()` has been running the computation task

```bash
bt
```