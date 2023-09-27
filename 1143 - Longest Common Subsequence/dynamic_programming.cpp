class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        auto DP = std::vector<std::vector<int>>(text1.length() + 1, std::vector<int>(text2.length() + 1, 0));
        for (std::size_t x = 1; x <= text1.length(); ++x)
        {
            for (std::size_t y = 1; y <= text2.length(); ++y)
            {
                if (text1[x - 1] == text2[y - 1])
                {
                    DP[x][y] = 1 + DP[x - 1][y - 1];
                }
                else
                {
                    DP[x][y] = std::max(DP[x][y - 1], DP[x - 1][y]);
                }
            }
        }
        return DP[text1.length()][text2.length()];
    }
};