CC = gcc
CFLAGS = -Wall -Wextra -g -I./include
LDFLAGS = -lraylib -lm

build:
	$(CC) $(CFLAGS) src/main.c src/simulation.c src/renderer.c -o doppler-simulator $(LDFLAGS)

run:
	./doppler-simulator

clean:
	rm -f doppler-simulator