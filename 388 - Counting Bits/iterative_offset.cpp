class Solution {
public:
    vector<int> countBits(int n) {
        auto ans = std::vector<int>();
        ans.reserve(n + 1);
        ans.emplace_back(0);

        auto offset{ 1 };

        for (int i = 1; i <= n; ++i)
        {
            if (offset * 2 <= i)
            {
                offset *= 2;
            }

            ans.emplace_back(1 + ans[i - offset]);
        }

        return ans;
    }
};