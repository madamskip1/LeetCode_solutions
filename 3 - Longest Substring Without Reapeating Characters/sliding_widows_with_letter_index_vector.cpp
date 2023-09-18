class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        auto longest{ 0 };
        auto curLength{ 0 };
        auto startIndexSubstring{ 0 };
        const auto stringLength = s.size();
        auto letterIndex = std::vector<int>(256, -1);

        for (int i = 0; i < stringLength; ++i)
        {
            auto letter = s[i];
            auto index = letterIndex[letter];
            if (index >= startIndexSubstring)
            {
                longest = std::max(longest, curLength);
                curLength -= (index - startIndexSubstring + 1);
                startIndexSubstring = index + 1;
            }
            letterIndex[letter] = i;
            ++curLength;
        }
        return std::max(longest, curLength);
    }
};