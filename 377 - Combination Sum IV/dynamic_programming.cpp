class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        auto DP = std::vector<unsigned int>(target + 1, 0);
        DP[0] = 1;
        for (std::size_t i = 1; i <= target; ++i)
        {
            for (const auto& num : nums)
            {
                if (i >= num)
                {
                    DP[i] += DP[i - num];
                }
            }
        }
        return DP[target];
    }
};