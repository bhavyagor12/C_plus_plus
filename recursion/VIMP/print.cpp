// basic problem to print from 1 to n
/// in vimportant as to improve the base of recursion
// induction base condition hypothesis
#include <bits/stdc++.h>
using namespace std;

void print(int n)
{
    // base condition means to stop at a particular case
    if (n == 1)
    {
        cout << 1 << " ";
        return;
    }
    print(n - 1);     // prints 1 to n-1
    cout << n << " "; // prints the nth char
}

void printNTo1(int n)
{
    // base condition
    if (n == 1)
    {
        cout << 1 << " ";
        return;
    }
    // induction here only had to do print 7
    cout << n << " ";
    // this returns 6 to 1
    printNTo1(n - 1);
}

int main()
{
    // print(7);
    printNTo1(7);
    return 0;
}