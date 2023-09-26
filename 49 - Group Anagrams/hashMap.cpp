class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        auto wordsMap = std::unordered_map<string, std::vector<std::string>>{};
        for (const auto& str : strs)
        {
            auto sorted = str;
            std::sort(sorted.begin(), sorted.end());
            wordsMap[sorted].push_back(str);
        }

        auto grouped = std::vector<std::vector<std::string>>{};
        grouped.reserve(wordsMap.size());
        for (const auto& [key, group] : wordsMap)
        {
            grouped.push_back(group);
        }

        return grouped;
    }
};