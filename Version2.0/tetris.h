#ifndef _TETRIS_H_
#define _TETRIS_H_

#include <vector>
#include "tetrominos.h"

using std :: vector;

class Tetris
{
public:
	int capacity;
	int tetrisNumber;
	vector<Tetromino> object;
	void fit(vector<vector<char>>);   
    Tetris(int);

private:
	vector<vector<char>> board; 
	void add(vector<vector<char>>);
	void draw() const;
	void animate();
    void createBoard(int);
};

#endif
