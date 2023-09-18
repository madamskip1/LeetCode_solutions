class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        auto countT{ 0 };
        auto countF{ 0 };
        auto result{ 0 };
        auto leftIterator = std::size_t{ 0 };

        for (std::size_t rightIterator = 0; rightIterator < answerKey.length(); ++rightIterator)
        {
            if (answerKey[rightIterator] == 'T')
            {
                ++countT;
            }
            else
            {
                ++countF;
            }

            while (countF > k && countT > k)
            {
                if (answerKey[leftIterator] == 'T')
                {
                    --countT;
                }
                else
                {
                    --countF;
                }
                ++leftIterator;
            }

            result = std::max(result, static_cast<int>(rightIterator - leftIterator + 1));
        }

        return result;
    }
};