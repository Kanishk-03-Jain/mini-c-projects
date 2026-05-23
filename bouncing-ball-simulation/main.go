package main

import (
	"fmt"

	rl "github.com/gen2brain/raylib-go/raylib"
)

func main() {
	rl.InitWindow(Width, Height, "Bouncing Ball Simulation")
	rl.SetTargetFPS(60)

	ball := NewBall()

	for !rl.WindowShouldClose() {
		if rl.IsKeyPressed(rl.KeySpace) {
			ball = NewBall()
		}

		dt := float64(rl.GetFrameTime())
		ball.Update(dt)

		rl.BeginDrawing()
		rl.ClearBackground(rl.Black)

		ball.Draw()

		rl.DrawText(fmt.Sprintf("Velocity X: %.2f", ball.Velocity.X), 10, 10, 20, rl.RayWhite)
		rl.DrawText(fmt.Sprintf("Velocity Y: %.2f", ball.Velocity.Y), 10, 40, 20, rl.RayWhite)
		rl.DrawText("Press SPACE to reset", 10, Height-30, 20, rl.LightGray)
		rl.EndDrawing()
	}

	rl.CloseWindow()
}
