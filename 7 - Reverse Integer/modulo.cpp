class Solution {
public:
    int reverse(int x) {
        auto ans{ 0 };
        auto int_max_divided_10 = int(INT_MAX / 10);
        auto int_min_divided_10 = int(INT_MIN / 10);

        while (x != 0)
        {
            if (ans > int_max_divided_10 ||
                ans < int_min_divided_10)
            {
                return 0;
            }

            ans *= 10;
            ans += x % 10;
            x /= 10;
        }

        return ans;
    }
};