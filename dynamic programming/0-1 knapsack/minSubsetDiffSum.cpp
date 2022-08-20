#include <bits/stdc++.h>
using namespace std;
void subsetSum(int arr[], int n, int range, vector<int> &validSums)
{
    // initialize the dp
    bool dp[n + 1][range + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < range + 1; j++)
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
        for (int j = 1; j < range + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                // chose or not to chose
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    // since we need to store till only half of range
    int halfOfRange = (range + 1) / 2;
    for (int j = 0; j < halfOfRange; j++)
    {
        if (dp[n][j] == true)
        {
            validSums.push_back(j);
        }
    }
}
int findMinDiff(int arr[], int n)
{
    // step 1: find the range(sum of array elements);
    int range = 0;
    for (int i = 0; i < n; i++)
    {
        range += arr[i];
    }
    // step 2: now we find valid sums;
    vector<int> validSums;
    subsetSum(arr, n, range, validSums);
    int minDiff = INT_MAX;
    for (int i = 0; i < validSums.size(); i++)
    {
        minDiff = min(minDiff, range - (2 * validSums[i]));
    }
    return minDiff;
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
    int minDifference = findMinDiff(arr, n);
    cout << minDifference;
    return 0;
}