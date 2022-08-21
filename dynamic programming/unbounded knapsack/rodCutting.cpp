// no variation to the unbounded knapsack -- same code
// wt[] becomes length[], val[] becomes price[]
#include <bits/stdc++.h>
using namespace std;
int rodCutting(int price[], int length[], int n)
{
    int dp[n + 1][n + 1];
    // i denotes n && j denotes the length
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (length[i - 1] <= j)
            {
                dp[i][j] = max(dp[i - 1][j], price[n - 1] + dp[i][j - length[i - 1]]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][n];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int price[n], length[n];
    for (int i = 1; i <= n; i++)
    {
        length[i] = i;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }
    cout << rodCutting(price, length, n);

    return 0;
}