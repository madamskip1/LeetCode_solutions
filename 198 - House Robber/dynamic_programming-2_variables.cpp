class Solution {
public:
	int rob(vector<int>& nums) {
		auto DP_minus_2{ 0 };
		auto DP_minus_1{ nums[0] };

		for (std::size_t i = 2; i <= nums.size(); ++i)
		{
			auto temp = std::max(DP_minus_1, DP_minus_2 + nums[i - 1]);
			DP_minus_2 = DP_minus_1;
			DP_minus_1 = temp;
		}
		return DP_minus_1;
	}
};