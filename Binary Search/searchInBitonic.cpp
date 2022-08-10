#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int> &nums)
{
    int size = nums.size();
    int low = 0, high = 0;
    int prev = 0, next = 0;
    if (size == 1)
    {
        return 0;
    }
    else
    {
        int mid = low + (high - low) / 2;
        if (mid == 0 && nums[mid] > nums[next])
        {
            return 0;
        }
        else if (mid == size - 1 && nums[mid] > nums[prev])
        {
            return size - 1;
        }
        else if (mid != 0 && mid != size - 1 && nums[mid] > nums[prev] && nums[mid] > nums[next])
        {
            return mid;
        }
        else if (mid != 0 && nums[mid] < nums[prev])
        {
            high = mid - 1;
        }
        else if (mid != size - 1 && nums[mid] < nums[next])
        {
            low = mid - 1;
        }
    }

    return -1;
}

int binaryAscending(vector<int> &nums, int low, int high, int val)
{

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == val)
        {
            return mid;
        }
        else if (nums[mid] < val)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int binaryDescending(vector<int> &nums, int low, int high, int val)
{

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == val)
        {
            return mid;
        }
        else if (nums[mid] < val)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {1, 3, 8, 12, 4, 2};
    int size = nums.size();
    int maxEle = findMax(nums);
    if (nums[maxEle] == 2)
    {
        cout << maxEle << endl;
    }
    int prev = maxEle - 1;
    int next = maxEle + 1;
    int last = size - 1;
    if (binaryAscending(nums, 0, prev, 2) != -1)
    {
        cout << binaryAscending(nums, 0, prev, 2)
             << endl;
    }
    if (binaryDescending(nums, next, last, 2) != -1)
    {
        cout << binaryDescending(nums, next, last, 2) << endl;
    }
    return 0;
}