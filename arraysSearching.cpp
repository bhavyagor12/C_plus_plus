/// List of variables to store similar type of datatype
// only integers/ float/ char/ string

// datatype arrayName[size];
// eg -- int array[4] = {1,2,3,4};
// indexing is used to access array elements starts with 0
// if array size is n then the indexes are 0 to n-1

#include <bits/stdc++.h>
using namespace std;

void linearSearch(int array[], int key, int n)
{
    int flag = 1;
    for (int i = 0; i < n; i++)
    {
        if (key == array[i])
        {
            cout << "found at index:" << i << endl;
            flag = 0;
            break;
        }
    }
    if (flag == 1)
    {
        cout << "not in array" << endl;
    }
}

int binarySearch(int array[], int key, int n)
{
    int startingPoint = 0;
    int endingPoint = n;
    while (startingPoint <= endingPoint)
    {
        int mid = (startingPoint + endingPoint) / 2;
        if (array[mid] == key)
        {
            return mid;
        }
        else if (array[mid] > key)
        {
            endingPoint = mid - 1;
        }
        else
        {
            startingPoint = mid + 1;
        }
    }
    return -1;
}
int main()
{
    // int array[4] = {1, 2, 3, 4};
    // cout << array[3] << endl;

    // int n;
    // cin >> n;
    // int array[n];

    // for (int i = 0; i < n; i++)
    // {
    //     cin >> array[i];
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << array[i] << endl;
    // }

    // Question -- take input from user and print max and min element
    // int n;
    // cin >> n;
    // int array[n];

    // for (int i = 0; i < n; i++)
    // {
    //     cin >> array[i];
    // }
    // int max = array[0];
    // int min = array[0];
    // for (int i = 1; i < n; i++)
    // {
    //     if (array[i] > max)
    //     {
    //         max = array[i];
    //     }
    //     if (array[i] < min)
    //     {
    //         min = array[i];
    //     }
    // }
    // cout << "max is: " << max << " "
    //      << " min is: " << min << endl;

    /// Searching in arraysss
    // a key taken from user is to be searched in array if present the output should be true else false
    // 2 methods -- linear and binary search(requires sorted array)

    // linear search approach
    int n;
    cin >> n;
    int key;
    cin >> key;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    // linearSearch(array, key, n); // time complexity will be O(n) as we traverse the array and go through it
    cout << "index is :" << binarySearch(array, key, n); // time complexity will be O(log n)
}