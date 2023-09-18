class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        auto sum{ 0 };
        auto max{ nums[0] };

        for (auto& num : nums)
        {
            sum += num;
            if (sum > max)
            {
                max = sum;
            }
            if (sum < 0)
            {
                sum = 0;
            }
        }
        return max;
    }
};