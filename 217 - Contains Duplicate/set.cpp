class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        auto numbersSet = std::unordered_set<int>{};
        for (auto& num : nums)
        {
            if (numbersSet.contains(num))
            {
                return true;
            }
            else
            {
                numbersSet.emplace(num);
            }
        }
        return false;
    }
};