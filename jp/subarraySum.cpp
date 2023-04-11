#include <bits/stdc++.h>
using namespace std;

int subArray(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i] * (i + 1) * (n - i);
    }
    return sum;
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

    cout << subArray(arr, n) << endl;
}