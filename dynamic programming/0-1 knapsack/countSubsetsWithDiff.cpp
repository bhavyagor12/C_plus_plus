#include <bits/stdc++.h>
using namespace std;
int subsetCount(int arr[], int n, int sum)
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
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}
int findCountWithGivenDiff(int arr[], int n, int diff)
{
    int sumOfArrayEle = 0;
    for (int i = 0; i < n; i++)
    {
        sumOfArrayEle += arr[i];
    }
    int sum1Partition = (sumOfArrayEle + diff) / 2;
    int countOfSubsets = subsetCount(arr, n, sum1Partition);
    return countOfSubsets;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int diff;
    cin >> diff;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int count = findCountWithGivenDiff(arr, n, diff);
    cout << count << endl;
}