# Double Pendulum Simulation

A lightweight, interactive simulation demonstrating the chaotic motion of a double pendulum, written in C using the [raylib](https://www.raylib.com/) library and raygui for UI controls.

## Features

- **Realistic Physics**: Simulates the complex and chaotic motion of a double pendulum system.
- **Interactive Controls**: Adjust the length and mass of both pendulums in real-time using on-screen sliders.
- **Visual Trail**: Displays a fading trail tracing the path of the second pendulum bob to visualize its chaotic trajectory.
- **Random Initial State**: Resets to a random initial angular configuration upon resetting.

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

- <kbd>Spacebar</kbd> : Reset the simulation to a new random state.
- **On-screen Sliders** : Adjust L1, L2 (Lengths) and M1, M2 (Masses).
