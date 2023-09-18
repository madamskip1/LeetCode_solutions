class Solution {
public:
    int maxProduct(vector<int>& nums) {
        auto max{ INT_MIN };
        auto positiveProduct{ 1 };
        auto negativeProduct{ 1 };

        for (auto& num : nums)
        {
            if (num == 0)
            {
                max = std::max(max, 0);
                positiveProduct = 1;
                negativeProduct = 1;
            }
            else
            {
                if (num < 0)
                {
                    std::swap(positiveProduct, negativeProduct);
                }
                positiveProduct = std::max(positiveProduct * num, num);
                negativeProduct = std::min(negativeProduct * num, num);

                max = std::max(positiveProduct, max);
            }
        }
        return max;
    }
};