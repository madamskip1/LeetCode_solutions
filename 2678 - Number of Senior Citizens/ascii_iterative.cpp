class Solution {
public:
    int countSeniors(vector<string>& details) {
        auto answer{ 0 };

        for (const auto& citizen : details)
        {
            auto firstDigit = citizen[11];
            if (firstDigit >= '6')
            {
                auto secondDigit = citizen[12];
                if (firstDigit >= '7' || secondDigit > '0')
                    ++answer;
            }
        }

        return answer;
    }
};