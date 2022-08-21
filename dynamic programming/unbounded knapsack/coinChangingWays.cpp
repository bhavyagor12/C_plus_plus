#include <bits/stdc++.h>
using namespace std;
int coinChangingRecursive(int coins[], int sum, int n)
{
    if (n == 0 && sum == 0)
    {
        return 1;
    }
    if (n == 0)
    {
        return 0;
    }
    if (sum == 0)
    {
        return 1;
    }
    if (coins[n - 1] <= sum)
    {
        return (coinChangingRecursive(coins, sum, n - 1) + coinChangingRecursive(coins, sum - coins[n - 1], n));
    }
    else
    {
        return coinChangingRecursive(coins, sum, n - 1);
    }
}
int coinChangingTabulation(int coins[], int sum, int n)
{
    int dp[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
            {
                dp[i][j] = 0;
            }
            if (j == 0)
            {
                dp[i][j] = 1;
            }
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (coins[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
            if (n == 0 && sum == 0)
            {
                return 1;
            }
        }
    }
    return dp[n][sum];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int sum;
    cin >> sum;
    int coins[n];
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    cout << coinChangingRecursive(coins, sum, n) << endl;
    cout << coinChangingTabulation(coins, sum, n) << endl;

    return 0;
}