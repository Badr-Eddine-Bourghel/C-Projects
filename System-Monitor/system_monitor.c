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
