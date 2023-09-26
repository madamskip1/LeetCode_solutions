class Solution {
public:
    int rob(vector<int>& nums) {
        return std::max(robLinear(nums, 0, nums.size() - 1), robLinear(nums, 1, nums.size()));
    }

    int robLinear(vector<int>& nums, int firstIndex, int lastIndex) {
        if (firstIndex >= nums.size())
        {
            return 0;
        }
        auto DP_minus_2{ 0 };
        auto DP_minus_1{ nums[firstIndex] };

        for (std::size_t i = firstIndex + 1; i < lastIndex; ++i)
        {
            auto temp = std::max(DP_minus_1, DP_minus_2 + nums[i]);
            DP_minus_2 = DP_minus_1;
            DP_minus_1 = temp;
        }
        return DP_minus_1;
    }
};