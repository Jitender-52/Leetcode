class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            int count = 0, a = nums[i];
            while(i < n && nums[i] == a)
            {
                count++;
                i++;
            }
            if(count > n/3)
                ans.push_back(nums[i-1]);
            i--;
        }
        return ans;
    }
};