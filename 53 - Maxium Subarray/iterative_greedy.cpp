class Solution {
public:
    bool canJump(vector<int>& nums) {
        auto maxJump{ 0 };
        auto i{ 0 };
        while (i <= maxJump && i < nums.size())
        {
            maxJump = std::max(maxJump, i + nums[i]);
            ++i;
        }

        return maxJump >= (nums.size() - 1);
    }
};