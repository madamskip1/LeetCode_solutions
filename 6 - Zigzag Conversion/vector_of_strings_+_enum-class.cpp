class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        auto numsSize = nums.size();
        auto triplets = std::vector<std::vector<int>>();

        for (std::size_t i = 0; i < numsSize - 2;)
        {
            auto firstValue = nums[i];
            auto secondIndex = i + 1;
            auto thirdIndex = numsSize - 1;

            while (secondIndex < thirdIndex)
            {
                auto secondValue = nums[secondIndex];
                auto thirdValue = nums[thirdIndex];
                auto sum = firstValue + secondValue + thirdValue;

                if (sum < 0)
                {
                    ++secondIndex;
                }
                else if (sum > 0)
                {
                    --thirdIndex;
                }
                else
                {
                    auto triplet = std::vector<int>{ firstValue, secondValue, thirdValue };
                    triplets.emplace_back(triplet);
                    ++secondIndex;
                    --thirdIndex;
                    while (secondIndex < thirdIndex && nums[secondIndex] == secondValue)
                    {
                        ++secondIndex;
                    }
                    while (secondIndex < thirdIndex && nums[thirdIndex] == thirdValue)
                    {
                        --thirdIndex;
                    }
                }
            }
            ++i;
            while (i < numsSize && nums[i] == firstValue)
            {
                ++i;
            }
        }

        return triplets;
    }
};