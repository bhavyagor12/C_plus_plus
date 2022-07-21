#include <bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;

vector<vector<int>> ans;
// void permute(vector<int> &a, int idx)
// {
//     if (idx == a.size())
//     {
//         ans.push_back(a);
//         return;
//     }

//     for (int i = idx; i < a.size(); i++)
//     {
//         swap(a[i], a[idx]);
//         permute(a, idx + 1);
//         swap(a[i], a[idx]);
//     }
//     return;
// }

void helper(vector<int> a, vector<vector<int>> &ans1, int idx)
{
    if (idx == a.size())
    {
        ans1.push_back(a);
        return;
    }
    for (int i = idx; i < a.size(); i++)
    {
        if (i != idx and a[i] == a[idx])
        {
            continue;
        }
        swap(a[i], a[idx]);
        helper(a, ans1, idx + 1);
    }
}

vector<vector<int>> permuteWithDuplicates(vector<int> nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans1;
    helper(nums, ans1, 0);
    return ans1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
    {
        cin >> i;
    }

    // permute(a, 0);

    // STL TRICK still O(N!)

    // sort(a.begin(), a.end());
    // do
    // {
    //     ans.push_back(a);
    // } while (next_permutation(a.begin(), a.end()));

    vector<vector<int>> ans1 = permuteWithDuplicates(a);
    for (auto v : ans1)
    {
        for (auto u : v)
        {
            cout << u << " ";
        }
        cout << endl;
    }
}
