# Sierpinski Triangle Simulator

A lightweight, interactive simulation demonstrating the construction of the [Sierpinski Triangle](https://en.wikipedia.org/wiki/Sierpi%C5%84ski_triangle) fractal, written in C using the [raylib](https://www.raylib.com/) library.

## Features

- **Recursive Generation**: Watch the generation of the Sierpinski Triangle over time, level by level.
- **Interactive Reset**: Reset the recursion depth back to zero at any point.

## Prerequisites

To build and run this project, you need:
- A C compiler (`gcc` recommended)
- `make`
- [raylib](https://www.raylib.com/) installed on your system.

## Building & Running

A `Makefile` is provided for easy compilation.

**To build the project:**
```bash
make build
```

**To run the simulator:**
```bash
make run
```
*(You can also run both commands at once using `make build && make run`)*

**To clean the build files:**
```bash
make clean
```

## Controls

- <kbd>Spacebar</kbd> : Reset the triangle generation depth to 0.
