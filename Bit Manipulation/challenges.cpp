#include <bits/stdc++.h>
typedef unsigned long long int ll;
using namespace std;

bool isPowerOf2(int n)
{
    return (n && !(n & n - 1));
}
int noOfOnes(int n)
{
    int count = 0;
    while (n != 0) // while(n)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}
void subsets(int arr[], int n)
{
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                cout << arr[j] << " ";
            }
        }
        cout << endl;
    }
}

int uniqueNumber(int n, int arr[])
{
    int xorSum = 0;
    for (int i = 0; i < n; i++)
    {
        xorSum ^= arr[i];
    }

    return xorSum;
}

int getBit(int n, int pos)
{
    return (n & (1 << pos)) != 0;
}
void unique2Number(int n, int arr[])
{
    int xorSum = 0;
    for (int i = 0; i < n; i++)
    {
        xorSum ^= arr[i];
    }
    int tempXor = xorSum;
    int setbit = 0;
    int pos = 0;
    while (setbit != 1)
    {
        setbit = xorSum & 1;
        pos++;
        xorSum = xorSum >> 1;
    }
    int newXor = 0;
    for (int i = 0; i < n; i++)
    {
        if (getBit(arr[i], pos - 1))
        {
            newXor = newXor ^ arr[i];
        }
    }
    cout << newXor << endl;
    cout << (tempXor ^ newXor) << endl;
}

bool getBit2(int n, int pos)
{
    return (n & (1 << pos)) != 0;
}
int setBit2(int n, int pos)
{
    return (n | (1 << pos));
}
int unique3(int arr[], int n)
{
    int result = 0;
    for (int i = 0; i < 64; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (getBit2(arr[j], i))
            {
                sum++;
            }
        }
        if (sum % 3 != 0)
        {
            result = setBit2(result, i);
        }
    }
    return result;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // cout << isPowerOf2(14) << endl;
    // returns 0 for false and 1 for true
    // cout << noOfOnes(19) << endl;

    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // cout << uniqueNumber(n, arr) << endl;
    // unique2Number(n, arr);
    cout << unique3(arr, n) << endl;
    // subsets(arr, n);
}