#include <raylib.h>
#include <stdbool.h>

#define WIDTH 900
#define HEIGHT 600

#define WAVE_SPEED 10
#define PARTICLE_SIZE 10

struct Particle {
  float x, y, vx, vy;
};

struct Particle particle;

void init_wave(Vector2 origin) {
  // emit thousands of individual particles in different (circular) directions
  particle.x = origin.x;
  particle.y = origin.y;
  particle.vx = 1;
  particle.vy = 1;
}

void move_wave(float dt) {
  particle.x += particle.vx * dt;
  particle.y += particle.vy * dt;
}

void draw_wave() {
  DrawRectangle(particle.x, particle.y, PARTICLE_SIZE, PARTICLE_SIZE, WHITE);
}

int main(int argc, char *argv[]) {

  InitWindow(WIDTH, HEIGHT, "Waves Reflection Simulation");

  SetTargetFPS(60);

  bool wave_emitted = false;
  while (!WindowShouldClose()) {

    Vector2 mouse_pos = GetMousePosition();
    if (!wave_emitted) {
      init_wave(mouse_pos);
      wave_emitted = true;
    }

    move_wave(GetFrameTime());
    BeginDrawing();
    ClearBackground(BLACK);

    DrawRectangleV(mouse_pos, (Vector2){10, 10}, WHITE);
    draw_wave();

    EndDrawing();
  }

  return 0;
}
