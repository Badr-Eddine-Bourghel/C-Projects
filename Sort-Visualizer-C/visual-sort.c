#include <raylib.h>
#include <stdbool.h>
#include <stdlib.h>

#define WIDTH 900
#define HEIGHT 600

#define COUNT 100

int numbers[COUNT];

typedef struct {
  bool swapped;
  int i, j; // bars that were swapped
  bool done;
} SortStatus;

void draw_bars(SortStatus status) {

  for (int i = 0; i < COUNT; i++) {
    int value = numbers[i];

    Color color = WHITE;
    if (status.done) {
      color = SKYBLUE;
    } else if (status.swapped && (i == status.i || i == status.j)) {
      color = RED;
    }

    int bar_height = (value * HEIGHT * 0.75) / COUNT;
    DrawRectangle(((float)i / COUNT) * WIDTH, (HEIGHT * 0.75) - bar_height,
                  WIDTH / COUNT - 2, bar_height, color);
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

SortStatus sort_step() {
  static SortStatus status = (SortStatus){false, 0, 1, false};
  static int i = 0;

  status.i = i;
  status.j = i + 1;
  if (status.i < COUNT - 1) {

    int current_value = numbers[status.i];
    int next_value = numbers[status.j];

    if (current_value > next_value) {
      swap(status.i, status.j);
      status.swapped = true;
    }
    i++;
  } else {
    if (!status.swapped) {
      // done
      status.done = true;
    }
    // Reached the end of the array -> go back to 0 and sort again
    i = 0;
    status.swapped = false;
  }
  return status;
}

int main() {

  init_numbers();

  InitWindow(WIDTH, HEIGHT, "Soritng Visualizer");

  SetTargetFPS(COUNT * 3);

  SortStatus status;
  while (!WindowShouldClose()) {

    if (!status.done) {
      status = sort_step();
    }

    BeginDrawing();
    ClearBackground(BLACK);
    // Draw numbers
    draw_bars(status);

    EndDrawing();
  }
  CloseWindow();
}
