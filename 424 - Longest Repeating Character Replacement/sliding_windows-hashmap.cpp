class Solution {
public:
    int characterReplacement(string s, int k) {
        auto ans{ 0 };
        auto charCounter = std::unordered_map<char, int>();
        auto mostFrequentCharCounter{ 0 };
        auto left{ 0 };
        auto stringSize = s.length();

        for (auto right = 0; right < stringSize; ++right)
        {
            char c = s[right];
            ++charCounter[c];
            mostFrequentCharCounter = std::max(mostFrequentCharCounter, charCounter[c]);
            auto windowSize = right - left + 1;

            if (windowSize - mostFrequentCharCounter > k)
            {
                char leftC = s[left];
                --charCounter[leftC];
                ++left;
                --windowSize;
            }
            ans = std::max(windowSize, ans);
        }
        return ans;
    }
};