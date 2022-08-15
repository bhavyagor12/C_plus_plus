#include <bits/stdc++.h>
using namespace std;
void spacesPermutations(string str, string output, int n)
{
    if (str.length() == 0)
    {
        cout << output << endl;
        return;
    }
    if (str.length() == n)
    {
        output.push_back(str[0]);
        str.erase(str.begin() + 0);
    }
    string op1 = output;
    string op2 = output;
    op1.push_back('_'); // pushing space with the letter
    op1.push_back(str[0]);
    op2.push_back(str[0]); // pushing letter without the space
    str.erase(str.begin() + 0);
    spacesPermutations(str, op1, n);
    spacesPermutations(str, op2, n);
}
int main()
{
    string str = "abc";
    string output = " ";
    int n = str.size();
    spacesPermutations(str, output, n);
    return 0;
}