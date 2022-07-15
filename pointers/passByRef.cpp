#include <bits/stdc++.h>
using namespace std;
void swap(int *a, int *b) // pass by value
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void increment(int *c)
{
    (*c)++; // direct *c++ wont work always extract and then use
    // think of it has bodmas rule
}
int main()
{
    int a = 2;
    int b = 4;
    int *aptr = &a;
    int *bptr = &b;

    // swap(a, b);// pass by value
    // swap(aptr, bptr);              // pass by reference
    // can be done like this
    swap(&a, &b);
    cout << a << " " << b << endl; // output is still 2,4
    int c = 3;
    increment(&c);
    cout << c << endl;
}