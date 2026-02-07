#include <iostream>
#include <map>
using namespace std;

int main()
{
    // map< key_datatype , associative datatype > MapName
    map<string, int> Students;

    // Students[Key] = Associative value
    Students["Ahmed"] = 100;
    Students["Mai"] = 90;
    Students["Laila"] = 80;

    // Print Map Elements
    for (const auto &Pairs : Students) // & to avoid unnecessary copy
    {
        cout << "Student Name :" << Pairs.first << "\n"
             << "Grade: " << Pairs.second << endl;
    };

    cout << "\nFind\n";
    // Find Element -- Using Key
    if (Students.find("Mai") != Students.end()) // find Method uses Key , it will return the iterator if the key found  , will return end(no element) if it isn't existing
    {
        cout << "Name: Mai\n"
             << "Grade: " << Students["Mai"] << endl;
    }
}