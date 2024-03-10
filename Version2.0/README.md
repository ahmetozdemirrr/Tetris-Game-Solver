# Tetris Game C++ Implementation

## Part 2 : Tetris Class

### Overview

Continuing from Part 1, this C++ program extends the Tetris game by adding a Tetris class. The Tetris class includes functions for handling the Tetris board, adding Tetrominos, fitting them optimally, drawing the board, and animating Tetrominos dropping to the bottom.

### Tetris Class Functions

* Constructors: Takes the rectangular size of the Tetris board.

* Add: Adds a Tetromino to the board. The Tetromino is added at the top row in the middle.

* Fit: Rotates and moves the added Tetromino to produce the best fit when dropped to the bottom.

* Draw:  the Tetris board, optionally starting the drawing from the top.

* Animate:
	- Animates the added Tetromino dropping to the bottom of the board.
	- The animation includes rotating, moving, drawing, sleeping, and lowering the Tetromino until it hits the bottom.

## Usage

```bash
g++ main.cpp tetris.cpp tetrominos.cpp -o a.out
./a.out
```

or

```bash
make
```

1. Ask the user for the size of the Tetris board.
2. Ask for the Tetromino type (I, O, T, J, L, S, Z). User may enter R for random Tetromino, Q for quit.
3. Add the asked Tetromino to the board and animate.
4. Repeat steps 2-3 until the user decides to quit.

### Notes
- Submit two driver source files, each with a main function.
- The first driver code should test each member function of both classes and print/show the result on the screen.
- The second driver code should follow the specified usage steps.
- Create and submit only one makefile for the entire project.
- Do not use functions from the standard C library, and do not use C arrays.
- The program should have header and implementation files.
- Use all OOP techniques learned in lectures, including consts, C++11 features, etc.
- Test the programs carefully with at least 5 different runs.
