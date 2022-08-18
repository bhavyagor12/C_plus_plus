// 1 more than 0 in any prefix
#include <bits/stdc++.h>
using namespace std;
void generatePrefix(string &op, int n, int zeros, int ones, vector<string> &ans)
{
    if (n == 0)
    {
        ans.push_back(op);
        return;
    }
    if (ones <= zeros) // always starts with 1
    {
        op.push_back('1');
        generatePrefix(op, n - 1, zeros, ones + 1, ans);
        op.pop_back(); // backtrack
    }
    if (ones > zeros) // only when no of 1s is greater than zeros we can include zeros
    {
        if (n != 0)
        {
            op.push_back('0');
            generatePrefix(op, n - 1, zeros + 1, ones, ans);
            op.pop_back();
        }
        if (n != 0)
        {
            op.push_back('1');
            generatePrefix(op, n - 1, zeros, ones + 1, ans);
            op.pop_back();
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int zeros = 0;
    int ones = 0;
    string op = "";
    vector<string> ans;
    generatePrefix(op, n, zeros, ones, ans);
    for (auto &it : ans)
    {
        cout << it << " ";
    }
    return 0;
}