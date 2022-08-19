#include <bits/stdc++.h>
using namespace std;
int DP[102][1002]; // dp matrix made on what changes
// here we see that n -- size of array and capacity are changing
// hence we make matrix of that size
int knapSack(int val[], int wt[], int n, int capacity) // recursive + memo
{
    if (n == 0 || capacity == 0)
    {
        return 0;
    }
    if (DP[n][capacity] != -1)
    {
        return DP[n][capacity];
    }
    if (wt[n - 1] <= capacity)
    {
        // therefore we can include or no;
        return DP[n][capacity] = max(val[n - 1] + knapSack(val, wt, n - 1, capacity - wt[n - 1]), knapSack(val, wt, n - 1, capacity));
    }
    else
    {
        // here weight of the item is greater than capacity
        // so we cant include
        return DP[n][capacity] = knapSack(val, wt, n - 1, capacity);
    }
}

int knapSackTabulation(int val[], int wt[], int n, int capacity)
{
    int dp[n + 1][capacity + 1];
    // now step is of initialization
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

    // choice diagram
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < capacity + 1; j++)
        {
            if (wt[i - 1] <= j)
            {
                // we can include the weight
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], 0 + dp[i - 1][j]);
                // replace places where recursive call was done with matrix
                // replace n with i, capacity with j;
            }
            else
            {
                // wt[i-1] > j
                dp[i][j] = 0 + dp[i - 1][j];
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
    int wt[n], val[n];
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    memset(DP, -1, sizeof(DP));
    int maxProfit = knapSackTabulation(val, wt, n, capacity);
    cout << maxProfit;
    return 0;
}