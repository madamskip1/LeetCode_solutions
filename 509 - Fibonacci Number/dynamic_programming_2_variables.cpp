class Solution {
public:
    int fib(int n) {
        if (n <= 1)
        {
            return n;
        }
        auto DP_minus_2{ 0 };
        auto DP_minus_1{ 1 };

        for (auto i = 2; i <= n; ++i)
        {
            auto nextValue = DP_minus_2 + DP_minus_1;
            DP_minus_2 = DP_minus_1;
            DP_minus_1 = nextValue;
        }

        return DP_minus_1;
    }
};