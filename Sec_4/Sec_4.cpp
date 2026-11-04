#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Person
{
    string name;
    int age;
};

int main()
{
    int n;
    cout << "How many persons? ";
    cin >> n;
    cin.ignore();

    ofstream out("persons.txt");
    for (int i = 0; i < n; i++)
    {
        string name;
        int age;

        cout << "Enter name of person " << i + 1 << ": ";
        getline(cin, name);

        cout << "Enter age: ";
        cin >> age;
        cin.ignore();

        out << name << endl;
        out << age << endl;
    }
    out.close();

    vector<Person> people;
    ifstream in("persons.txt");
    Person p;
    while (getline(in, p.name))
    {
        in >> p.age;
        in.ignore();
        people.push_back(p);
    }
    in.close();

    if (people.empty())
    {
        cout << "No data found";
        return 0;
    }

    Person younger = people[0];
    Person older = people[0];
    for (int i = 1; i < people.size(); i++)
    {
        if (people[i].age < younger.age)
            younger = people[i];
        if (people[i].age > older.age)
            older = people[i];
    }

    ofstream results("results.txt");
    results << "Younger person: " << younger.name << " - " << younger.age << endl;
    results << "Older person: " << older.name << " - " << older.age << endl;
    results.close();

    cout << "Results saved in results.txt";
    return 0;
}
