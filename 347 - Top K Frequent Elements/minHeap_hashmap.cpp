class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        auto numbersOccurrence = std::unordered_map<int, int>{};
        for (auto& num : nums)
        {
            ++numbersOccurrence[num];
        }
        auto comparator = [](const auto& pair1, const auto& pair2) {
            return pair1.second < pair2.second;
        };
        auto minHeap = std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(comparator)>(comparator);

        for (const auto& keyValuePair : numbersOccurrence)
        {
            minHeap.push(keyValuePair);
        }

        auto answer = std::vector<int>();
        answer.reserve(k);

        while (k-- > 0 && !minHeap.empty())
        {
            answer.push_back(minHeap.top().first);
            minHeap.pop();
        }

        return answer;
    }
};