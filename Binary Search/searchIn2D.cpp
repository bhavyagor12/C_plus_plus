#include <bits/stdc++.h>
using namespace std;
#define N 100
vector<int> search2D(int arr[][N], int n, int target)
{
    vector<int> ans;
    int row = 0, col = n - 1;
    while (row <= n - 1 && col >= 0)
    {
        if (arr[row][col] == target)
        {
            ans.push_back(row);
            ans.push_back(col);
            return ans;
        }
        else if (arr[row][col] < target)
        {
            row++;
        }
        else
        {
            col--;
        }
    }
    if (ans.empty())
    {
        ans.push_back(-1);
    }
    return ans;
}
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int arr[N][N];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    vector<int> ans = search2D(arr, n, 51);
    for (auto &it : ans)
    {
        cout << it << " ";
    }
    return 0;
}
