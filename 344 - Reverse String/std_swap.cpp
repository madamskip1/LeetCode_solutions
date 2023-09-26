class Solution {
public:
    void reverseString(vector<char>& s) {
        auto leftIterator = std::size_t{ 0 };
        auto rightIterator = s.size() - 1;
        while (leftIterator < rightIterator)
        {
            std::swap(s[leftIterator], s[rightIterator]);
            ++leftIterator;
            --rightIterator;
        }
    }
};