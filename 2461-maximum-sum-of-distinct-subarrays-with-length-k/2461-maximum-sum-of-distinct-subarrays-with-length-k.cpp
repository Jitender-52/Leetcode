class Solution {
public:
    
//     Runtime: 237 ms, faster than 15.96% of C++ online submissions for Maximum Sum of Distinct Subarrays With Length K.
// Memory Usage: 104.2 MB, less than 13.76% of C++ online submissions for Maximum Sum of Distinct Subarrays With Length K.
    
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> mp;
        long long sum = 0;
        for(int i = 0; i < k; i++)
        {
            mp[nums[i]]++;
            sum += nums[i];
        }
        
        long long ans = 0;
        int j = 0;
        for(int i = k; i < n; i++)
        {
            if(mp.size() == k)
            {
                ans = max(ans, sum);
            }
            mp[nums[j]]--;
            mp[nums[i]]++;
            if(mp[nums[j]] == 0)
            {
                mp.erase(nums[j]);
            }
            sum += nums[i];
            sum -= nums[j];
                  j++;
        }
         if(mp.size() == k)
            {
                ans = max(ans, sum);
            }
        
        return ans;
    }
};

