#include <bits/stdc++.h>
using namespace std;
#define N 100
void kClosestToOrigin(int arr[][N], int n, int k)
{
    priority_queue<pair<int, pair<int, int>>> maxHeap;
    for (int i = 0; i < n; i++)
    {
        maxHeap.push({arr[i][0] * arr[i][0] + arr[i][1] * arr[i][1], {arr[i][0], arr[i][1]}});
        if (maxHeap.size() > k)
        {
            maxHeap.pop();
        }
    }
    while (!maxHeap.empty())
    {
        pair<int, int> pear = maxHeap.top().second;
        cout << pear.first << " " << pear.second;
        cout << endl;
        maxHeap.pop();
    }
}
int main()
{
    int n, k;
    cin >> n >> k;
    int arr[N][N];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> arr[i][j];
        }
    }
    kClosestToOrigin(arr, n, k);

    return 0;
}