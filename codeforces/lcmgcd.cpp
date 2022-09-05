#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
bool check(int a, int b)
{
    int value = a * b / (gcd(a, b) * gcd(a, b));
    if (value <= 3)
    {
        return true;
    }
    return false;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int count = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                if (check(i, j))
                {
                    if (i == j)
                    {
                        count++;
                    }
                    else
                    {
                        count += 2;
                    }
                }
            }
        }
        cout << count << endl;
    }
}