class Solution {
public:
    bool isValid(string s) {
        auto bracketStack = std::stack<char>{};

        for (auto& c : s)
        {
            if (c == '(' || c == '[' || c == '{')
            {
                bracketStack.push(c);
            }
            else
            {
                if (bracketStack.empty())
                {
                    return false;
                }

                auto& stackedChar = bracketStack.top();
                if (stackedChar == '(')
                {
                    if (c != ')')
                    {
                        return false;
                    }
                }
                else if (stackedChar == '[')
                {
                    if (c != ']')
                    {
                        return false;
                    }
                }
                else if (stackedChar == '{')
                {
                    if (c != '}')
                    {
                        return false;
                    }
                }
                bracketStack.pop();
            }
        }

        if (!bracketStack.empty())
        {
            return false;
        }

        return true;
    }
};