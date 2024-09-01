class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(m * n != original.size())
            return {};
        vector<vector<int>> ans(m, vector<int> (n, 0));
        int i = 0, j = 0;
        for(auto it : original)
        {
            ans[i][j] = it;
            j++;
            if(j == n)
            {
                i++;
                j = 0;
            }
        }
        return ans;
    }
};