#include <vector>

using std :: vector;

enum class name {I = 'I',O = 'O',T = 'T',J = 'J',L = 'L',S = 'S',Z = 'Z'};

class Tetromino
{
public:
    vector<vector<char>> tetForm; //ilk vektörümüz
    vector<vector<char>> rotatedTetForm; //Döndürme fonksiyonu için kullandığımız vektör
    Tetromino(name); //Constuctor
	void rotate(char, vector<vector<char>>); //Cisimleri döndürmek için yazdığımız fonksiyon
	void print(vector<vector<char>>) const;	
	bool canFit(vector<vector<char>>,vector<vector<char>>);
	vector<vector<char>> concatenate(vector<vector<char>>, vector<vector<char>>, int &);
	char symbol;
	vector<vector<char>> deleteColumn(vector<vector<char>>);
	vector<vector<char>> connect(vector<vector<char>>);
};