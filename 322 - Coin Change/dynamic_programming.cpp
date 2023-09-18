class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        auto DP = std::vector<int>(amount + 1, INT_MAX);
        DP[0] = 0;
        for (auto i = 1; i <= amount; ++i)
        {
            for (auto& coin : coins)
            {
                auto prevIndex = i - coin;
                if (prevIndex >= 0)
                {
                    auto prevValue = DP[prevIndex];
                    if (prevValue != INT_MAX)
                    {
                        auto newValue = prevValue + 1;
                        DP[i] = std::min(DP[i], newValue);
                    }
                }
            }
        }
        auto ans{ DP[amount] };
        return (ans == INT_MAX ? -1 : ans);
    }
};