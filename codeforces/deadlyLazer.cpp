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

    int t;
    cin >> t;
    while (t--)
    {
        int n, m, sx, sy, d;
        cin >> n >> m;
        cin >> sx >> sy >> d;
        int flag = 0;
        // // the last cell is blocked
        if (sx + d >= n && sy + d >= m)
        {
            flag++;
        }
        // the first cell is blocked
        if (sx - d <= 1 && sy - d <= 1)
        {
            flag++;
        }
        // horizontal blockage
        if (sx - d <= 1 && sx + d >= n)
        {
            flag++;
        }
        // vertical blockage
        if (sy + d >= m && sy - d <= 1)
        {
            flag++;
        }
        if (flag)
        {
            cout << -1 << endl;
        }
        else
            cout << n + m - 2 << endl;
    }
}