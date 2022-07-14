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

    int n, m, key;
    cin >> n >> m >> key;
    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    int i = 0, j = m - 1;
    bool flag = 0;
    while (i < n && j >= 0)
    {
        if (arr[i][j] == key)
        {
            flag = 1;
            cout << i << " " << j << endl;
            break;
        }
        else if (arr[i][j] > key)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    if (flag == 1)
    {
        cout << "present" << endl;
    }
    else
    {
        cout << "not present" << endl;
    }
}