class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        auto subsets = std::vector<std::vector<int>>();
        subsets.push_back({});

        for (const auto& num : nums)
        {
            auto subsetsSizeBefore = subsets.size();
            for (std::size_t i = 0; i < subsetsSizeBefore; ++i)
            {
                subsets.push_back(subsets[i]);
                subsets[i].push_back(num);
            }
        }

        return subsets;
    }
};