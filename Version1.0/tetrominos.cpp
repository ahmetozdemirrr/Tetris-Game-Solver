#include "tetrominos.h"
#include <vector>
#include <iostream>

using namespace std;

Tetromino :: Tetromino(name x)
{
    //Şekillerin hepsi 4x4'lük vektörlerimizin sol alt köşesine gelecek şekilde diziyoruz.

    if (x == name :: I)
    {
        symbol = 'I';
        tetForm = {{' ',' ',' ',' '},{' ',' ',' ',' '},{' ',' ',' ',' '},{'I','I','I','I'}};
    }

    else if (x == name :: O)
    {
        symbol = 'O';
        tetForm = {{' ',' ',' ',' '},{' ',' ',' ',' '},{'O','O',' ',' '},{'O','O',' ',' '}};
    }

    else if (x == name :: T)
    {
        symbol = 'T';
        tetForm = {{' ',' ',' ',' '},{' ',' ',' ',' '},{'T','T','T',' '},{' ','T',' ',' '}};
    }

    else if (x == name :: J)
    {
        symbol = 'J';
        tetForm = {{' ',' ',' ',' '},{' ','J',' ',' '},{' ','J',' ',' '},{'J','J',' ',' '}};
    }

    else if (x == name :: L)
    {
        symbol = 'L';
        tetForm = {{' ',' ',' ',' '},{'L',' ',' ',' '},{'L',' ',' ',' '},{'L','L',' ',' '}};
    }

    else if (x == name :: S)
    {
        symbol = 'S';
        tetForm = {{' ',' ',' ',' '},{' ',' ',' ',' '},{' ','S','S',' '},{'S','S',' ',' '}};
    }

    else if (x == name :: Z)
    {
        symbol = 'Z';
        tetForm = {{' ',' ',' ',' '},{' ',' ',' ',' '},{'Z','Z',' ',' '},{' ','Z','Z',' '}};
    }
}

vector<vector<char>> Tetromino :: concatenate(vector<vector<char>> a,vector<vector<char>> comp, int & count) //Gelen objelerin vektörlerini yatay birleştir.
{   
    for (int i = 0; i < 4; ++i)
    {
		for (int k = 0; k < 4; ++k)
		{
			comp[k][i + count] = a[k][i];
		}    	
    }
    count += 4; //Sonraki vektör geldiğinde 4 sonraki indiste devam ediyoruz ki cisimler üst üste binmesin.

    return comp;
}

bool Tetromino :: canFit(vector<vector<char>> a, vector<vector<char>> b)
{	
    /*Bu fonksyion tamamlanmamıştır*/

    int count = 0;
    int flag = 0;

    vector<vector<char>> empty (4, vector<char>(8)); //İki vektörü buraya atıp en alttaki boşluk sayısına göre değerlendiriyoruz.

    empty = connect(deleteColumn(concatenate(a,b,count)));

    for (int i = 0; i < a.size(); ++i)
    {
        for (int j = 0; j < a[0].size(); ++j)
        {
            if (empty[3][j+1] != ' ' && empty[3][j+2] != ' ' && empty[3][j] == ' ')
            {
                flag++;
            }

            if (flag > 2)
            {
                //rotate('L',a);
            }
        }
    }
    return true;
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

vector<vector<char>> Tetromino :: connect(vector<vector<char>> connectForm) //Tüm şekillerin birleştirildiği büyük haritada arasında boşluk olan şekilleri iç içe geçir.
{
    int rightSpace1 = 0, rightSpace2 = 0; /*En sağdaki cismi de tüm şekle entegre ettikten sonra sağda daha fazla öteleme yapmamak için bu kontrol değişkenlerini kullanacağız */
                                            
    for (int i = 0; i < connectForm.size(); ++i) //Sol çapraz boşluklarını kontrol eder.
    {
        for (int j = 0; j < connectForm[0].size(); ++j)
        {
            if (connectForm[3][j] == ' ' && connectForm[2][j-1] == ' ')
            {
                if (connectForm[3][j-1] != ' ' && connectForm[2][j] != ' ')
                {
                    for (int k = 3; k >= 0; --k)
                    {
                        for (int m = j; m >= 0; --m)
                        {
                            if (connectForm[k][m] == ' ')
                            {
                                connectForm[k][m] = connectForm[k][m+1];
                                connectForm[k][m+1] = ' ';                               
                            }
                        }                       
                    }
                } 

                else if (connectForm[3][j])
                {
                    /* code */
                }            
            }
        }
    }
    
    for (int i = 0; i < connectForm.size(); ++i) //Sağ çapraz boşluklarını kontrol eder.
    {
        for (int j = 0; j < connectForm[0].size(); ++j)
        {
            if (connectForm[3][j] == ' ' && connectForm[2][j+1] == ' ')
            {
                if (connectForm[3][j-1] != ' ' && connectForm[3][j+1])
                {
                    for (int k = 3; k >= 0 ; --k)
                    {
                        for (int m = j; m < connectForm[0].size(); ++m)
                        {
                            if (connectForm[k][m] == ' ')
                            {
                                connectForm[k][m] = connectForm[k][m+1];
                                connectForm[k][m+1] = ' ';                                
                            }
                        }                        
                    }
                }              
            }
        }
    }
    return connectForm;
}

vector<vector<char>> Tetromino :: deleteColumn(vector<vector<char>> concatenateForm) //Şekillerin birleştirilmesiyle elde edilen haritada şekiller arasında sütun halinda boşluklar varsa sağdaki cismi boşluğa doğru kaydır.
{
    int countLeft = 0;

    for (int x = 0; x < 4; ++x) //Haritanın tamamını birkaç kez gezdiriyoruz çünkü 1 kere döndüğü zaman aralarda boş sütunlar kalabiliyor.
    {
        for (int i = 0; i < concatenateForm[0].size(); ++i)
        {
            for (int j = 0; j < concatenateForm.size(); ++j)
            {
                if (concatenateForm[j][i] == ' ') 
                {
                    countLeft++;
                }
                
                if (countLeft == 4) //Eğer bir sütunun dört elemanı da space ise buraya gir
                {
                    for (int k = 0; k < concatenateForm.size(); ++k)
                    {
                        if (i < concatenateForm[0].size() - 1)  //Hafızada aşım olmaması için son sütuna erişmemesini istiyoruz, cisimler hep sol köşede olduğu için son sütun zaten hep boş olmuş olacak.
                        {
                            concatenateForm[k][i] = concatenateForm[k][i+1];   /*Boş sütunu sonraki sütunla yer değiştir*/
                            concatenateForm[k][i+1] = ' ';                     
                        }                    
                    }
                }    
            }
            countLeft = 0;
        }
    }
    return concatenateForm;
}

void Tetromino :: rotate(char intersection ,vector<vector<char>> x)
{
    rotatedTetForm = x;
    int countLeft = 0;
    int countBottom = 0;
    int size = x.size();

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
                if (x[j][i] == ' ')
                {
                    countLeft++;
                }
                
                if (countLeft == 4)
                {
                    for (int k = 0; k < size; ++k)
                    {
                        x[k][i] = x[k][i+1];
                        x[k][i+1] = ' ';
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
                if (x[i][j] == ' ')
                {
                    countBottom++;
                }
                
                if (countBottom == 4)
                {
                    for (int k = 0; k < size; ++k)
                    {
                        x[i][k] = x[i-1][k];
                        x[i-1][k] = ' ';
                    }
                }    
            }
            countBottom = 0;
        }
    }
}
