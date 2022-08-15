#include <bits/stdc++.h>
using namespace std;
void permutationsWithChange(string str, string output)
{
    if (str.length() == 0)
    {
        cout << output << endl;
        return;
    }
    string op1 = output;
    string op2 = output; // choices
    op1.push_back(toupper(str[0]));
    op2.push_back(str[0]);
    str.erase(str.begin() + 0);
    permutationsWithChange(str, op1);
    permutationsWithChange(str, op2);
}
int main()
{
    string str = "ab";
    string output = " ";
    permutationsWithChange(str, output);
}