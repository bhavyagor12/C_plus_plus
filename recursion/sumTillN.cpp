#include <bits/stdc++.h>
using namespace std;

int sum(int n)
{
    if (n == 0)
        return 0;
    int prevSum = sum(n - 1);
    return n + prevSum;
}
int multiply(int n, int p)
{
    if (p == 0)
    {
        return 1;
    }
    int prevValue = multiply(n, p - 1);
    return n * prevValue;
}
int factorial(int n)
{
    if (n == 1 || n == 2)
        return n;
    int value = factorial(n - 1);
    return n * value;
}
int fibonnaci(int n)
{

    if (n == 0 || n == 1)
    {
        return n;
    }

    return fibonnaci(n - 1) + fibonnaci(n - 2);
}
int main()
{
    int n, p;
    cin >> n;
    // cout << sum(n) << endl;
    // cout << multiply(n, p) << endl;
    cout << factorial(n) << endl;
    // cout << fibonnaci(n) << endl;
}