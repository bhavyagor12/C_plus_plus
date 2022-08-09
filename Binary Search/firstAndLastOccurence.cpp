#include <bits/stdc++.h>
using namespace std;
int firstOccurence(vector<int> &nums, int val)
{
    int size = nums.size();
    int low = 0, high = size - 1;
    int res = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == val)
        {
            res = mid;
            high = mid - 1;
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
    return res;
}

int lastOccurence(vector<int> &nums, int val)
{
    int size = nums.size();
    int low = 0, high = size - 1;
    int res = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == val)
        {
            res = mid;
            low = mid + 1;
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
    return res;
}

int main()
{
    vector<int> nums = {2, 4, 10, 10, 10, 18, 20};
    int valToBeSearch = 10;
    cout << firstOccurence(nums, valToBeSearch) << " ";
    cout << lastOccurence(nums, valToBeSearch) << endl;
    return 0;
}