#include <bits/stdc++.h>
using namespace std;
string lcs(string &x, string &y, int n, int m)
{
    int dp[n + 1][m + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int i = n;
    int j = m;
    string ans = "";
    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            ans.push_back(x[i - 1]);
            i--;
            j--;
        }
        else if (dp[i - 1][j] < dp[i][j - 1])
        {
            ans.push_back(y[j - 1]);
            j--;
        }
        else
        {
            ans.push_back(x[i - 1]);
            i--;
        }
    }
    while (i > 0)
    {
        ans.push_back(x[i - 1]);
        i--;
    }
    while (j > 0)
    {
        ans.push_back(y[j - 1]);
        j--;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return ans;
}
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string x, y;
    cin >> x >> y;
    int n = x.size();
    int m = y.size();
    string ans = lcs(x, y, n, m);
    string scSuperSequence = x + y;
    cout << scSuperSequence;
    return 0;
}