class Solution {
public:
    
    double largest(int i, int last, int k, vector<double> prefix, vector<int> &nums, vector<vector<vector<double>>> &dp)
    {
        int n = nums.size();
        if(i == n && k == 0)
            return 0;
        if(k == 0 || i >= n) // mybad was taking k < 0 instead of k == 0;
            return INT_MIN; 
        if(dp[i][last][k] != -1)
            return dp[i][last][k];
        
        return dp[i][last][k] = max(largest(i+1, last, k, prefix, nums, dp), (prefix[i] - prefix[last] + nums[last]) / ((double)(i-last+1)) + largest(i+1, i+1, k-1, prefix, nums, dp));
    }
    
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<vector<double>>> dp(n+1, vector<vector<double>> (n+1, vector<double> (k+1, -1)));
        vector<double> prefix(n, 0);
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++)
            prefix[i] = prefix[i-1] + nums[i];
        return largest(0, 0, k, prefix, nums, dp);
    }
};