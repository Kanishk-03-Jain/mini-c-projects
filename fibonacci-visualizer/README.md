# Fibonacci Visualizer

A mini C project that visualizes the Fibonacci sequence and the Golden Spiral using [Raylib](https://www.raylib.com/).

<img width="897" height="625" alt="image" src="https://github.com/user-attachments/assets/7ce8abb6-f1be-4d43-9c97-887f32c4c8bf" />


## Description

This project calculates the Fibonacci sequence and graphically represents it by drawing a series of squares, where the side length of each square corresponds to a Fibonacci number. Inside each square, a quarter-circle arc is drawn, connecting to form the famous Golden Spiral.

## Prerequisites

- **C Compiler**: GCC (or any standard C compiler).
- **Raylib**: Make sure Raylib is installed on your system.
  - **macOS**: `brew install raylib`
  - **Linux**: Install via your package manager or compile from source.
  - **Windows**: Follow instructions on the [Raylib Wiki](https://github.com/raysan5/raylib/wiki).

## How to Build and Run

1. **Build the project**
   ```bash
   make build
   ```

2. **Run the visualizer**
   ```bash
   make run
   ```

3. **Clean build files**
   ```bash
   make clean
   ```

## Configuration

You can tweak the visualizer by modifying the constants in `include/fibonacci.h`:
- `WIDTH`: Window width.
- `HEIGHT`: Window height.
- `COUNT`: The number of Fibonacci numbers to generate and draw.
- `SCALE`: Visual scaling factor for the blocks.
