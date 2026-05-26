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

void init_numbers() {
  for (int i = 0; i < COUNT; i++) {
    numbers[i] = i;
  }

  // Fisher Yates Shuffer
  for (int i = COUNT - 1; i >= 0; i--) {
    int j = rand() % (i + 1); // Generates a random number between 0 and i

    // Swap the array entries
    int tmp = numbers[i];
    numbers[i] = numbers[j];
    numbers[j] = tmp;
  }
}

int main() {

  init_numbers();

  InitWindow(WIDTH, HEIGHT, "Soritng Visualizer");

  while (!WindowShouldClose()) {
    BeginDrawing();

    // Draw numbers
    draw_bars();

    EndDrawing();
  }
  CloseWindow();
}
