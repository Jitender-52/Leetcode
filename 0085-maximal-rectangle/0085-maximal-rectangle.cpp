class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int row = 1, col = m;
                for(int k = i; k < n && matrix[k][j] == '1'; k++)
                {
                    int count = j;
                    for(int l = j; l < col && matrix[k][l] == '1'; l++)
                    {
                        count++;
                    }
                    // if(i == 1 && j == 2)
                    //     cout << k << " " << count << endl;
                    col = min(col, count);
                    ans = max(ans, (k - i + 1) * (col - j));
                }
                // cout << i << " " << j << " " << " " << col << endl;
            }
        }
        return ans;
    }
};