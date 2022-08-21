#include <bits/stdc++.h>
using namespace std;
int minCoinsRecursive(int coins[], int sum, int n)
{
    if (sum == 0 && n != 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return INT_MAX - 1;
    }
    if (n == 1 && sum != 0)
    {
        if (sum % coins[n - 1] == 0)
        {
            return sum / coins[n - 1];
        }
        else
        {
            return INT_MAX - 1;
        }
    }
    if (coins[n - 1] <= sum)
    {
        return min(minCoinsRecursive(coins, sum, n - 1), 1 + minCoinsRecursive(coins, sum - coins[n - 1], n));
    }
    else
    {
        return minCoinsRecursive(coins, sum, n - 1);
    }
}
int minCoinsTabulation(int coins[], int sum, int n)
{
    int dp[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (j == 0 && i != 0)
            {
                dp[i][j] = 0;
            }
            if (i == 0)
            {
                dp[i][j] = INT_MAX - 1;
            }
        }
    }
    for (int j = 1; j < sum + 1; j++)
    {
        if (j % coins[0] == 0)
        {
            dp[1][j] = j / coins[0];
        }
        else
        {
            dp[1][j] = INT_MAX - 1;
        }
    }

    for (int i = 2; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (coins[i - 1] <= j)
            {
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
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
    cout << minCoinsRecursive(coins, sum, n);
    // cout << minCoinsTabulation(coins, sum, n);

    return 0;
}