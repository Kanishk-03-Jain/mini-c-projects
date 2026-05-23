package main

import rl "github.com/gen2brain/raylib-go/raylib"

type Trail struct {
	Positions []Vector2
	Head      int32
	Count     int32
}

func NewTrail() Trail {
	return Trail{
		Positions: make([]Vector2, TrailLength),
		Head:      0,
		Count:     0,
	}
}

func (t *Trail) Draw() {

	for i := int32(0); i < t.Count; i++ {
		opacity := float32(i) / float32(t.Count)

		// oldest point is at (t.Head - t.Count + TrailLength) % TrailLength
		// traverse from oldest to newest with increasing opacity of color
		index := (i + t.Head - t.Count + TrailLength) % TrailLength
		pos := t.Positions[index]

		rl.DrawCircle(
			int32(pos.X), int32(pos.Y),
			3,
			rl.Fade(rl.Red, opacity),
		)
	}
}

func (t *Trail) Update(pos Vector2) {
	t.Positions[t.Head] = pos
	t.Head = (t.Head + 1) % TrailLength
	if t.Count < TrailLength {
		t.Count++
	}
}
