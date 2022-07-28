#include <bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;

void merge(int arr[], int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    // temporary array for merging
    int a[n1], b[n2];

    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[l + i]; // values from 0 to mid
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[mid + 1 + i]; // values from mid+1 to end
    }

    int i = 0;
    int j = 0;
    int k = l; // main array pointer

    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            arr[k] = a[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = b[j];
            j++;
            k++;
        }
    }

    // case when one pointer is last tak and one is left
    while (i < n1)
    {
        arr[k] = a[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = b[j];
        k++;
        j++;
    }
}

void mergeSorting(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeSorting(arr, l, mid);
        mergeSorting(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int arr[] = {5, 4, 3, 2, 1};
    mergeSorting(arr, 0, 4);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
