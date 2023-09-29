class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        auto numsSize = nums.size();
        auto ans = std::vector<int>(numsSize * 2, 0);
        for (std::size_t i = 0; i < numsSize; ++i)
        {
            ans[i] = nums[i];
            ans[i + numsSize] = nums[i];
        }
        return ans;
    }
};