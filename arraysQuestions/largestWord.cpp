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

    int n;
    cin >> n;
    cin.ignore();
    char arr[n + 1];
    cin.getline(arr, n);
    cin.ignore();
    int i = 0;
    int currLength = 0, maxLength = 0;

    int start = 0, maxStart = 0;
    while (1)
    {
        if (arr[i] == ' ' || arr[i] == '\0')
        {
            if (currLength > maxLength)
            {
                maxLength = currLength;
                maxStart = start;
            }
            currLength = 0;
            start = i + 1;
        }
        else
            currLength++;
        if (arr[i] == '\0')
        {
            break;
        }
        i++;
    }
    cout << maxLength << endl;
    for (int i = 0; i < maxLength; i++)
    {
        cout << arr[i + maxStart];
    }
}