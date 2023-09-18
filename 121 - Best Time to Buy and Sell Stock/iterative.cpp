class Solution {
public:
    int maxProfit(vector<int>& prices) {
        auto maxProfit{ 0 };
        auto minBought{ 10001 };
        for (auto& price : prices)
        {
            if (price < minBought)
            {
                minBought = price;
            }
            else
            {
                auto curProfit = price - minBought;
                if (curProfit > maxProfit)
                {
                    maxProfit = curProfit;
                }
            }
        }

        return maxProfit;
    }
};