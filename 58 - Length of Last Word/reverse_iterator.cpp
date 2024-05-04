class Solution {
public:
    int lengthOfLastWord(string s) {
        auto length {0};
        for (auto iterator = s.crbegin(); iterator != s.crend(); ++iterator)
        {
            if (*iterator != ' ')
            {
                ++length;
            }
            else if (length != 0)
            {
                break;
            }
        }

        return length;
    }
};