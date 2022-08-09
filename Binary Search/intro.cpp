#include <bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> &nums, int val)
{
    int size = nums.size();
    int low = 0, high = size - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
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

int main()
{
    vector<int> nums = {1, 5, 2, 3, 7, 4, 9, 6, 8};
    sort(nums.begin(), nums.end());
    int valToBeSearch = 4;
    cout << binarySearch(nums, valToBeSearch);

    return 0;
}