#include <raylib.h>

#define WIDTH 900
#define HEIGHT 600

#define COUNT 10

int numbers[COUNT];

void draw_bars() {

  for (int i = 0; i < COUNT; i++) {
    int value = numbers[i];
    int bar_height = (value * HEIGHT * 0.75) / COUNT;
    DrawRectangle(((float)i / COUNT) * WIDTH, (HEIGHT * 0.75) - bar_height,
                  WIDTH / COUNT - 2, bar_height, WHITE);
  };
}

int main() {

  for (int i = 0; i < COUNT; i++) {
    numbers[i] = i;
  }
  InitWindow(WIDTH, HEIGHT, "Soritng Visualizer");

  while (!WindowShouldClose()) {
    BeginDrawing();

    // Draw numbers
    draw_bars();

    EndDrawing();
  }
  CloseWindow();
}
