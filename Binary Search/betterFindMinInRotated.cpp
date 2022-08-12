class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int size = nums.size();
        int low = 0, high = size - 1;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (nums[high] == nums[mid]) // only for when array contains duplicates
            {
                high = high - 1;
            }
            else if (nums[high] > nums[mid])
            {
                high = mid;
            }
            else
            {
                // here high is smaller than mid
                low = mid + 1;
            }
        }
        return nums[low];
    }
};