#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string line;

    ifstream in;
    in.open("fruit.txt");

    if (!in.is_open())
    {
        cout << "Error, file is not opened";
        return 1;
    }

    cout << "The fruits: " << endl;

    while (getline(in, line))
    {
        cout << line << endl;
    }

    in.close();

    ofstream out;
    out.open("fruit.txt", ios::app);               // فنهاية الملف fresh fruits لإضافة app هنستخدم 
                                           
    if (!out.is_open())
    {
        cout << "Error, file is not opened";
        return 1;
    }

    out << "Fresh Fruits" << endl;

    out.close();

    cout << "Fresh Fruits saved in the file";
    return 0;
}
