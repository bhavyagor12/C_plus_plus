#include <bits/stdc++.h>
using namespace std;

bool pairSum(int arr[], int n, int targetSum) // O(n)
{
    int low = 0;
    int high = n - 1;

    while (low < high) // not low<=high because we need pairs
    {
        if (arr[low] + arr[high] > targetSum)
        {
            high--;
        }
        if (arr[high] + arr[low] < targetSum)
        {
            low++;
        }
        if (arr[high] + arr[low] == targetSum)
        {
            cout << low << " " << high << endl;
            return true;
        }
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int targetSum;
    cin >> targetSum;
    pairSum(arr, n, targetSum);
}