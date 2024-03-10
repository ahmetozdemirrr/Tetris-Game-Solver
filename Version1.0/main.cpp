#include <iostream>
#include <vector>
#include "tetrominos.h"

using namespace std;

int main()
{
	vector<Tetromino> object; //Kullanıcının istediği şekilleri nesne olarak bir vektörde tutuyoruz.
   
    int count = 0;
    int numbOfShape; //Kullanılacak şekil sayısı
    char codeOfShape; //Şeklin tutulacağı değişken

    cout << "How many tetrominos?" << endl;
    cin >> numbOfShape;
    vector<vector<char>> lastMap(4, vector<char>(4*numbOfShape));

    cout << "What are the types?" << endl;

    for (int i = 0; i < numbOfShape; ++i)
    {
    	cin >> codeOfShape;
        object.push_back(static_cast<name> (codeOfShape)); 	
    }
    
    for (int i = 0; i < numbOfShape; ++i)
    {
        lastMap = object[i].concatenate(object[i].tetForm,lastMap,count);
    }
    
    cout << endl << "Your tetrominos " << endl;

    for (int i = 0; i < numbOfShape; ++i)
    {
    	object[i].print(object[i].tetForm);
    }
    
    cout << endl << "Best fit:" << endl;

    lastMap = object[0].deleteColumn(lastMap);
    lastMap = object[0].connect(lastMap);

    object[0].print(lastMap);

	return 0;
}
