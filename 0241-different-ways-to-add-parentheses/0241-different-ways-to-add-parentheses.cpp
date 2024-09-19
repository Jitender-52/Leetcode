class Solution {
public:
    vector<int> diffWaysToCompute(string expression)
    {
        vector<int> ans;
        if (expression.length() == 0)
            return ans;
        if (expression.length() == 1)
        {
            ans.push_back(stoi(expression));
            return ans;
        }
        if (expression.length() == 2 && isdigit(expression[0]))
        {
            ans.push_back(stoi(expression));
            return ans;
        }
        for (int i = 0; i < expression.length(); i++)
        {
            char currentChar = expression[i];
            if (isdigit(currentChar))
                continue;
            vector<int> left = diffWaysToCompute(expression.substr(0, i));
            vector<int> right = diffWaysToCompute(expression.substr(i + 1));
            for (int leftValue : left)
            {
                for (auto i : right)
                {
                    int count = 0;
                    switch (currentChar)
                    {
                    case '+':
                        count = leftValue + i;
                        break;
                    case '-':
                        count = leftValue - i;
                        break;
                    case '*':
                        count = leftValue * i;
                        break;
                    }

                    ans.push_back(count);
                }
            }
        }
        return ans;
    }
};