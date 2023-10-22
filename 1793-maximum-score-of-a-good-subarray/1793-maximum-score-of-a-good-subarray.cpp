class Solution {
public:
    
    int solve(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> left(k);
        int mini = INT_MAX;
        for(int i = k-1; i >= 0; i--)
        {
            mini = min(mini, nums[i]);
            left[i] = mini;
        }
        
        vector<int> right;
        mini = INT_MAX;
        for(int i = k; i < n; i++)
        {
            mini = min(mini, nums[i]);
            // right.push_back(nums[i]); mybad here got 1 WA
            right.push_back(mini);
        }
        
        int ans = 0;
        for(int i = 0; i < right.size(); i++)
        {
            int j = lower_bound(left.begin(), left.end(), right[i]) - left.begin();
            ans = max(ans, right[i] * ((i + k) - j + 1));
        }
        return ans;
    }
    
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();   
        int ans = solve(nums, k);
        reverse(nums.begin(), nums.end());
        ans = max(ans, solve(nums, n - k - 1));
        return ans;
    }
};