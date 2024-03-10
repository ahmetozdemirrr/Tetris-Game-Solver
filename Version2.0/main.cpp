#include <iostream>
#include <vector>
#include "tetrominos.h"
#include "tetris.h"

using namespace std;

int main()
{
    int size, capacity = 0, i = 0;
    char type;

    cout << "What is the your tetris board size?" << endl;
    cin >> size;
        
    Tetris game(size);
    game.capacity = 0;
    game.tetrisNumber = 0;

    srand(time(NULL));

    do
    {
        cout << "Which shape of tetromino do you want? (I,O,T,J,L,S,Z). For random (R), quit (Q)" << endl;
        cin >> type;

        if (type == 'R')
        {
            int x;

            x = (1 + (rand() % 7));

            if (x == 1)
            {
                game.object.push_back(static_cast<name> ('I'));
                game.fit(game.object[i].tetForm);
                game.capacity += 1;
                i++;
            } 

            else if (x == 2)
            {
                game.object.push_back(static_cast<name> ('O'));
                game.fit(game.object[i].tetForm);
                game.capacity += 2;
                i++;
            }

            else if (x == 3)
            {
                game.object.push_back(static_cast<name> ('T'));
                game.fit(game.object[i].tetForm);
                game.capacity += 2;
                i++;
            }

            else if (x == 4)
            {
                game.object.push_back(static_cast<name> ('J'));
                game.fit(game.object[i].tetForm);
                game.capacity += 2;
                i++;
            }

            else if (x == 5)
            {
                game.object.push_back(static_cast<name> ('L'));
                game.fit(game.object[i].tetForm);
                game.capacity += 2;
                i++;
            }

            else if (x == 6)
            {
                game.object.push_back(static_cast<name> ('S'));
                game.fit(game.object[i].tetForm);
                game.capacity += 2;
                i++;
            }

            else
            {
                game.object.push_back(static_cast<name> ('Z'));
                game.fit(game.object[i].tetForm);
                game.capacity += 2;
                i++;
            }
        }

        else if (type == 'I' || type == 'O' || type == 'T' || type == 'J' || type == 'L' || type == 'S' || type == 'Z')
        {
            game.object.push_back(static_cast<name> (type));
            game.fit(game.object[i].tetForm);
            game.capacity += 2;
            i++;
        }

        else if (type == 'Q')
        {
            break;
        }

        else
        {
            cout << "Invalid character! " << endl;
        }
        
    }
    while (capacity < size);

	return 0;
}