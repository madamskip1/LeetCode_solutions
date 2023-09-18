class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int numsSize = nums.size();
        int sum = numsSize / 2.0 * (numsSize + 1);
        for (auto& num : nums)
        {
            sum -= num;
        }
        return sum;
    }
};