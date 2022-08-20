#include <bits/stdc++.h>
using namespace std;
bool subsetSum(int arr[], int n, int sum)
{
    bool dp[n + 1][sum + 1];
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
    for (int i = 1; i < n + 1; i++)
    {
        for (int jfor(int i = 0; i < n; i++) {
                 cout << arr[i] << " ";
             } = 1;
             j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                // if the sum is more than the element we can include or choose not to include
                // this means we can choose to include or no
                return (dp[i - 1][j - arr[i - 1]] || dp[i - 1][j]);
            }
            else
            {
                // not include
                return dp[i - 1][j];
            }
        }
    }

    return dp[n][sum];
}
bool equalSumPartition(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    if (sum % 2 != 0)
    {
        return false;
    }
    else
    {
        return subfor(int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        setSum(arr, n, sum / 2);
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    cout << equalSumPartition(arr, n);

    return 0;
}