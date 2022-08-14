// same problem of optimal cost -- huffman coding/ optimal merge
#include <bits/stdc++.h>
using namespace std;
int minCostMerge(vector<int> &ropes)
{
    int size = ropes.size();
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int totalCost = 0;
    for (int i = 0; i < size; i++)
    {
        minHeap.push(ropes[i]);
    }
    while (minHeap.size() > 1)
    {
        int first = minHeap.top();
        minHeap.pop();
        int second = minHeap.top();
        minHeap.pop();
        totalCost = totalCost + first + second;
        minHeap.push(first + second);
    }
    return totalCost;
}
int main()
{
    vector<int> ropes = {1, 2, 3, 4, 5};
    cout << minCostMerge(ropes) << endl;

    return 0;
}