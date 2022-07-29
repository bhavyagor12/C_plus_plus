#include <bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;

int bruteForce(int arr[], int n)
{
    int inversions = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                inversions++;
            }
        }
    }
    return inversions;
}

long long merge(int arr[], int l, int mid, int r)
{
    long long inv = 0;
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int a[n1], b[n2];
    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[mid + i + 1];
    }
    // left half and right half get stored in temporary arrays

    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            arr[k] = a[i];
            i++;
            k++;
        }
        else
        { // this is the case of a[i] > b[j] hence a inversion will take place
            arr[k] = b[j];
            inv += n1 - i; // if a[i] is bigger than remaining elements following it will also be bigger as they are sorted
            j++;
            k++;
        }
    }
    while (i < n1)
    {
        arr[k] = a[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = b[j];
        j++;
        k++;
    }
    return inv;
}

long long mergeOptimised(int arr[], int l, int r)
{
    long long inversions = 0;
    if (l < r)
    {
        int mid = (l + r) / 2;
        inversions += mergeOptimised(arr, l, mid);     // left wale inversions
        inversions += mergeOptimised(arr, mid + 1, r); // right wale inversions
        inversions += merge(arr, l, mid, r);           // merge wale inversions
    }

    return inversions;
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
    // cout << bruteForce(arr, n);
    cout << mergeOptimised(arr, 0, n - 1);
}