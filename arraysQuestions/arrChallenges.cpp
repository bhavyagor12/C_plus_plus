#include <bits/stdc++.h>
using namespace std;

int main()
{

    // max till i code -- O(n) approach take mx variable at each index compare max
    // with the arr[i]. and print mx
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // int mx = -1999999999;

    // for (int i = 0; i < n; i++)
    // {
    //     mx = max(mx, arr[i]);
    //     cout << mx << endl;
    // }

    // int n;
    // cin >> n;
    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    // int sum = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     sum = 0;
    //     for (int j = i; j < n; j++)
    //     {
    //         sum += arr[j];
    //         cout << sum << endl;
    //     }
    // }

    // int n;
    // cin >> n;
    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    // int ans = 2;
    // int j = 2;
    // int current = 2;
    // int previous_common_difference = arr[1] - arr[0];

    // while (j < n)
    // {
    //     if (previous_common_difference == arr[j] - arr[j - 1])
    //     {
    //         current++;
    //     }
    //     else
    //     {
    //         previous_common_difference = arr[j] - arr[j - 1];
    //         current = 2;
    //     }
    //     ans = max(ans, current);
    //     j++;
    // }
    // cout << ans << endl;

    int mx = -199999;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        // simplified approach
        if (arr[i] > mx && arr[i] > arr[i + 1])
        {
            count++;
        }
        mx = max(mx, arr[i]);

        // my approach
        //  if ((arr[i] > arr[i + 1]) && (arr[i] > arr[i - 1]))
        //  {
        //      count++;
        //  }
        //  if (i == n - 1 && mx == arr[i])
        //  {
        //      count++;
        //  }
    }
    cout << count << endl;
}