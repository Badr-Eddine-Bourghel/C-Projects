# Sorting Visualizer

A real-time **Bubble Sort visualizer** built in C using [raylib](https://www.raylib.com/). Watch 100 bars get sorted step-by-step, with swapped elements highlighted in red and the finished array glowing in sky blue.
---

## Demo

| State | Color |
|---|---|
| Unsorted bars | White |
| Active swap | Red |
| Fully sorted | Sky Blue |

---

## How It Works

1. An array of 100 integers (`0–99`) is initialized and shuffled using the **Fisher-Yates algorithm**.
2. Each frame, one step of **Bubble Sort** is executed — comparing adjacent elements and swapping them if out of order.
3. The sort completes when a full pass produces no swaps.
4. The window runs at `COUNT × 3 = 300 FPS` so the sort plays out smoothly in real time.

---

## Requirements

- **C compiler** (gcc, clang, or MSVC)
- **[raylib](https://github.com/raysan5/raylib)** — install via your package manager or build from source

```bash
# macOS (Homebrew)
brew install raylib

# Ubuntu / Debian
sudo apt install libraylib-dev

# Arch Linux
sudo pacman -S raylib
```

---

## Build & Run

```bash
# Clone the repo
git clone https://github.com/yourname/sorting-visualizer.git
cd sorting-visualizer

# Compile
gcc main.c -o sorting_visualizer -lraylib -lm

# Run
./sorting_visualizer
```

On **macOS** you may need to link additional frameworks:

```bash
gcc main.c -o sorting_visualizer -lraylib -lm -framework OpenGL -framework Cocoa -framework IOKit
```

---

## Project Structure

```
sorting-visualizer/
└── main.c       # All source code (single file)
```

---

## Configuration

These constants at the top of `main.c` are easy to tweak:

| Constant | Default | Description |
|---|---|---|
| `WIDTH` | `900` | Window width in pixels |
| `HEIGHT` | `600` | Window height in pixels |
| `COUNT` | `100` | Number of bars / elements to sort |

Increasing `COUNT` will also speed up the FPS target (`COUNT × 3`), keeping the animation at a consistent pace.

