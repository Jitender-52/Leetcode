class Solution {
public:
    
    short dp[2001][2001][2] = {}, max_val = 2002;
short dfs(vector<int>& t, vector<int>& s, int i, int j, bool prev_t) {
    if (i >= t.size()) 
      return 0;
    int prev = prev_t ? i == 0 ? INT_MIN : t[i - 1] : s[j];
    j = upper_bound(begin(s) + j, end(s), prev) - begin(s);
    if (dp[i][j][prev_t] == 0) {
        dp[i][j][prev_t] = max_val;
        if (j < s.size())
            dp[i][j][prev_t] = dfs(t, s, i + 1, j, false) + 1;
        if (prev < t[i])
            dp[i][j][prev_t] = min(dp[i][j][prev_t], dfs(t, s, i + 1, j, true));
    }
    return dp[i][j][prev_t];
}
int makeArrayIncreasing(vector<int>& t, vector<int>& s) {
  sort(begin(s), end(s));
  auto res = dfs(t, s, 0, 0, true);
  return res >= max_val ? -1 : res;
}
};
    
    
    
//     int make(int i, int j, vector<int> arr1, vector<int> arr2, vector<vector<int>> &dp)
//     {
//         int n = arr1.size();
//         int m = arr2.size();
//         // cout << i <<" " << j << endl;
//         for(int i = 0; i < n; i++)
//         {
//             cout << arr1[i] << " ";
//         }
//         cout << endl;
//         if(i >= n)
//         {
//             cout << "HII" << endl;
//             return 0;
//         }
//         if(j > m)
//             return 1e6;
        
//         int ans = 1e6;
//         // cout << i << " " << j << endl;
        
//         // ans = min(ans, make(i, j+1, arr1, arr2, dp));   
//         if((i == 0 || arr1[i] > arr1[i-1]) && (i == n-1 || arr1[i] < arr1[i+1]))
//         {
//             ans = min(ans, make(i+1, j, arr1, arr2, dp));
//         }
//         if((j < m) && (i == 0 || arr2[j] > arr1[i-1]) && (i == n-1 || arr2[j] < arr1[i+1]))
//         {
//             arr1[i] = arr2[j];
//             ans = min(ans, 1 + make(i+1, j+1, arr1, arr2, dp));
//         }
//         // cout << "ans = " << ans << endl;
//         if(ans == 1e6)
//             cout << i << " " << j << endl;
//         return ans;
//     }
    
//     int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
//         int n = arr1.size();
//         int m = arr2.size();
//         sort(arr2.begin(), arr2.end());
        
//         vector<vector<int>> dp(n, vector<int> (m, -1));
        
//         int ans = make(0, 0, arr1, arr2, dp);
//         return ans >= 1e6 ? -1 : ans;
//     }
// };