#include <raylib.h>

#define WIDTH 900
#define HEIGHT 600

int main() {

  InitWindow(WIDTH, HEIGHT, "Soritng Visualizer");

  while (!WindowShouldClose()) {
    BeginDrawing();

    DrawRectangle(50, 50, 30, 100, WHITE);

    EndDrawing();
  }
  CloseWindow();
}
