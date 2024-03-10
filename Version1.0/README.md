# Tetris Game C++ Implementation

## Part 1 : Tetromino Class

### Overview

This C++ program implements a Tetromino class that represents Tetris pieces. The Tetromino class allows rotation (left and right) of the pieces and printing them on the screen. The class uses 2D vectors of characters to represent each tetromino.

### Tetromino Class Functions

* constructor: Takes a C++11 strong enum type parameter to represent one of the Tetris pieces (I to Z).

* rotate: Takes a parameter to rotate the tetromino either left or right.

* print: Prints the current tetromino on the screen.

* canFit: Takes another tetromino and the relative position of the other tetromino.
Checks if the other tetromino can fit at the specified position without any holes.
Returns true if it can fit, otherwise returns false.

## Usage :

```bash
g++ -o test main.cpp tetrominos.cpp
./test
```
or

```bash
make
```

1. When the program starts, it will ask the user how many tetrominos will be created in a vector of tetrominos.
2. The program will print each tetromino on the screen.
3. It will rotate each tetromino as many times as necessary so that they fit together horizontally as good as possible.
4. Finally, it will print each tetromino in this rotated form.

### Notes

- Do not use functions from the standard C library, and do not use C arrays.
- Use C++11 strong enum types for representing Tetrominos.
- Utilize C++ standard classes such as string, vector, list, etc.
- The program should have header and implementation files.
- Use all OOP techniques learned in lectures, including consts, C++11 features, etc

