#include <bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;

class student
{
public:
    string name;
    int age;
    bool gender;

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
};

int main()
{
    // student a;
    // a.name = "Bhavya";
    // a.age = 20;
    // a.gender = 0;

    student arr[3];
    for (int i = 0; i < 3; i++)
    {
        arr[i].getInfo();
    }

    for (int i = 0; i < 3; i++)
    {
        arr[i].printInfo();
    }
}