class Solution {
public:
    
    int search(vector<vector<int>> &events, int target)
    {
        int left = 0, right = events.size()-1;
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(events[mid][0] <= target)
                left = mid + 1;
            else 
                right = mid - 1;
        }
        return left;
    }
    
    int maximum(int i, int k, int maxi, vector<vector<int>> &events, vector<vector<int>> &dp)
    {
        int n = events.size();
        if(i >= n || k <= 0)
            return 0;
        
        if(dp[i][k] != -1)
            return dp[i][k];

        int idx = search(events, events[i][1]);       
        
        return dp[i][k] = max(maximum(i+1, k, maxi, events, dp), events[i][2] + maximum(idx, k-1, events[i][1], events, dp)); 
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end());
        vector<vector<int>> dp(n, vector<int> (k+1, -1));
        
        return maximum(0, k, 0, events, dp);
    }
};