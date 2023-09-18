class Solution {
public:
    int countGoodSubstrings(string s) {
        if (s.length() < 3)
        {
            return 0;
        }

        auto counter{ 0 };
        auto charOccurrence = std::unordered_map<char, int>();
        auto leftIterator = std::size_t{ 0 };

        for (std::size_t rightIterator = 0; rightIterator < s.length(); ++rightIterator)
        {
            ++charOccurrence[s[rightIterator]];

            if (rightIterator >= 3)
            {
                --charOccurrence[s[leftIterator]];
                if (charOccurrence[s[leftIterator]] == 0)
                {
                    charOccurrence.erase(s[leftIterator]);
                }
                ++leftIterator;
            }

            if (charOccurrence.size() == 3)
            {
                ++counter;
            }
        }

        return counter;
    }
};