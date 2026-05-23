# Bouncing Ball Simulation

A lightweight, interactive 2D physics simulation of a bouncing ball, written in Go using the `raylib-go` library.

## Features

- **Physics Simulation**: Demonstrates gravity, velocity updates, and collisions with a coefficient of restitution.
- **Visual Trail**: The ball leaves a trail of its previous positions for better visualization of its trajectory.
- **Sub-stepping**: Uses physics sub-stepping for more accurate collision detection.
- **Interactive**: Press `SPACE` to reset the ball's position and velocity with random values.
- **Real-time Stats**: Displays the real-time X and Y velocities of the ball on screen.

## Dependencies

- Go (1.20+ recommended)
- [raylib-go](https://github.com/gen2brain/raylib-go): Go bindings for the Raylib library. Note: A C compiler is required to build `raylib-go`.

## Build and Run

1. Clone the repository and navigate to the `bouncing-ball-simulation` directory.
2. Run the simulation using the Go CLI:
   ```bash
   go run .
   ```
   *Alternatively, build and run the executable:*
   ```bash
   go build -o bouncing-ball
   ./bouncing-ball
   ```

## Controls

- **SPACE**: Reset the simulation with a new random initial position and velocity.
