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

typedef struct {
  int x, y;
} Point;

typedef enum {DIR_UP, DIR_DOWN, DIR_LEFT, DIR_RIGHT} Direction;

enum {
  CP_SNAKE = 1,
  CP_FOOD,
  CP_GOLDEN,
  CP_WALL,
  CP_OBSTACLE,
  CP_TEXT
};

static Point snake[MAX_SNAKE_LEN];
static int snake_len;
static Direction dir;
