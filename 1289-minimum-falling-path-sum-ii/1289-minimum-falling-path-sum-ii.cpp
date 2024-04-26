class Solution {
public:
    
//     Runtime: 247 ms, faster than 43.86% of C++ online submissions for Minimum Falling Path Sum II.
// Memory Usage: 18.3 MB, less than 16.18% of C++ online submissions for Minimum Falling Path Sum II.

    
//     Try To Solve Tabulation method once again

    
    int pathSum(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        int n = grid.size();
        
        if(i >= n)
            return 0;
        
        if(j != -1 && dp[i][j] != -1)
            return dp[i][j];
           
        int ans = INT_MAX;
        for(int k = 0; k < n; k++)
        {
            if(k == j)
                continue;
            ans = min(ans, grid[i][k] + pathSum(i+1, k, grid, dp));
        }

        if(j != -1)
           return dp[i][j] = ans;
        return ans;
    }
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        
        int last = -1;
        for(int i = n-1; i >= 0; i--)
        {
            for(int j = n-1; j >= 0; j--)
            {
                int ans = INT_MAX;
                for(int k = 0; k < n; k++)
                {
                    if(i < n-1 && k == j)
                        continue;
                    ans = min(ans, dp[i+1][k] + grid[i][j]);
                }
                dp[i][j] = ans;
            }
        }
        
        int ans = INT_MAX;
        for(int j = 0; j < n; j++)
        {
            ans = min(ans, dp[0][j]);
        }
        return ans;
    }
};
    
    
    
//     Runtime: 1989 ms, faster than 15.32% of C++ online submissions for Minimum Falling Path Sum II.
// Memory Usage: 15.9 MB, less than 41.81% of C++ online submissions for Minimum Falling Path Sum II.
    
//     Recursive + Memoisation Solution
    
//        int pathSum(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
//     {
//         int n = grid.size();
        
//         if(i >= n)
//             return 0;
        
//         if(j != -1 && dp[i][j] != -1)
//             return dp[i][j];
           
//         int ans = INT_MAX;
//         for(int k = 0; k < n; k++)
//         {
//             if(k == j)
//                 continue;
//             ans = min(ans, grid[i][k] + pathSum(i+1, k, grid, dp));
//         }

//         if(j != -1)
//            return dp[i][j] = ans;
//         return ans;
//     }
    
//     int minFallingPathSum(vector<vector<int>>& grid) {
//         int n = grid.size();
//         vector<vector<int>> dp(n, vector<int> (n, -1));
//         return pathSum(0, -1, grid, dp);
//     }
// };
    
    
//     Recursive Solution
    
//     int pathSum(int i, int j, vector<vector<int>> &grid)
//     {
//         int n = grid.size();
        
//         if(i >= n)
//             return 0;
        
//         int ans = INT_MAX;
//         for(int k = 0; k < n; k++)
//         {
//             if(k == j)
//                 continue;
//             ans = min(ans, grid[i][k] + pathSum(i+1, k, grid));
//         }

//         return ans;
//     }
    
//     int minFallingPathSum(vector<vector<int>>& grid) {
//         return pathSum(0,-1,grid);
//     }
// };