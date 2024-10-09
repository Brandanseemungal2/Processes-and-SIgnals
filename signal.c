#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

// Global variable to store the start time
time_t start_time;

void sigalrm_handler(int signum)
{ 
  // Signal handler for SIGALRM
  printf("Hello World!\n");
  alarm(5); // Reschedule the alarm to trigger again in 5 seconds
}

void sigint_handler(int signum)
{ 
  // Signal handler for SIGINT (CTRL-C)
  time_t end_time = time(NULL); // Get the end time
  double elapsed = difftime(end_time, start_time); // Calculate elapsed time
  printf("\nProgram executed for %.0f seconds.\n", elapsed);
  exit(0); // Exit after printing the time
}

int main(int argc, char *argv[])
{
  // Store the start time of the program
  start_time = time(NULL);

  // Register the handlers for SIGALRM and SIGINT
  signal(SIGALRM, sigalrm_handler);
  signal(SIGINT, sigint_handler);

  // Schedule a SIGALRM for every 5 seconds
  alarm(5);

  // Infinite loop
  while (1) {
    pause(); // Wait for signal to be delivered
  }

  return 0; // Never reached
}
