#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cout << "Enter a string consisting of 0s and 1s" << endl;
    cin >> str;
    int length = str.size();
    int i = length - 1;
    while (str[i] == '1')
    {
        str[i] = '0';
        i--;
    }
    if (i >= 0)
    {
        str[i] = '1';
    }
    cout << str;
    return 0;
}