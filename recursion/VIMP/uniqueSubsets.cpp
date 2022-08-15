#include <bits/stdc++.h>
using namespace std;
void printSubsets(string str, string output, map<string, int> &m)
{
    if (str.size() == 0)
    {
        // as map ka index is string
        m[output]++;
        if (m[output] == 1)
            cout << output << endl;
        return;
    }
    string op1 = output;
    string op2 = output;
    op2.push_back(str[0]);
    str.erase(str.begin() + 0);
    printSubsets(str, op1, m);
    printSubsets(str, op2, m);
}
int main()
{
    string str = "aab";
    string output = " ";
    map<string, int> m;
    printSubsets(str, output, m);
}