#include <algorithm>

class Solution {
public:
    int findMin(vector<int>& nums) {
        auto leftIndex{ 0 };
        auto rightIndex{ int(nums.size() - 1) };
        auto midIndex{ 0 };

        while (leftIndex < rightIndex)
        {
            midIndex = (leftIndex + rightIndex) / 2;
            if (nums[midIndex] > nums[rightIndex])
            {
                leftIndex = midIndex + 1;
            }
            else if (nums[midIndex] < nums[leftIndex])
            {
                rightIndex = midIndex;
            }
            else
            {
                return nums[leftIndex];
            }
        }
        return nums[leftIndex];
    }
};