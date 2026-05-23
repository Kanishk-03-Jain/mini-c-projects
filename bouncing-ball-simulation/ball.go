package main

import (
	"math/rand/v2"

	rl "github.com/gen2brain/raylib-go/raylib"
)

type Ball struct {
	Position Vector2 // Position vector of the ball
	Velocity Vector2 // Velocity vector of the ball
	R        float64 // Radius of the ball
	Trail    Trail   // Position trail of the ball
}

func NewBall() *Ball {
	return &Ball{
		Position: Vector2{float64(rand.IntN(50)), float64(rand.IntN(50))},
		Velocity: Vector2{float64(rand.IntN(50)), -float64(rand.IntN(50))},
		R:        BallRadius,
		Trail:    NewTrail(),
	}
}

func (b *Ball) Update(dt float64) {
	simulatedTime := dt * 10.0
	subSteps := 100
	subDt := simulatedTime / float64(subSteps)
	for range subSteps {
		b.updateVelocity(subDt)
		b.updatePosition(subDt)
		b.collisionX()
		b.collisionY()
	}
	b.Trail.Update(b.Position)
}

func (b *Ball) updateVelocity(dt float64) {
	b.Velocity.Y += Gravity * dt
}

func (b *Ball) updatePosition(dt float64) {
	b.Position.X += b.Velocity.X * dt
	b.Position.Y += b.Velocity.Y * dt
}

func (b *Ball) collisionX() {
	if b.Position.X+b.R >= float64(Width) {
		b.Position.X = float64(Width) - b.R
		b.Velocity.X = -CoeffOfRestution * b.Velocity.X
	}

	if b.Position.X-b.R <= 0 {
		b.Position.X = b.R
		b.Velocity.X = -CoeffOfRestution * b.Velocity.X
	}
}

func (b *Ball) collisionY() {
	if b.Position.Y+b.R >= float64(Height) {
		b.Position.Y = float64(Height) - b.R
		b.Velocity.Y = -CoeffOfRestution * b.Velocity.Y
	}

	if b.Position.Y-b.R <= 0 {
		b.Position.Y = b.R
		b.Velocity.Y = -CoeffOfRestution * b.Velocity.Y
	}
}

func (b *Ball) Draw() {
	b.Trail.Draw()
	rl.DrawCircle(int32(b.Position.X), int32(b.Position.Y), float32(b.R), rl.White)
}
