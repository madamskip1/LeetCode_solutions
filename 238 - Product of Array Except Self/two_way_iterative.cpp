class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        auto leftSide = std::vector(nums.size(), 1);

        std::size_t maxLoop = nums.size();
        for (std::size_t i = 1; i < maxLoop; ++i)
        {
            leftSide[i] = leftSide[i - 1] * nums[i - 1];
        }

        auto rightProduct{ nums[nums.size() - 1] };
        for (std::size_t i = nums.size() - 2; i > 0; --i)
        {
            leftSide[i] *= rightProduct;
            rightProduct *= nums[i];
        }
        leftSide[0] = rightProduct;

        return leftSide;
    }
};