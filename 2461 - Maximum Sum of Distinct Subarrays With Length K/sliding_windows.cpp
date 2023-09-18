class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxSum = 0;
        long long curSum = 0;
        auto valueOccured = std::unordered_map<int, int>();

        for (std::size_t i = 0; i < k; ++i)
        {
            auto value = nums[i];
            curSum += value;
            ++valueOccured[value];
        }

        if (valueOccured.size() == k)
        {
            maxSum = curSum;
        }

        auto leftIndex = std::size_t{ 0 };

        for (std::size_t rightIndex = k; rightIndex < nums.size(); ++rightIndex)
        {
            auto leftValue = nums[leftIndex];
            auto rightValue = nums[rightIndex];
            curSum -= leftValue;
            curSum += rightValue;

            --valueOccured[leftValue];
            ++valueOccured[rightValue];
            if (valueOccured[leftValue] == 0)
            {
                valueOccured.erase(leftValue);
            }

            if (valueOccured.size() == k)
            {
                maxSum = std::max(curSum, maxSum);
            }
            ++leftIndex;
        }

        return maxSum;
    }
};