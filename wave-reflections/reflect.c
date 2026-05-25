#include <math.h>
#include <raylib.h>
#include <stdbool.h>
#include <sys/param.h>

#define WIDTH 900
#define HEIGHT 600

#define WAVE_SPEED 150
#define PARTICLE_SIZE 6
#define PARTICLE_PER_WAVE 10000
#define TOTAL_POSSIBLE_PARTICLES PARTICLE_PER_WAVE * 10

struct Particle {
  float x, y, vx, vy;
};

int emitted_particles = 0;
int slot_index = 0;
struct Particle particles[TOTAL_POSSIBLE_PARTICLES];

void emit_wave(Vector2 origin) {
  // emit thousands of individual particles in different (circular) directions
  if (slot_index + PARTICLE_PER_WAVE >= TOTAL_POSSIBLE_PARTICLES) {
    slot_index = 0;
  }
  int start_index = slot_index;
  int end_index = start_index + PARTICLE_PER_WAVE;

  for (int i = start_index; i < end_index; i++) {
    particles[i].x = origin.x;
    particles[i].y = origin.y;
    particles[i].vx = WAVE_SPEED * sinf(2 * M_PI * (float)(i - start_index) /
                                        PARTICLE_PER_WAVE);
    particles[i].vy = WAVE_SPEED * cosf(2 * M_PI * (float)(i - start_index) /
                                        PARTICLE_PER_WAVE);
  }
  emitted_particles += PARTICLE_PER_WAVE;
  slot_index += PARTICLE_PER_WAVE;
}

void move_wave(float dt) {
  for (int i = 0; i < MIN(emitted_particles, TOTAL_POSSIBLE_PARTICLES); i++) {
    particles[i].x += particles[i].vx * dt;
    particles[i].y += particles[i].vy * dt;

    // Left boundries
    if (particles[i].x < 0) {
      particles[i].x = 0;
      particles[i].vx = -particles[i].vx;
    };
    if (particles[i].y < 0) {
      particles[i].y = 0;
      particles[i].vy = -particles[i].vy;
    };

    // Right boundries
    if (particles[i].x + PARTICLE_SIZE > WIDTH) {
      particles[i].x = WIDTH - PARTICLE_SIZE;
      particles[i].vx = -particles[i].vx;
    };
    if (particles[i].y + PARTICLE_SIZE > HEIGHT) {
      particles[i].y = HEIGHT - PARTICLE_SIZE;
      particles[i].vy = -particles[i].vy;
    };
  }
}

void draw_wave() {
  for (int i = 0; i < MIN(emitted_particles, TOTAL_POSSIBLE_PARTICLES); i++) {
    DrawRectangle(particles[i].x, particles[i].y, PARTICLE_SIZE, PARTICLE_SIZE,
                  WHITE);
  }
}

int main(int argc, char *argv[]) {

  InitWindow(WIDTH, HEIGHT, "Waves Reflection Simulation");

  SetTargetFPS(60);

  float interval = 0;
  while (!WindowShouldClose()) {

    Vector2 mouse_pos = GetMousePosition();

    float dt = GetFrameTime();
    interval += dt;

    if (interval >= 1) {

      emit_wave(mouse_pos);
      interval = 0;
    }

    move_wave(dt);
    BeginDrawing();
    ClearBackground(BLACK);

    draw_wave();
    EndDrawing();
  }

  return 0;
}
