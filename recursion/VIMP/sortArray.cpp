#include <bits/stdc++.h>
using namespace std;

void insert(vector<int> &nums, int lastEle)
{
    int size = nums.size();
    if (size == 0 || nums[size - 1] <= lastEle)
    {
        nums.push_back(lastEle);
        return;
    }
    int val = nums[size - 1];
    nums.pop_back();
    insert(nums, lastEle);
    nums.push_back(val);
}
void arraySort(vector<int> &nums)
{
    if (nums.size() == 1)
    {
        return;
    }
    int lastEle = nums[nums.size() - 1];
    nums.pop_back();
    arraySort(nums);
    insert(nums, lastEle);
}

int main()
{
    vector<int> nums = {15, 23, 45, 12, 3, 2, 5, 1, 4, 6};
    arraySort(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}
