#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define MAX_SNAKE_LEN     1024
#define MAX_OBSTACKE      40
#define INITIAL_DELAY_US  120000
#define GOLDEN_CHANCE     5  /* 1 in N food spawns is golden*/
#define GOLDEN_LIFETIME   60 /* ticks before golden food expires*/
#define HIGH_SCORE_FILE   ".snake_highscore"
