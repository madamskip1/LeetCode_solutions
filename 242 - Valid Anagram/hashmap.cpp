class Solution {
public:
    bool isAnagram(string s, string t) {
        auto charOccurrence = std::unordered_map<char, int>{};
        for (auto& c : s)
        {
            ++charOccurrence[c];
        }
        for (auto& c : t)
        {
            --charOccurrence[c];
        }

        for (auto& [key, val] : charOccurrence)
        {
            if (val != 0) return false;
        }

        return true;
    }
};