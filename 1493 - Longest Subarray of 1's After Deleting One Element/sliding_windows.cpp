class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        auto count1{ 0 };
        auto count0{ 0 };
        auto result{ 0 };
        auto leftIterator = std::size_t{ 0 };

        for (std::size_t rightIterator = 0; rightIterator < nums.size(); ++rightIterator)
        {
            if (nums[rightIterator] == 1)
            {
                ++count1;
            }
            else
            {
                ++count0;
            }

            while (count0 > 1)
            {
                if (nums[leftIterator] == 1)
                {
                    --count1;
                }
                else
                {
                    --count0;
                }

                ++leftIterator;
            }

            if (count1 > 0)
            {
                auto currentLength = static_cast<int>(rightIterator - leftIterator);
                result = std::max(result, currentLength);
            }
        }

        return result;
    }
};