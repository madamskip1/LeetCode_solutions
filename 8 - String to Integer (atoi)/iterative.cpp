class Solution {
public:
    int myAtoi(string s) {
        auto negative{ false };
        auto startedNumber{ false };
        auto ans{ 0 };
        auto int_max_divided_10 = int(INT_MAX / 10);
        auto index = std::size_t{ 0 };

        while (s[index] == ' ')
        {
            ++index;
        }

        if (s[index] == '-')
        {
            negative = true;
            ++index;
        }
        else if (s[index] == '+')
        {
            ++index;
        }

        while (std::isdigit(s[index]))
        {
            int digit = s[index] - '0';

            if (ans != 0)
            {
                if (ans > int_max_divided_10)
                {
                    return (negative ? INT_MIN : INT_MAX);
                }
                ans *= 10;
            }
            if (ans > (INT_MAX - digit))
            {
                return (negative ? INT_MIN : INT_MAX);
            }

            ans += digit;
            ++index;
        }

        if (negative)
        {
            ans *= -1;
        }

        return int(ans);
    }
};