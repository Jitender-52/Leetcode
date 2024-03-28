class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        int check = 0;
        map<int,int> mp;
        int ans = 0;
        while(j < n && i < n)
        {
            mp[nums[i]]++;
            if(mp[nums[i]] > k)
                check++;
            while(check > 0 && j <= i)
            {
                if(mp[nums[j]] == k+1)
                    check--;
                mp[nums[j]]--;
                j++;
            }
            // cout << i << " " << j << endl;
            ans = max(ans, i - j + 1);
            i++;
        }
        // cout << endl;
        return ans;
    }
};