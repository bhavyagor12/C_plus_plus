#include <bits/stdc++.h>
using namespace std;

void sortBasedOnFrequency(vector<int> &nums)
{
    unordered_map<int, int> mp;
    priority_queue<pair<int, int>> maxHeap; // for descending order on frequency
    int size = nums.size();
    for (int i = 0; i < size; i++)
    {
        mp[nums[i]]++;
    }
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        maxHeap.push({i->second, i->first});
    }
    while (!maxHeap.empty())
    {
        int frequencyOfEle = maxHeap.top().first;
        while (frequencyOfEle)
        {
            cout << maxHeap.top().second << " ";
            frequencyOfEle--;
        }
        maxHeap.pop();
    }
}

int main()
{

    vector<int> nums = {1, 1, 1, 3, 2, 2, 4};

    sortBasedOnFrequency(nums);

    return 0;
}