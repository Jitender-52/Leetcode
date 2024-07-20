class Solution {
public:
    
//     Runtime: 35 ms, faster than 73.82% of C++ online submissions for Find Valid Matrix Given Row and Column Sums.
// Memory Usage: 36.1 MB, less than 11.51% of C++ online submissions for Find Valid Matrix Given Row and Column Sums.
    
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size(), m = colSum.size();
        vector<vector<int>> ans(n, vector<int> (m, 0));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                ans[i][j] += min(rowSum[i], colSum[j]);
                rowSum[i] -= ans[i][j];
                colSum[j] -= ans[i][j];
            }
        }
        return ans;
    }
};