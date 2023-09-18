class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        auto DP = std::vector<bool>(s.length(), false);
        DP[0] = true;

        for (std::size_t i = 1; i <= s.length(); ++i)
        {
            for (std::size_t j = 1; j <= i; ++j)
            {
                auto subStringIndex{ i - j };
                if (DP[subStringIndex])
                {
                    std::string subString = s.substr(subStringIndex, j);
                    if (std::any_of(wordDict.cbegin(), wordDict.cend(), [&subString](const auto& str) { return str == subString; }))
                    {
                        DP[i] = true;
                    }
                }


            }
        }
        return DP[s.length()];
    }
};