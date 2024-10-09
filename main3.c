#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>

void  ChildProcess1(void);               
void  ChildProcess2(void);
void  ParentProcess(void);               
void  main(void)
{
     pid_t pid1, pid2;

     pid1 = fork();
     if (pid1 == 0) 
          ChildProcess1(); //Calls first child process
     pid2 = fork();
     if (pid2 == 0)
          ChildProcess2(); //Calls second child process
     ParentProcess(); //After two processes are terminated, ParentProcess is called
}

void  ChildProcess1(void)
{
     int i;
     srandom(time(NULL)); //Generates random time int from seed
     int iterations = (random() % 30) + 1;
     sleep_time = (random() % 10) + 1;

     for (i = 1; i <= iterations; i++)
        printf("Child Pid: %d is going to sleep!”, getpid(pid1));
          sleep(sleep_time);
          printf("Child Pid: is awake!\nWhere is my Parent: %d", getppid(pid1));
     exit(0);
}

void  ChildProcess2(void)
{
     int i;
     srandom(time(NULL));
     sleep_time = (random() % 10) + 1;

     for (i = 1; i <= iterations; i++)
          printf("Child Pid: %d is going to sleep!”, getpid(pid1));
          sleep(sleep_time);
          printf("Child Pid: is awake!\nWhere is my Parent: %d", getppid(pid2));
     exit(0);
}

void  ParentProcess(void)
{
    pid_t terminated_pid;
    printf("Child Pid: %d has completed", getpid(pid1));

    pid_t terminated_pid;
    printf("Child Pid: %d has completed", getpid(pid2));
    
}
