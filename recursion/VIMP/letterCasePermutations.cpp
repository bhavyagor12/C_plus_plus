#include <bits/stdc++.h>
using namespace std;
void casePermutations(string input, string output)
{
    if (input.length() == 0)
    {
        cout << output << endl;
        return;
    }

    if (isalpha(input[0]))
    {
        // if aplha change caps/ no caps
        string op1 = output;
        string op2 = output;
        op1.push_back(tolower(input[0]));
        op2.push_back(toupper(input[0]));
        input.erase(input.begin() + 0);
        casePermutations(input, op1);
        casePermutations(input, op2);
    }
    else
    {
        string op1 = output;
        op1.push_back(input[0]);
        input.erase(input.begin() + 0);
        casePermutations(input, op1);
    }
}
int main()
{
    string input = "a1B2";
    string output = "";
    casePermutations(input, output);
    return 0;
}