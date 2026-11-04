#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char name[20];
    int id;
    float grade;
    char choice = 'y';

    ofstream file("students.txt", ios::app);

    while (choice == 'y')
    {
        cout << "Enter Name: ";
        cin.getline(name, 20);

        cout << "Enter ID: ";
        cin >> id;

        cout << "Enter Grade: ";
        cin >> grade;

        file << name << ", " << id << ", " << grade << " $" << endl;

        cout << "Add more records? (y/n): ";
        cin >> choice;
        cin.ignore();
    }

    file.close();
    return 0;
}
