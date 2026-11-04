#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ofstream out("welcome.txt");
    out << "Hello Everybody";

    out.seekp(-4, ios::end);
    out << "one ";
    out.close();

    ifstream in("welcome.txt");
    string text;
    getline(in, text);
    in.close();

    cout << text;
    return 0;
}