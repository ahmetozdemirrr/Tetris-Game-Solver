#include "tetrominos.h"
#include "tetris.h"
#include <vector>
#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;

Tetris :: Tetris(int a)
{
    createBoard(a);
}

void Tetris :: createBoard(int x)
{
    vector<vector<char>> empty(x,vector<char>(x, '.')); //Board vektörünün boyutunu bu şekilde belirliyoruz.
    board = empty;
}

void Tetris :: fit(vector<vector<char>> x)
{
    int size = board.size();
    int count = 0;

    x = object[0].rotate('R',x);
    add(x);
    
    if (tetrisNumber <= size / 2) //Tetrominoları sola öteleyen algoritma.
    {
        for (int p = 0; p < size; ++p)
        {
            for (int i = 0; i < size; ++i)
            {
                for (int j = 0; j < size; ++j)
                {
                    if (board[j][i] == '.')
                    {
                        count++;
                    }
                    
                    if (count == size)
                    {
                        if (board[j][i] == '.')
                        {
                            for (int k = 0; k < size; ++k)
                            {
                                if (i < size - 1)
                                {
                                    board[k][i] = board[k][i+1];
                                    board[k][i+1] = '.';
                                }                          
                            }
                        }                   
                    }    
                }
                count = 0;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(250));
            cout << "\x1B[2J\x1B[H";
            draw();
        }
    }

    else
    {
        for (int p = 0; p < size; ++p)
        {
            for (int i = 0; i < size; ++i)
            {
                for (int j = 0; j < size; ++j)
                {
                    
                }
            }
        }
    }
    animate();
}

void Tetris :: add(vector<vector<char>> x)
{
    int size = board.size();
    int k = 0, m = 0;

    for (int i = 0; i < 4; ++i)  //Tetrominoyu boarda ekleyen algoritma
    {
        m = 0;

        for (int j = (size - 2)/2 - 1; j < (size - 2)/2 + 3; ++j)
        {           
            if (board[i][j] == '.')
            {
                board[i][j] = x[k][m];
                m++;
            }                           
        }
        k++;
    }
    tetrisNumber += 2;
}

void Tetris :: animate()
{ 
    int size = board.size();
    int countBottom = 0;

    for (int p = 0; p < size; ++p)  //Tetrominoyu boardın aşağısına öteleyen algoritma.
    {
        for (int i = size - 1; i > 0 ; --i)
        {
            for (int j = 0; j < size; ++j)
            {
                if (board[i][j] == '.')
                {
                    countBottom++;
                }
                
                if (countBottom == size)
                {
                    for (int k = 0; k < size; ++k)
                    {
                        board[i][k] = board[i-1][k];
                        board[i-1][k] = '.';
                    }
                }    
            }
            countBottom = 0;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
        cout << "\x1B[2J\x1B[H";
        draw();
    }   
}

void Tetris :: draw() const
{
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board[0].size(); ++j)
        {
            cout << board[i][j];
        }
        cout << endl;
    }
}
