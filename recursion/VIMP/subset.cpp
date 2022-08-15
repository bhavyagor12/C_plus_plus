#include <bits/stdc++.h>
using namespace std;
void printSubsets(string str, string output, vector<string> &v)
{
    if (str.length() == 0) // when inputsize is zero we print
    {
        // lexographically
        v.push_back(output);
        return;
    }
    string output1 = output;
    string output2 = output;
    output2.push_back(str[0]);
    str.erase(str.begin() + 0);
    printSubsets(str, output1, v);
    printSubsets(str, output2, v);
}
int main()
{
    string str = "abc";
    string output = " ";
    vector<string> v;
    printSubsets(str, output, v);
    sort(v.begin(), v.end());
    for (auto &i : v)
    {
        cout << i << " ";
    }
}