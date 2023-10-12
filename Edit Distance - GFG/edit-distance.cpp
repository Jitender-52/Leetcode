//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    int solve(int i, int j, string s, string t, vector<vector<int>> &dp)
    {
        int n = s.length(), m = t.length();
        // cout << i << " " << j << endl;
        if(i >= n && j >= m)
            return 0;
        if(j >= m)
            return n - i;
        if(i >= n)
            return m - j;
            
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans = 1e9;
        if(s[i] == t[j])
            ans = min(ans, solve(i+1, j+1, s, t, dp));
        if(s[i] != t[j])
            ans = min({ans, 1 + solve(i+1, j, s, t, dp), 1 + solve(i, j+1, s, t, dp), 1 + solve(i+1, j+1, s, t, dp)});
        return dp[i][j] = ans;
    }
    
    int editDistance(string s, string t) {
        // Code here
        int n = s.length(), m = t.length();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return solve(0, 0, s, t, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends