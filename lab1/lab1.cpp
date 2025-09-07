#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream f1("C:\\Users\\User\\Desktop\\шаражное\\лаба1\\lab1\\x64\\Debug\\file1.txt");
    ifstream f2("C:\\Users\\User\\Desktop\\шаражное\\лаба1\\lab1\\x64\\Debug\\file2.txt");
    ofstream fout("C:\\Users\\User\\Desktop\\шаражное\\лаба1\\lab1\\x64\\Debug\\result.txt");

    if (!f1.is_open() || !f2.is_open()) 
    {
        cerr << "помилка відкриття фалйів" << endl;              //відкриття файлів
        return 1;
    }
    if (!fout.is_open()) 
    {
        cerr << "помилка відкриття фалйів" << endl;
        return 1;
    }

    vector<int> v1, v2, result;
    int x;

    while (f1 >> x) 
    {                                      //читаємо 1 файл
        v1.push_back(x);
    }

    while (f2 >> x) 
    {                                      //читаємо 2 файл
        v2.push_back(x);
    }

    f1.close();                           //закриваємо вхідні файли
    f2.close();

    set_symmetric_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(result));  
                                                            //розраъунок симетричної різнтці
    for (size_t i = 0; i < result.size(); ++i)              //запис у файл рез
    {
        fout << result[i];
        if (i < result.size() - 1) {
            fout << " ";
        }
    }

    fout.close();                    //закрити файл

    cout << "результат записано в result.txt. перевіряйте" << endl;
    return 0;
}