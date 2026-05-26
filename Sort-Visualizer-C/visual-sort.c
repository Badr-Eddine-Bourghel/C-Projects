#include <raylib.h>
#include <stdlib.h>

#define WIDTH 900
#define HEIGHT 600

#define COUNT 50

int numbers[COUNT];

void draw_bars() {

  for (int i = 0; i < COUNT; i++) {
    int value = numbers[i];
    int bar_height = (value * HEIGHT * 0.75) / COUNT;
    DrawRectangle(((float)i / COUNT) * WIDTH, (HEIGHT * 0.75) - bar_height,
                  WIDTH / COUNT - 2, bar_height, WHITE);
  };
}

void swap(int i, int j) {

  int tmp = numbers[i];
  numbers[i] = numbers[j];
  numbers[j] = tmp;
}

void init_numbers() {
  for (int i = 0; i < COUNT; i++) {
    numbers[i] = i;
  }

  // Fisher Yates Shuffer
  for (int i = COUNT - 1; i >= 0; i--) {
    int j = rand() % (i + 1); // Generates a random number between 0 and i

    // Swap the array entries
    swap(i, j);
  }
}

void sort_step() {
  static int i;

  if (i < COUNT - 1) {

    int current_value = numbers[i];
    int next_value = numbers[i + 1];

    if (current_value > next_value) {
      swap(i, i + 1);
    }
    i++;
  } else {
    // Reached the end of the array -> go back to 0 and sort again
    i = 0;
  }
}

int main() {

  init_numbers();

  InitWindow(WIDTH, HEIGHT, "Soritng Visualizer");

  SetTargetFPS(COUNT);
  while (!WindowShouldClose()) {

    sort_step();

    BeginDrawing();
    ClearBackground(BLACK);
    // Draw numbers
    draw_bars();

    EndDrawing();
  }
  CloseWindow();
}
