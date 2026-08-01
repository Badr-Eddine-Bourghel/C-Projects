#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define MAX_SNAKE_LEN     1024
#define MAX_OBSTACLES      40
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

static Point food;
static int food_is_golden;
static int golden_ticks_left;

static Point obstacles[MAX_OBSTACLES];
static int obstacle_count;

static int score;
static int high_score;
static int width, height;
static int paused;
static int use_color;

// high score persistance 

static const char *high_score_path(void){

  static char path[512];
  const char *home = getenv("HOME");

  if (home) {
    snprintf(path, sizeof(path),"%s%s", home, HIGH_SCORE_FILE);
  } else {
    snprintf(path, sizeof(path), "./%s", HIGH_SCORE_FILE);
  }
  return path;
}

static void load_high_score(void){

  FILE *f = fopen(high_score_path(),"r");

  if (f) {
    if(fscanf(f, "%d", &high_score) !=1) high_score= 0;
    fclose(f);
  }
}

static voide snake_high_score(void){
  if(score <= high_score) return;
  high_score = score;
  FILE *f = fopen(high_score_path(),"w");
  if(f) {
    fprintf(f, "%d\n",high_score);
    fclose(f);
  }

}

// placement holder 

static int occupied(int x , int y , int check_food){

  for (int i=0; i<snake_len; i++)
    if(snake[i].x == x && snake[i].y==y)return 1;

  for (int i=0; i<obstacle_count; i++)
    if (obstacles[i].x == x && obstacles[i].y == y) return 1;
  
  if(check_food && food.x== x && food.y) return 1;
  return 0;
}

static void spawn_food(void){
  do{
    food.x = rand() %(width - 2 ) + 1;
    food.y = rand() % (height -2 ) + 1;
  }while (occupied(food.x, food.y, 0));

  food_is_golden = (rand() % GOLDEN_CHANCE == 0);
  golden_ticks_left = GOLDEN_LIFETIME;
}

static voide spawn_obstacles(void){
  obstacle_count = height / 4;
  if (obstacle_count > MAX_OBSTACLES) obstacle_count = MAX_OBSTACLES
}
















