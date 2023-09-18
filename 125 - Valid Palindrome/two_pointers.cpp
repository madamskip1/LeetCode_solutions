class Solution {
public:
    bool isPalindrome(string s) {
        auto leftIndex = std::size_t{ 0 };
        auto rightIndex = s.length();

        while (leftIndex < rightIndex)
        {
            if (!isalnum(s[leftIndex]))
            {
                ++leftIndex;
            }
            else if (!isalnum(s[rightIndex]))
            {
                --rightIndex;
            }
            else if (tolower(s[leftIndex]) != tolower(s[rightIndex]))
            {
                return false;
            }
            else
            {
                ++leftIndex;
                --rightIndex;
            }
        }
        return true;
    }
};