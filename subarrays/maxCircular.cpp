#include <bits/stdc++.h>
using namespace std;
int kadaneAlgo(int arr[], int n)
{
    int currSum = 0;
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        if (currSum < 0)
        {
            currSum = 0;
        }
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
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

    // maxSum = sum of array elements - sum of non contributing elements
    // two cases one which will require wrapping other wont
    // we find both cases sum and compare and print max
    int wrapsum;
    int nonwrapsum;
    nonwrapsum = kadaneAlgo(arr, n);
    int sum_of_array = 0;
    for (int i = 0; i < n; i++)
    {
        sum_of_array += arr[i];
        arr[i] = -arr[i];
    }
    wrapsum = sum_of_array + kadaneAlgo(arr, n);
    cout << max(wrapsum, nonwrapsum) << endl;
}