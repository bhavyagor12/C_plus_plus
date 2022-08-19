#include <bits/stdc++.h>
using namespace std;
int DP[102][1002];
int knapSack(int val[], int wt[], int n, int capacity)
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
    int maxProfit = knapSack(val, wt, n, capacity);
    cout << maxProfit;
    return 0;
}