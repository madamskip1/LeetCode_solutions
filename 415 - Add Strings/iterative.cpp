class Solution {
public:
    string addStrings(string num1, string num2) {
        auto ans = std::string{};
        auto i = int(num1.length()) - 1;
        auto j = int(num2.length()) - 1;
        auto over{ 0 };
        while (i >= 0 && j >= 0)
        {
            auto sum = int(num1[i] - '0') + int(num2[j] - '0');
            sum += over;
            ans.push_back((sum % 10) + '0');
            if (sum >= 10)
            {
                over = 1;
            }
            else
            {
                over = 0;
            }
            --i;
            --j;
        }

        while (i >= 0)
        {
            int sum = num1[i] - '0';
            sum += over;
            ans.push_back((sum % 10) + '0');
            if (sum >= 10)
            {
                over = 1;
            }
            else
            {
                over = 0;
            }
            --i;
        }

        while (j >= 0)
        {
            int sum = num2[j] - '0';
            sum += over;
            ans.push_back((sum % 10) + '0');
            if (sum >= 10)
            {
                over = 1;
            }
            else
            {
                over = 0;
            }
            --j;
        }

        if (over)
        {
            ans.push_back('1');
        }

        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};