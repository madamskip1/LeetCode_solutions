class Solution {
public:
    int maxArea(vector<int>& height) {
        auto maxArea{ INT_MIN };
        auto leftIndex{ 0 };
        auto rightIndex = int(height.size() - 1);
        while (leftIndex < rightIndex)
        {
            auto leftValue = height[leftIndex];
            auto rightValue = height[rightIndex];
            auto yLength = std::min(leftValue, rightValue);
            auto xLength = rightIndex - leftIndex;
            auto area = xLength * yLength;
            maxArea = std::max(maxArea, area);

            if (leftValue < rightValue)
            {
                ++leftIndex;
            }
            else if (leftValue > rightValue)
            {
                --rightIndex;
            }
            else
            {
                ++leftIndex;
                --rightIndex;
            }
        }

        return maxArea;
    }
};