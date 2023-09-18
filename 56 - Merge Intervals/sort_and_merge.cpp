class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto merged = std::vector<std::vector<int>>();

        std::sort(intervals.begin(), intervals.end(), [](auto& a, auto& b)
            {
                return a[0] < b[0];
            });

        merged.push_back(intervals[0]);

        for (std::size_t i = 1; i < intervals.size(); ++i)
        {
            auto lastIntervalEnd = merged[merged.size() - 1][1];
            if (lastIntervalEnd >= intervals[i][0])
            {
                merged[merged.size() - 1][1] = std::max(lastIntervalEnd, intervals[i][1]);
            }
            else
            {
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};