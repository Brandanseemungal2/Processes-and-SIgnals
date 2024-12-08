#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

volatile sig_atomic_t caught_signal = 0; //Signal flag
volatile sig_atomic_t alarm_count = 0;
time_t start_time, end_time;

void handle_alarm(int signal) {
  if (signal == SIGALRM) {
    alarm_count ++;
    alarm(1);
  }
}

void handle_sigint(int signal) {
  if (signal == SIGINT) {
    caught_signal = 1; // Flag set to exit the loop
  }
}

int main() {
  // Register signal handlers
  signal(SIGALRM, handle_alarm);
  signal(SIGINT, handle_sigint);

  //Record start time
  start_time = time(NULL);

  // Set initial alarm
  alarm(1);

  while(!caught_signal) {
    pause(); // Wait for a signal
  }

  //Calsulate and print execution time
  end_time = time(NULL);
  printf("\nProgram ran for %ld seconds.\n", end_time - start_time);
  printf("Number of alarms: %d\n", alarm_count);

  return 0;
}
