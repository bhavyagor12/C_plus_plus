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
    int targetSum;
    cin >> targetSum;
    int currSum = 0;

    int i = 0, j = 0, st = -1, en = -1;

    while (j < n && currSum + arr[j] < targetSum)
    {
        currSum += arr[j];
        j++;
    }
    if (currSum == targetSum)
    {
        cout << i + 1 << " " << j << endl;
        return 0;
    }
    while (j < n)
    {
        currSum += arr[j];
        while (currSum > targetSum)
        {
            currSum -= arr[i];
            i++;
        }
        if (currSum == targetSum)
        {
            st = i + 1;
            en = j + 1;
            break;
        }
        j++;
    }

    cout << st << " " << en << endl;
}