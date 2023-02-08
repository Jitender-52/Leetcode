class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        
       int ans = 0;
        
        int curr = 0;
        int maxi = 0;
        for(int i = 0; i < n-1; i++)
        {
            maxi = max(maxi, nums[i]+i);
            if(i == curr)
            {
                curr = maxi;
                ans++;
            }
        }
        return ans;
        
//         vector<int> v(n+1, 1e6);
//         v[n-1] = 0;
        
//         for(int  i = n-2; i >= 0; i--)
//         {
//             v[i] = min(v[i], v[i+1] + 1);
//             if(i + nums[i] < n)
//                 v[i] = min(v[i+nums[i]] + 1, v[i]);
//             else
//                 v[i] = 1;
//         }
//         return v[0];   
    }
};