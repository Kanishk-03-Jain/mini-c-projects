package main

import (
	"fmt"

	rl "github.com/gen2brain/raylib-go/raylib"
)

func main() {

	agents := initAgents()

	rl.InitWindow(Width, Height, "Random Walk Simulation")
	rl.SetTargetFPS(60)
	for !rl.WindowShouldClose() {
		if rl.IsKeyPressed(rl.KeySpace) {
			agents = initAgents()
		}

		rl.BeginDrawing()
		rl.ClearBackground(rl.Black)
		for i := range agents {
			agents[i].Draw()
			agents[i].Update()
		}

		rl.DrawText(fmt.Sprintf("Number of Agents: %d", NumAgents), 10, 10, 20, rl.White)
		rl.EndDrawing()
	}

	rl.CloseWindow()
}
