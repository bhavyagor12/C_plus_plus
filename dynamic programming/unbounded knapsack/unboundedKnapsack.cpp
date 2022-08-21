#include <bits/stdc++.h>
using namespace std;
int DP[102][1002];
int unboundedKnapsackRecursive(int val[], int wt[], int n, int capacity)
{
    if (n == 0 || capacity == 0)
    {
        return 0;
    }
    if (wt[n - 1] <= capacity)
    {
        return max(unboundedKnapsackRecursive(val, wt, n - 1, capacity), val[n - 1] + unboundedKnapsackRecursive(val, wt, n, capacity - wt[n - 1]));
    }
    else
    {
        return unboundedKnapsackRecursive(val, wt, n - 1, capacity);
    }
}

int unboundedKnapsackMemo(int val[], int wt[], int n, int capacity)
{
    if (n == 0 || capacity == 0)
    {
        return DP[n][capacity] = 0;
    }
    if (DP[n][capacity] != -1)
    {
        return DP[n][capacity];
    }
    if (wt[n - 1] <= capacity)
    {
        return DP[n][capacity] = max(unboundedKnapsackMemo(val, wt, n - 1, capacity), val[n - 1] + unboundedKnapsackMemo(val, wt, n, capacity - wt[n - 1]));
    }
    else
    {
        return DP[n][capacity] = unboundedKnapsackMemo(val, wt, n - 1, capacity);
    }
}

int unboundedKnapsackTabulation(int val[], int wt[], int n, int capacity)
{
    int dp[n + 1][capacity + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < capacity + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < capacity + 1; j++)
        {
            if (wt[i - 1] <= j)
            {
                dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i][j - wt[i - 1]]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][capacity];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int capacity;
    cin >> capacity;
    int val[n], wt[n];
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    memset(DP, -1, sizeof(DP));
    cout << unboundedKnapsackRecursive(val, wt, n, capacity) << endl;
    cout << unboundedKnapsackMemo(val, wt, n, capacity) << endl;
    cout << unboundedKnapsackTabulation(val, wt, n, capacity) << endl;

    return 0;
}