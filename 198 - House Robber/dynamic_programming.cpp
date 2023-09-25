class Solution {
public:
    int rob(vector<int>& nums) {
        auto DP = std::vector<int>(nums.size() + 1, 0);
        DP[0] = 0;
        DP[1] = nums[0];
        for (std::size_t i = 2; i <= nums.size(); ++i)
        {
            DP[i] = std::max(DP[i - 1], DP[i - 2] + nums[i - 1]);
        }
        return DP[nums.size()];
    }
};