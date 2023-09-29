class Solution {
public:
    vector<int> minOperations(string boxes) {
        auto ans = std::vector<int>(boxes.length(), 0);
        auto leftSum{ 0 };
        auto leftBalls{ 0 };
        for (std::size_t i = 1; i < boxes.length(); ++i)
        {
            if (boxes[i - 1] == '1')
            {
                ++leftBalls;
            }
            leftSum += leftBalls;
            ans[i] = leftSum;
        }

        auto rightSum{ 0 };
        auto rightBalls{ 0 };

        for (int i = boxes.length() - 2; i >= 0; --i)
        {
            if (boxes[i + 1] == '1')
            {
                ++rightBalls;
            }
            rightSum += rightBalls;
            ans[i] += rightSum;
        }

        return ans;
    }
};