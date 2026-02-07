#include <iostream>
#include <map>
using namespace std;

class clsPerson
{
private:
    string name;
    short age;

public:
    clsPerson(string name, short age)
    {
        this->name = name;
        this->age = age;
    };

    string Print() const
    {
        return  "The Name Is: " + this->name +"\n";
        + "The Age Is: " + this->age +"\n";
    }
};

void InsertObjToMap(map<string, clsPerson> &StudentsDetailsWithID, string Id, const clsPerson &Obj)
{
    // StudentsDetailsWithID--> Map Name
    // Id --> Key
    // Obj --> Associated Value
    StudentsDetailsWithID[Id] = Obj;
};

int main()
{
    map<string, clsPerson> StudentsMap;

    clsPerson P1 = clsPerson("Jana", 22);
    string P1Id = "#1";
    InsertObjToMap(StudentsMap, P1Id, P1);

    clsPerson P2 = clsPerson("Jala", 24);
    string P2Id = "#2";
    InsertObjToMap(StudentsMap, P2Id, P2);

    // Print Map Elements
    for (const auto &Pairs : StudentsMap)
    {
        cout<<"The ID: "<<Pairs.first<<"\n";
        cout<<"The Student Details Is: "<<Pairs.second.Print()<<endl; 
    }
}