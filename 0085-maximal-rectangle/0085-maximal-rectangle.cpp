class Solution {
public:
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        for(int i = n-1; i >= 0; i--)
        {
            for(int j = m-1; j >= 0; j--)
            {
                if(matrix[i][j] == '1')
                    dp[i][j] = dp[i][j+1] + 1;
                else
                    dp[i][j] = 0;
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int col = m;
                for(int k = i; k < n; k++)
                {
                    col = min(col, dp[k][j]);
                    ans = max(ans, (k - i + 1) * col);
                }
            }
        }
        return ans;
    }
};
    
//     Time Complexity - O(MN * MN);
//     Space Complexity - O(1);
    
//     Runtime: 1569 ms, faster than 5.01% of C++ online submissions for Maximal Rectangle.
// Memory Usage: 12.2 MB, less than 99.92% of C++ online submissions for Maximal Rectangle.
    
//     int maximalRectangle(vector<vector<char>>& matrix) {
//         int n = matrix.size(), m = matrix[0].size();
//         int ans = 0;
//         for(int i = 0; i < n; i++)
//         {
//             for(int j = 0; j < m; j++)
//             {
//                 int row = 1, col = m;
//                 for(int k = i; k < n && matrix[k][j] == '1'; k++)
//                 {
//                     int count = j;
//                     for(int l = j; l < col && matrix[k][l] == '1'; l++)
//                     {
//                         count++;
//                     }
//                     // if(i == 1 && j == 2)
//                     //     cout << k << " " << count << endl;
//                     col = min(col, count);
//                     ans = max(ans, (k - i + 1) * (col - j));
//                 }
//                 // cout << i << " " << j << " " << " " << col << endl;
//             }
//         }
//         return ans;
//     }
// };