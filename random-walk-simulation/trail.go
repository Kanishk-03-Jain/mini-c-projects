package main

import rl "github.com/gen2brain/raylib-go/raylib"

type Trail struct {
	Positions []rl.Vector2
	Head      int
	Count     int
}
