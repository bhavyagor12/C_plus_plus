#include <bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;

int knapsack(int value[], int weight[], int n, int W)
{

    if (n == 0 || W == 0)
        return 0;

    if (weight[n - 1] > W)
        knapsack(value, weight, n - 1, W);

    return max(knapsack(value, weight, n - 1, W - weight[n - 1]) + value[n - 1],
               knapsack(value, weight, n - 1, W));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int wt[] = {10, 20, 30};
    int value[] = {100, 50, 150};
    int W = 50;

    cout << knapsack(value, wt, 3, W) << endl;
}