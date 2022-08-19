#include <bits/stdc++.h>
using namespace std;
bool subsetSumRecursive(int arr[], int n, int sum)
{
    if (n == 0 && sum == 0)
    {
        return true;
    }
    if (n == 0)
    {
        return false;
    }
    if (sum == 0)
    {
        return true;
        1 1
    }
    if (arr[n - 1] <= sum)
    {
        // we have two choices of choosing or no
        return (subsetSumRecursive(arr, n - 1, sum - arr[n - 1]) || subsetSumRecursive(arr, n - 1, sum));
    }
    else
    {
        return subsetSumRecursive(arr, n - 1, sum);
    }
}
bool DP[102][1002];
bool subsetSumMemo(int arr[], int n, int sum)
{
    if (n == 0 && sum == 0)
    {
        return DP[n][sum] = true;
    }
    if (n == 0)
    {
        return DP[n][sum] = false;
    }
    if (sum == 0)
    {
        return DP[n][sum] = true;
    }
    if (DP[n][sum] != NULL)
    {
        return DP[n][sum];
    }
    if (arr[n - 1] <= sum)
    {
        // we have two choices of choosing or no
        return DP[n][sum] = (subsetSumMemo(arr, n - 1, sum - arr[n - 1]) || subsetSumMemo(arr, n - 1, sum));
    }
    else
    {
        return DP[n][sum] = subsetSumMemo(arr, n - 1, sum);
    }
}

bool subsetSumTabulation(int arr[], int n, int sum)
{
    bool dp[n + 1][sum + 1];
    // initialization
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
            {
                dp[i][j] = false;
            }
            if (j == 0)
            {
                dp[i][j] = true;
            }
        }
    }

    // choice diagram
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = (dp[i - 1][j - arr[i - 1]] || dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
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
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << subsetSumRecursive(arr, n, sum) << endl;
    memset(DP, NULL, sizeof(DP));
    cout << subsetSumMemo(arr, n, sum) << endl;
    cout << subsetSumTabulation(arr, n, sum) << endl;
    return 0;
}