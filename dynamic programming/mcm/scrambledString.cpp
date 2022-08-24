#include <bits/stdc++.h>
using namespace std;
unordered_map<string, bool> mp;
bool solve(string a, string b)
{
    // create key for map
    string temp = a;
    temp.push_back('_');
    temp.append(b);

    if (a.compare(b) == 0) // this means both strings are same
    {
        return true; // same string is scrambled with no swaps
    }

    int n = a.length();
    if (n <= 1)
    {
        return false;
    }
    if (mp.find(temp) != mp.end())
    {
        return mp[temp];
    }

    bool flag = false;
    for (int i = 1; i <= n - 1; i++)
    {
        bool swap, noswap;
        swap = solve(a.substr(0, i), b.substr(n - i, i)) && solve(a.substr(i, n - i), b.substr(0, n - i));
        // no swap
        noswap = solve(a.substr(0, i), b.substr(0, i)) && solve(a.substr(i, n - i), b.substr(i, n - i));
        if (swap || noswap)
        {
            flag = true;
            break;
        }
    }
    return mp[temp] = flag;
}
int main()
{
    string a, b;
    cin >> a >> b;
    int n = a.size();
    if (n != b.size()) // both string length dont match
    {
        cout << false; // this gives 0
    }
    if (n == 0) // both strings empty
    {
        cout << true;
    }
    cout << solve(a, b) << endl;
    return 0;
}