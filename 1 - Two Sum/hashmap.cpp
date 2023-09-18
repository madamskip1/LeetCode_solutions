class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        auto indices = std::unordered_map<int, int>{};
        auto size = nums.size();
        indices.insert({ nums[0], 0 });

        for (std::size_t i = 1; i < size; ++i)
        {
            auto val = nums[i];
            auto valDiff = target - val;
            if (indices.contains(valDiff))
            {
                auto secondKey = indices[valDiff];
                return { static_cast<int>(i), secondKey };
            }
            indices.insert({ val, i });
        }
        return {};
    }
};