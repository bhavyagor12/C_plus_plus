#include <bits/stdc++.h>
using namespace std;
int maxLcsRecursive(string &x, string &y, int n, int m)
{
    if (n == 0 || m == 0)
        return 0;
    if (x[n - 1] == y[m - 1])
    {
        return (1 + maxLcsRecursive(x, y, n - 1, m - 1));
    }
    else
    {
        return max(maxLcsRecursive(x, y, n - 1, m), maxLcsRecursive(x, y, n, m - 1));
    }
}
int DP[100][1002];
int maxLcsMemo(string &x, string &y, int n, int m)
{
    if (n == 0 || m == 0)
    {
        return DP[n][m] = 0;
    }
    if (DP[n][m] != -1)
    {
        return DP[n][m];
    }
    if (x[n - 1] == y[m - 1])
    {
        return DP[n][m] = 1 + maxLcsMemo(x, y, n - 1, m - 1);
    }
    else
    {
        return DP[n][m] = max(maxLcsMemo(x, y, n - 1, m), maxLcsMemo(x, y, n, m - 1));
    }
}
int maxLcsTabulation(string &x, string &y, int n, int m)
{
    int dp[n + 1][m + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[n][m];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string x, y;
    cin >> x >> y;
    int n = x.size();
    int m = y.size();
    memset(DP, -1, sizeof(DP));
    cout << maxLcsRecursive(x, y, n, m) << endl;
    cout << maxLcsMemo(x, y, n, m) << endl;
    cout << maxLcsTabulation(x, y, n, m) << endl;
    return 0;
}