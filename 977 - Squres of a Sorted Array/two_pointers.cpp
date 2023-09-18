class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        auto squares = std::vector<int>(nums.size());
        auto k = nums.size() - std::size_t(1);
        auto rightIndex = nums.size() - std::size_t(1);
        auto leftIndex = 0;

        while (leftIndex <= rightIndex)
        {
            auto leftValue = abs(nums[leftIndex]);
            auto rightValue = abs(nums[rightIndex]);
            if (leftValue >= rightValue)
            {
                squares[k] = leftValue * leftValue;
                ++leftIndex;
            }
            else
            {
                squares[k] = rightValue * rightValue;
                --rightIndex;
            }

            --k;
        }
        return squares;
    }
};