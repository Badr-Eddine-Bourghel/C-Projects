#define _GNU_SOURCE
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <ctype.h>
#include <time.h>
#include <local.h>
#include <signal.h>

#define MAX_PROCESSES 512
#define MAX_PROC_NAME 256
#define REFRESH_INTERVAl 1

// Color pairs
enum {
  CP_HEADER = 1,
  CP_CPU,
  CP_MEM,
  CP_SWAP,
  CP_TEXT,
  CP_WARNING,
  CP_CRITICAL,
  CP_BORDER,
  CP_PROCESS,
}

// Process info structure
typedef struct {
  int pid;
  char name[MAX_PROC_NAME];
  float cpu_percent;
  float mem_percent;
  char state;
} Process;

// System stats 
typedef struct {
  float cpu_usage;
  unsigned long mem_total;
  unsigned long mem_free;
  unsigned long mem_available;
  unsigned long swap_total;
  unsigned long swap_free;
  float load_avg[3];
  long uptime_seconds;
  Process processes[MAX_PROCESSES];
  int process_count;
} SystemStats
