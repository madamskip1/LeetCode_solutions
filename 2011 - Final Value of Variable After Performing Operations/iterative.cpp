class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        auto ans{ 0 };

        for (const auto& operation : operations)
        {
            if (operation[1] == '+')
            {
                ++ans;
            }
            else
            {
                --ans;
            }
        }

        return ans;
    }
};