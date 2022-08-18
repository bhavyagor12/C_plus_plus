// when open == close then we have only one option to use open
// when close > open then we can use close

#include <bits/stdc++.h>
using namespace std;
void parethesisGenerator(string &op, int open, int close, vector<string> &ans)
{
    if (open == 0 && close == 0)
    {
        ans.push_back(op);
        return;
    }
    if (open != 0)
    {
        op.push_back('(');
        parethesisGenerator(op, open - 1, close, ans);
        op.pop_back();
    }
    if (close != 0)
    {
        if (open < close) // basically string has more open so the count of remaining open is less
        {
            op.push_back(')');
            parethesisGenerator(op, open, close - 1, ans);
            op.pop_back();
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int open = n;
    int close = n;
    string op = "";
    vector<string> ans;
    parethesisGenerator(op, open, close, ans);
    int size = ans.size();
    for (auto &it : ans)
    {
        cout << it << endl;
    }
    return 0;
}