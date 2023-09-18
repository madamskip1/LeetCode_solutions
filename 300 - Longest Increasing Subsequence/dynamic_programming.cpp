class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        auto DP = std::vector<int>(nums.size(), 1);

        for (int i = nums.size() - 2; i >= 0; --i)
        {
            for (auto j = i + 1; j < nums.size(); ++j)
            {
                if (nums[i] < nums[j])
                {
                    DP[i] = std::max(DP[i], DP[j] + 1);
                }
            }
        }
        return *std::max_element(DP.cbegin(), DP.cend());
    }
};