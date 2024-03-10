#ifndef _TETROMINOS_H_
#define _TETROMINOS_H_

#include <vector>

using std :: vector;

enum class name {I = 'I',O = 'O',T = 'T',J = 'J',L = 'L',S = 'S',Z = 'Z'};

class Tetromino
{
public:
    char symbol;
    vector<vector<char>> tetForm; //ilk vektörümüz
    Tetromino(name); //Constuctor
	vector<vector<char>> rotate(char, vector<vector<char>>); //Cisimleri döndürmek için yazdığımız fonksiyon
	void print(vector<vector<char>>) const;	

private:
	vector<vector<char>> rotatedTetForm; //Döndürme fonksiyonu için kullandığımız vektör
};

#endif
