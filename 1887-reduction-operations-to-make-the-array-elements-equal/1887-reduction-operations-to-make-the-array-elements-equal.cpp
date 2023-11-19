class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int count = 0, ans = 0;
        for(int i = 1; i < n; i++)
        {
            if(nums[i] != nums[i-1])
            {
                count++;
            }
            ans += count;
        }
        return ans;
    }
};