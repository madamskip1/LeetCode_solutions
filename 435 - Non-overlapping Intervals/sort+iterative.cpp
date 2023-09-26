class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](auto& a, auto& b)
            {
                return a[0] < b[0];
            });

        auto removedCounter{ 0 };
        auto lastEnd{ intervals[0][1] };
        for (std::size_t i = 1; i < intervals.size(); ++i)
        {
            if (intervals[i][0] < lastEnd)
            {
                ++removedCounter;
                lastEnd = std::min(lastEnd, intervals[i][1]);
            }
            else
            {
                lastEnd = intervals[i][1];
            }
        }

        return removedCounter;
    }
};