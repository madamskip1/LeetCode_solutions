class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty())
        {
            return std::vector<std::vector<int>>(1, newInterval);
        }

        auto resultIntervals = std::vector<std::vector<int>>();
        auto intervalIndex = std::size_t{ 0 };
        auto intervalsSize = intervals.size();

        while (intervalIndex < intervalsSize)
        {
            if (intervals[intervalIndex][1] >= newInterval[0])
            {
                break;
            }

            resultIntervals.push_back(intervals[intervalIndex]);
            ++intervalIndex;
        }

        if (intervalIndex >= intervalsSize)
        {
            resultIntervals.push_back(newInterval);
            return resultIntervals;
        }

        newInterval[0] = std::min(newInterval[0], intervals[intervalIndex][0]);

        while (intervalIndex < intervalsSize)
        {
            if (intervals[intervalIndex][0] > newInterval[1])
            {

                break;
            }

            newInterval[1] = std::max(newInterval[1], intervals[intervalIndex][1]);
            ++intervalIndex;
        }

        resultIntervals.push_back(newInterval);

        while (intervalIndex < intervalsSize)
        {
            resultIntervals.push_back(intervals[intervalIndex]);
            ++intervalIndex;
        }

        return resultIntervals;
    }
};