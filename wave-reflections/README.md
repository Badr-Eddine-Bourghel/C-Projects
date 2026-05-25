# 🌊 Wave Reflections Simulation

A real-time wave propagation and reflection simulation built in C using [raylib](https://www.raylib.com/). Click anywhere on the screen to emit a wave that expands in all directions and bounces off the walls.

## Preview

Every second, a burst of **10,000 particles** is emitted radially from the mouse position, simulating a circular wave that reflects off all four boundaries of the window.

## Features

- Circular wave emission from the mouse cursor
- Particle-based wave simulation (up to 100,000 particles)
- Realistic boundary reflection on all four walls
- Automatic wave emission every second
- Runs at a locked 60 FPS

## Requirements

- A C compiler (`gcc` or `clang`)
- [raylib](https://github.com/raysan5/raylib) installed on your system

### Installing raylib

**Ubuntu / Debian**
```bash
sudo apt install libraylib-dev
```

**Arch Linux**
```bash
sudo pacman -S raylib
```

**macOS**
```bash
brew install raylib
```

## Building & Running

```bash
# Clone the repository
git clone https://github.com/Badr-Eddine-Bourghel/C-Projects.git
cd C-Projects/wave-reflections

# Compile
gcc main.c -o wave-reflections -lraylib -lm

# Run
./wave-reflections
```

## How It Works

| Constant | Value | Description |
|---|---|---|
| `WIDTH` / `HEIGHT` | 900 × 600 | Window dimensions |
| `WAVE_SPEED` | 150 px/s | Speed of each particle |
| `PARTICLE_SIZE` | 6 px | Size of each rendered particle |
| `PARTICLE_PER_WAVE` | 10,000 | Particles emitted per wave |
| `TOTAL_POSSIBLE_PARTICLES` | 100,000 | Circular buffer capacity |

Each wave distributes particles evenly across 360° using:

```c
vx = WAVE_SPEED * sin(2π * i / PARTICLE_PER_WAVE)
vy = WAVE_SPEED * cos(2π * i / PARTICLE_PER_WAVE)
```

When a particle hits a wall, its velocity component on that axis is inverted, simulating a reflection.

A circular buffer (`slot_index`) recycles old particles once the buffer is full, keeping memory usage constant.

## Controls

| Input | Action |
|---|---|
| Move mouse | Set the origin of the next wave |
| `ESC` | Close the window |
