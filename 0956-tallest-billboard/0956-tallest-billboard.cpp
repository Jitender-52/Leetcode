class Solution {
public:
    
    // int tallest(int i, int count, int sum, vector<int> &nums)
    // {
    //     cout << count << " " << sum << endl;
    //     int n = nums.size();
    //     if(i >= n)
    //         return 1e9;
    //     if(sum == count)
    //         return sum;
    //     return min(tallest(i+1, count, sum, nums), tallest(i+1, count+nums[i], sum -nums[i], nums));
    // }
    
    int tallest(int i, int diff, vector<int> &rods, vector<vector<int>> &dp)
    {
        int n = rods.size();
        if(i == n)
        {
            if(diff == 0)
            {
                return 0;
            }
            return -1e6;
        }
        if(dp[i][diff+5000] != -1)
            return dp[i][diff+5000];
        
        return dp[i][diff + 5000] = max({rods[i] + tallest(i+1, diff + rods[i], rods, dp), tallest(i+1, diff, rods, dp), tallest(i+1, diff-rods[i], rods, dp)});
    }
    
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        vector<vector<int>> dp(n, vector<int> (1e4+1, -1));
        return tallest(0, 0, rods, dp);
    }
};