#include <bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string str;
    cin >> str;

    int count = 0;
    char majorityElement = '\0';
    for (int i = 0; i < str.size(); i++)
    {
        if (count == 0)
        {
            majorityElement = str[i];
        }
        if (majorityElement == str[i])
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    cout << majorityElement << endl;
}
