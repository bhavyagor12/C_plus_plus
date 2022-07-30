#include <bits/stdc++.h>
using namespace std;

class A
{
public:
    A()
    {
        cout << "parent class" << endl;
    }
};

class B : public A
{
public:
    B()
    {

        cout << "single inheritance" << endl;
    }
};

class C : public A, public B // also hybrid
{
public:
    C()
    {
        cout << "Mulitple inheritance" << endl;
    }
};

class D : public B
{
public:
    C()
    {
        cout << "Multi level inheritance" << endl;
    }
};

int main()
{
    // B b;
    C c;
}