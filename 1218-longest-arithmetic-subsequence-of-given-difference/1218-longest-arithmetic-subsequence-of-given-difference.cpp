class Solution {
public:
    
//     int sequence(int i, int last, vector<int> &arr, int difference, vector<int> &dp)
//     {
//         int n = arr.size();
//         if(i >= n)
//             return 0;
        
//         if(dp[i] != -1)
//             return dp[i];
        
//         if(last == 1e9)
//         {
//             return dp[i] = max(1 + sequence(i+1, arr[i], arr, difference, dp), sequence(i+1, last, arr, difference, dp));
//         }
//         if(arr[i] - last == difference)
//             return dp[i] = 1 + sequence(i+1, arr[i], arr, difference, dp);
//         return dp[i] = sequence(i+1, last, arr, difference, dp);
//     }
    
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        // vector<int> dp(n, -1);
        // return sequence(0, 1e9, arr, difference, dp);
        
        map<int,int> mp;
        for(int i = n-1; i >= 0; i--)
        {
            mp[arr[i]] = mp[arr[i] + difference] + 1;
        }
        
        int ans = 0;
        for(auto i : mp)
            ans = max(ans, i.second);
        return ans;
    }
};