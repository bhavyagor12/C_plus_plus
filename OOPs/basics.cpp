#include <bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;

class student
{
    int sapid;

public:
    string name;
    int age;
    bool gender;

    student()
    {
        cout << "this is the default constructor";
    }

    // parameterized constructor
    student(string s, int a, bool g)
    {
        name = s;
        age = a;
        gender = g;
    }

    // copy constructor
    student(student &a)
    {
        name = a.name;
        age = a.age;
        gender = a.gender;
    }

    void getSapid(int i)
    {
        sapid = i;
    }
    void getInfo()
    {
        cout << "Enter Name: " << endl;
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Gender: " << endl;
        cin >> gender;
    }
    void printInfo()
    {
        cout << "Name: ";
        cout << name << endl;
        cout << "Age: ";
        cout << age << endl;
        cout << "Gender: ";
        cout << gender << endl;
    }
    // operator overloading
    bool operator==(student &a)
    {
        if (name == a.name && age == a.age && gender == a.gender)
        {
            return true;
        }
        return false;
    }

    ~student()
    {
        cout << "this is the destructor!";
    }
};

int main()
{
    // student a;
    // a.name = "Bhavya";
    // a.age = 20;
    // a.gender = 0;

    // student arr[3];
    // for (int i = 0; i < 3; i++)
    // {
    //     int j;
    //     cout << "Sapid = ";
    //     cin >> j;
    //     arr[i].getSapid(j);
    //     arr[i].getInfo();
    // }

    // for (int i = 0; i < 3; i++)
    // {
    //     arr[i].printInfo();
    // }

    student a("bhavya", 20, 0);
    student c = a;

    // need to do operator overloading
    if (c == a)
    {
        cout << " same af";
    }
    else
    {
        cout << "different af";
    }
}