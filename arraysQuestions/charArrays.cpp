#include <bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // char arr[100] = "apple";
    // int i = 0;
    // while (arr[i] != '\0')
    // {
    //     cout << arr[i] << endl;
    //     i++;
    // }

    int n;
    cin >> n;
    char arr[n + 1];
    cin >> arr;

    int low = 0;
    int high = n - 1;
    while (low < high)
    {
        if (arr[low] != arr[high])
        {
            break;
        }
        else
        {
            low++;
            high--;
        }
    }
    if (low == high)
    {
        cout << " palidrome" << endl;
    }
    else
    {
        cout << " not a palidrome" << endl;
    }
}