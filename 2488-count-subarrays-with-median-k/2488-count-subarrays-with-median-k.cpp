class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> mp;
        bool check = false;
        int ans = 0;
        int count = 0;
        mp[0]++;
        
        for(int i = 0; i < n; i++)
        {
            if(nums[i] > k)
            {
                count++;
            }
            else if(nums[i] < k)
            {
                count--;
            }
            else
            {
                check = true;
            }
            
            if(check)
            {
                ans += mp[count] + mp[count-1];
            }
            else
            {
                mp[count]++;
            }
        }
        return ans;
    }
};