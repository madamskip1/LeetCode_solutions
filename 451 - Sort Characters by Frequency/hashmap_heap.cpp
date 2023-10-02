class Solution {
public:
    string frequencySort(string s) {
        auto frequency = std::unordered_map<char, int>{};
        for (const auto& c : s)
        {
            ++frequency[c];
        }

        auto comparator = [](const auto& a, const auto& b)
            {
                return a.second < b.second;
            };
        auto sorted = std::priority_queue<std::pair<char, int>, std::vector<std::pair<char, int>>, decltype(comparator)>{ comparator };


        for (const auto& pairCharFrequency : frequency)
        {
            sorted.push(pairCharFrequency);
        }

        auto answer = std::string{};
        answer.reserve(s.length());
        while (!sorted.empty())
        {
            auto pairCharFrequency = sorted.top();
            sorted.pop();
            while (pairCharFrequency.second)
            {
                answer.push_back(pairCharFrequency.first);
                --pairCharFrequency.second;
            }
        }
        return answer;
    }
};