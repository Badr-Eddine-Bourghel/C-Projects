# Terminal Snake

A classic Snake game for the terminal, built in C with `ncurses`. Features colored rendering, obstacles, golden food with a bonus/timeout mechanic, wraparound edges, pause, and a persistent high score saved to disk.

## Features

- Smooth terminal rendering via `ncurses`, with color support when the terminal allows it
- Wraparound walls — the snake passes through the border instead of dying
- Randomly placed obstacles that end the game on collision
- Two food types:
  - Regular food (`*`) — worth 10 points, grows the snake by 1
  - Golden food (`$`) — worth 50 points, grows the snake by 3, and disappears if not eaten within a time limit
- Increasing difficulty — game speed ramps up as your score grows
- Pause/resume with `p`
- Persistent high score, stored in `~/.snake_highscore`

## Requirements

- A C compiler (`gcc` or `clang`)
- The `ncurses` development library

On Debian/Ubuntu:
```bash
sudo apt install build-essential libncurses-dev
```

On macOS (with Homebrew):
```bash
brew install ncurses
```

## Build

```bash
gcc -o snake snake.c -lncurses
```

(Replace `snake.c` with whatever you name the source file.)

## Run

```bash
./snake
```

## Controls

| Key           | Action        |
|---------------|---------------|
| `W` / ↑       | Move up       |
| `S` / ↓       | Move down     |
| `A` / ←       | Move left     |
| `D` / →       | Move right    |
| `P`           | Pause/resume  |
| `Q`           | Quit          |

## How it works

- The snake dies on collision with an obstacle or itself. Hitting the outer wall instead wraps the snake around to the opposite side.
- Golden food (`$`) is worth more but only stays on the board for a limited number of ticks before it respawns elsewhere.
- The high score is read from and written to `~/.snake_highscore` (or the current directory if `$HOME` isn't set), so your best run persists between sessions.

## Files

| File                  | Purpose                                  |
|-----------------------|-------------------------------------------|
| `snake.c`              | Game source code                         |
| `~/.snake_highscore`   | Saved high score (created automatically) |
