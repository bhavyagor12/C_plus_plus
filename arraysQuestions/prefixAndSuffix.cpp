#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int prefixMax[n], suffixMax[n];
    prefixMax[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefixMax[i] = max(prefixMax[i - 1], arr[i]);
    }
    suffixMax[n - 1] = arr[n - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        suffixMax[i] = max(suffixMax[i + 1], arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << prefixMax[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << suffixMax[i] << " ";
    }
    cout << endl;
    return 0;
}