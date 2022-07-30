#include <bits/stdc++.h>
using namespace std;

class A
{
private:
    int real, iamg;

public:
    // constructor overloading
    A(int r = 0, int i = 0)
    {
        real = r;
        iamg = i;
    }
    A operator+(A const &obj)
    {
        A res;
        res.iamg = iamg + obj.iamg;
        res.real = real + obj.real;
        return res;
    }
    // function overloading
    void display()
    {
        cout << real << " +i" << iamg << endl;
    }
    virtual void display(int x) // dynamic binding without virtual even if we put adrres in ptr still the base is called
    {
        cout << "with int " << x << endl;
    }
};

class B : public A
{
public:
    void display(int x)
    {
        cout << "inside of the derived class " << x << endl;
    }
};

int main()
{
    // A c1(12, 7);
    // A c2(13, 2);
    // A c3 = c1 + c2;
    // c3.display();
    // c2.display(3);
    A *baseptr;
    B d;
    baseptr = &d;
    baseptr->display(3);
}