#include "tetrominos.h"
#include "tetris.h"
#include <vector>
#include <iostream>

using namespace std;

Tetromino :: Tetromino(name x)
{
    //Şekillerin hepsi 4x4'lük vektörlerimizin sol alt köşesine gelecek şekilde diziyoruz.

    if (x == name :: I)
    {
        symbol = 'I';
        tetForm = {{'.','.','.','.'},{'.','.','.','.'},{'.','.','.','.'},{'I','I','I','I'}};
    }

    else if (x == name :: O)
    {
        symbol = 'O';
        tetForm = {{'.','.','.','.'},{'.','.','.','.'},{'O','O','.','.'},{'O','O','.','.'}};
    }

    else if (x == name :: T)
    {
        symbol = 'T';
        tetForm = {{'.','.','.','.'},{'.','.','.','.'},{'T','T','T','.'},{'.','T','.','.'}};
    }

    else if (x == name :: J)
    {
        symbol = 'J';
        tetForm = {{'.','.','.','.'},{'.','.','.','.'},{'J','.','.','.'},{'J','J','J','.'}};
    }

    else if (x == name :: L)
    {
        symbol = 'L';
        tetForm = {{'.','.','.','.'},{'.','.','.','.'},{'L','L','L','.'},{'L','.','.','.'}};
    }

    else if (x == name :: S)
    {
        symbol = 'S';
        tetForm = {{'.','.','.','.'},{'.','.','.','.'},{'.','S','S','.'},{'S','S','.','.'}};
    }

    else if (x == name :: Z)
    {
        symbol = 'Z';
        tetForm = {{'.','.','.','.'},{'.','.','.','.'},{'Z','Z','.','.'},{'.','Z','Z','.'}};
    }
}

void Tetromino :: print(vector<vector<char>> a) const
{
    for (int i = 0; i < a.size(); ++i)
    {
    	for (int j = 0; j < a[0].size(); ++j)
    	{
    		cout << a[i][j];
    	}
    	cout << endl;
    }
}

vector<vector<char>> Tetromino :: rotate(char intersection ,vector<vector<char>> x)
{
    rotatedTetForm = x;
    int countLeft = 0, countBottom = 0, size = x.size();

    /* Bu fonksiyonda cisimlerin bulunduğu vektörleri 4x4'lük kare gibi düşünüyoruz cisimleri döndürmek istediğim zaman
    direkt olarak karenin kendisini döndürürsem şekil de dönmüş olur. if bloklarının içinde karenin köşelerini birbiriyle
    sırasıyla en içtekine kadar swap ediyoruz. */

    if (intersection == 'R') //Sağa döndürme
    {
        for (int i = 0; i < size / 2; ++i)
        {
            for (int j = i; j < size - i -1; ++j)
            {
                char y = x[i][j];
                x[i][j] = x[j][size - 1 - i];
                x[j][size - 1 - i] = x[size - 1 - i][size - 1 - j];
                x[size - 1 - i][size - 1 - j] = x[size - 1 -j][i];
                x[size - 1 - j][i] = y;
            }
        }
    }

    else if (intersection == 'L') //Sola döndürme
    {
        for (int i = 0; i < size / 2; ++i)
        {
            for (int j = i; j < size - i -1; ++j)
            {
                char y = x[j][size - 1 - i];
                x[j][size - 1 - i] = x[i][j];
                x[i][j] = x[size - 1 -j][i];
                x[size - 1 - j][i] = x[size - 1 - i][size - 1 - j];
                x[size - 1 - i][size - 1 - j] = y;
            }
        }
    }

    /*Rotate fonksiyonuna gelen her vektör döndürüldükten sonra herhangi bir konumda bulunacağı için vektörler
    aşağıdaki iki for ile tekrardan sol en alta alınıyor. */

    for (int p = 0; p < 3; ++p)
    {
        for (int i = 0; i < size - 1; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                if (x[j][i] == '.')
                {
                    countLeft++;
                }
                
                if (countLeft == 4)
                {
                    for (int k = 0; k < size; ++k)
                    {
                        x[k][i] = x[k][i+1];
                        x[k][i+1] = '.';
                    }
                }    
            }
            countLeft = 0;
        }
    }

    for (int p = 0; p < 3; ++p)
    {
        for (int i = size - 1; i > 0 ; --i)
        {
            for (int j = 0; j < size; ++j)
            {
                if (x[i][j] == '.')
                {
                    countBottom++;
                }
                
                if (countBottom == 4)
                {
                    for (int k = 0; k < size; ++k)
                    {
                        x[i][k] = x[i-1][k];
                        x[i-1][k] = '.';
                    }
                }    
            }
            countBottom = 0;
        }
    }
    return x;
}
