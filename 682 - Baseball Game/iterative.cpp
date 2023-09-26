class Solution {
public:
    int calPoints(vector<string>& operations) {
        auto records = std::vector<int>{};

        for (const auto& operation : operations)
        {
            if (operation[0] == '+')
            {
                records.push_back(records[records.size() - 1] + records[records.size() - 2]);
            }
            else if (operation[0] == 'D')
            {
                records.push_back(records[records.size() - 1] * 2);
            }
            else if (operation[0] == 'C')
            {
                records.pop_back();
            }
            else
            {
                records.emplace_back(std::stoi(operation));
            }
        }

        return std::accumulate(records.cbegin(), records.cend(), 0);
    }
};