#include <bits/stdc++.h>
using namespace std;

string winnerOfGame(string a)
{
    int n = a.length();
    int countW = 0;
    int countB = 0;

    for (int i = 0; i < n; i++)
    {
        int counter = 1;
        while (a[i] == a[i + 1])
        {
            counter++;
            i++;
        }
        if (a[i] == 'W')
        {
            countW = counter - 2;
        }
        else
        {
            countB = counter - 2;
        }
    }
    if (countW > countB)
    {
        return "Wendy";
    }
    else
    {
        return "Bob";
    }
}

int main()
{
    string a;
    cin >> a;

    cout << winnerOfGame(a) << endl;
}