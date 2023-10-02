class Solution {
public:
    vector<string> fizzBuzz(int n) {
        auto ans = std::vector<std::string>{};
        ans.reserve(n);

        for (std::size_t i = 1; i <= n; ++i)
        {
            auto divisble3 = i % 3 == 0;
            auto divisble5 = i % 5 == 0;

            if (divisble3)
            {
                if (divisble5)
                {
                    ans.emplace_back("FizzBuzz");
                }
                else
                {
                    ans.emplace_back("Fizz");
                }
            }
            else if (divisble5)
            {
                ans.emplace_back("Buzz");
            }
            else
            {
                ans.emplace_back(std::to_string(i));
            }
        }
        return ans;
    }
};