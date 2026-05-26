package main

import (
	"math/rand"

	rl "github.com/gen2brain/raylib-go/raylib"
)

type Agent struct {
	Position rl.Vector2
	Trail    Trail
	Size     rl.Vector2
	Colour   rl.Color
}

func (a *Agent) Draw() {
	for i := 0; i < a.Trail.Count; i++ {
		idx := (i + a.Trail.Head - a.Trail.Count + MaxTrail) % MaxTrail
		rl.DrawRectangleV(a.Trail.Positions[idx], a.Size, a.Colour)
	}
}

func (a *Agent) Move(direction int, stepSize float32) {
	switch direction {
	case 0:
		a.Position.X -= stepSize // Left
	case 1:
		a.Position.X += stepSize // Right
	case 2:
		a.Position.Y -= stepSize // Up
	case 3:
		a.Position.Y += stepSize // Down
	}

	// Screen Wrapping
	if a.Position.X < 0 {
		a.Position.X = Width - stepSize
	} else if a.Position.X >= Width {
		a.Position.X = 0
	}

	if a.Position.Y < 0 {
		a.Position.Y = Height - stepSize
	} else if a.Position.Y >= Height {
		a.Position.Y = 0
	}

	a.Trail.Positions[a.Trail.Head] = a.Position
	a.Trail.Head = (a.Trail.Head + 1) % MaxTrail
	if a.Trail.Count < MaxTrail {
		a.Trail.Count++
	}
}

func (a *Agent) Update() {
	direction := rand.Intn(4)
	stepSize := a.Size.X

	a.Move(direction, stepSize)
	a.Move(direction, stepSize)
}

func NewAgent() Agent {
	trail := Trail{
		Positions: make([]rl.Vector2, MaxTrail),
		Head:      0,
		Count:     0,
	}

	startPos := rl.Vector2{X: Width / 2, Y: Height / 2}

	colour := rl.Color{
		R: uint8(rand.Intn(256)),
		G: uint8(rand.Intn(256)),
		B: uint8(rand.Intn(256)),
		A: 255,
	}
	return Agent{
		Position: startPos,
		Trail:    trail,
		Size:     rl.Vector2{X: 5, Y: 5},
		Colour:   colour,
	}
}

func initAgents() [NumAgents]Agent {
	var agents [NumAgents]Agent
	for i := range agents {
		agents[i] = NewAgent()
	}
	return agents
}
