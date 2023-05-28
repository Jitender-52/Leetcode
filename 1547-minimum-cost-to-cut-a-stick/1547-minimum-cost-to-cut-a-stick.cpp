class Solution {
public:
    
    int minimum(int left, int right, vector<int> &cuts, vector<vector<int>> &dp)
    {
        if(right - left <= 1)
            return 0;
        if(dp[left][right] != -1)
            return dp[left][right];
        
        int ans = INT_MAX;
        for(int i = left+1; i < right; i++)
        {
            ans = min(ans, minimum(left, i, cuts, dp) + minimum(i, right, cuts, dp) + cuts[right] - cuts[left]);
        }
        return dp[left][right] = ans;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        int m = cuts.size();

        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(m+1, vector<int> (m+1, -1));
        return minimum(0, m-1, cuts, dp);
    }
};
    
//     int minimum(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
//     {
//         // cout << i << " " << j << endl;
//         int n = cuts.size();
//         if(i >= j)
//             return 0;
//         if(dp[i][j] != -1)
//             return dp[i][j];
        
//         int ans = 1e6;
//         for(int k = 0; k < n; k++)
//         {
//             if(cuts[k] > i && cuts[k] < j)
//             {
//                 // cout << cuts[k] << endl;
//                 ans = min(ans, j - i + minimum(i, cuts[k], cuts, dp) + minimum(cuts[k], j, cuts, dp));
//             }
//         }
//         if(ans >= 1e6)
//             return dp[i][j] = 0;
//         return dp[i][j] = ans;        
//     }
    
//     int minCost(int n, vector<int>& cuts) {
//         int m = cuts.size();
//         vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
//         return minimum(0, n, cuts, dp);
//     }
// };