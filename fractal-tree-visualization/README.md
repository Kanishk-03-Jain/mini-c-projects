# Fractal Tree Visualization

A lightweight, interactive C program that visualizes the recursive generation of a fractal tree using the [raylib](https://www.raylib.com/) library.

<img width="902" height="827" alt="image" src="https://github.com/user-attachments/assets/d1ed6f0e-81b8-459a-a960-1b2745b5aff9" />

## Features

- **Recursive Generation**: The tree dynamically grows level by level over time, creating a visually appealing fractal structure.
- **Interactive Reset**: Press the spacebar to reset the tree's generation depth back to zero and watch it grow again.


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

**To run the visualization:**
```bash
make run
```
*(You can also run both commands at once using `make build && make run`)*

**To clean the build files:**
```bash
make clean
```

## Controls

- **SPACE**: Reset the tree generation depth to 0.
