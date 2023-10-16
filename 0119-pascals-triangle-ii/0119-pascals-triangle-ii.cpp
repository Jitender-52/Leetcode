class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev;
        prev.push_back(1);
        for(int i = 0; i < rowIndex; i++)
        {
            vector<int> curr;
            curr.push_back(1);
            for(int i = 0; i < prev.size()-1; i++)
            {
                curr.push_back(prev[i] + prev[i+1]);
            }
            curr.push_back(1);
            prev = curr;
        }
        return prev;
    }
};