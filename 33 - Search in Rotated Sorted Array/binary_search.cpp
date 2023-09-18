class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto left{ 0 };
        auto right{ int(nums.size()) - 1 };

        while (left < right)
        {
            auto mid{ int((left + right) / 2) };
            auto leftValue = nums[left];
            auto midValue = nums[mid];
            auto rightValue = nums[right];

            if (midValue == target)
            {
                return mid;
            }
            else if (midValue >= leftValue)
            {
                if (target >= leftValue && target <= midValue)
                {
                    right = mid;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else
            {
                if (target <= rightValue && target >= midValue)
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid;
                }
            }
        }
        if (nums[left] == target)
        {
            return left;
        }
        return -1;
    }
};