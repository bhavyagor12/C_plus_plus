// v.v.v imp question
#include <bits/stdc++.h>
using namespace std;
#define N 100
bool checkValid(int arr[N], int n, int k, int mid)
{
    int student = 1;
    int sumOfPages = 0;
    for (int i = 0; i < n; i++)
    {
        sumOfPages += arr[i];
        if (sumOfPages > mid)
        {
            student++;
            sumOfPages = arr[i];
        }
        if (student > k)
        {
            return false;
        }
    }
    return true;
}
int findMinimumMax(int arr[N], int n, int k)
{
    int low = 0;  // low will be the max of arr[i]
    int high = 0; // high will be the sum of arr elements
    int maxPages = INT_MIN, sumOfPages = 0;
    for (int i = 0; i < n; i++)
    {
        maxPages = max(maxPages, arr[i]);
        sumOfPages += arr[i];
    }
    low = maxPages, high = sumOfPages;
    int res = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (checkValid(arr, n, k, mid) == true)
        {
            res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return res;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int k;
    cin >> k; // k stands for students here
    int arr[N];
    if (n < k) // #books should be more or atleast equal to students
    {
        return -1;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << findMinimumMax(arr, n, k);

    return 0;
}