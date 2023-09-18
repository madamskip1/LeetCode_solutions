class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        auto sum{ 3 }
        auto minus2{ 1 };
        auto minus1{ 2 };

        for (int i = 3; i <= n; ++i)
        {
            sum = minus2 + minus1;
            minus2 = minus1;
            minus1 = sum;
        }

        return sum;
    }
};