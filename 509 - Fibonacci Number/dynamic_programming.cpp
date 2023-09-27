class Solution {
public:
    int fib(int n) {
        if (n <= 1)
        {
            return n;
        }

        auto DP = std::vector<int>(n + 1, 0);
        DP[0] = 0;
        DP[1] = 1;

        for (std::size_t i = 2; i <= n; ++i)
        {
            DP[i] = DP[i - 1] + DP[i - 2];
        }

        return DP[n];
    }
};