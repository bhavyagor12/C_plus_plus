#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001]; /// according to constraints
int solve(int eggs, int floors)
{
    if (eggs == 1 || floors == 1 || floors == 0)
    {
        return floors; // no of attempts
    }
    if (dp[eggs][floors] != -1)
    {
        return dp[eggs][floors];
    }
    int ans = INT_MAX;
    // this is a linear search
    // for (int k = 1; k <= floors; k++)
    // {
    //     int breakEgg = solve(eggs - 1, k - 1);
    //     int noBreakEgg = solve(eggs, floors - k);
    //     int temp_ans = 1 + max(breakEgg, noBreakEgg);
    //     ans = min(ans, temp_ans);
    // }
    // can we make it binary? -- yes.
    int low = 1, high = floors, temp = 0;
    while (low <= high)
    {
        int mid = (low + (high + low)) / 2;
        int breakEgg = solve(eggs - 1, mid - 1);
        int noBreak = solve(eggs, floors - mid);
        temp = 1 + max(breakEgg, noBreak);
        if (breakEgg < noBreak)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
        ans = min(ans, temp);
    }

    return dp[eggs][floors] = ans;
}
int main()
{
    int eggs, floors;
    cin >> eggs >> floors;
    memset(dp, -1, sizeof(dp));
    cout << solve(eggs, floors);

    return 0;
}