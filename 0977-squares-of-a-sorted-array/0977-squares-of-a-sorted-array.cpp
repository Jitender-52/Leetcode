class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n-1;
        while(i < n && nums[i] < 0)
            i++;
        while(j >= 0 && nums[j] >= 0)
            j--;
        vector<int> ans;
        while(i < n && j >= 0)
        {
            if(nums[i] <= abs(nums[j]))
            {
                ans.push_back(nums[i] * nums[i]);
                i++;
            }
            else
            {
                ans.push_back(nums[j] * nums[j]);
                j--;
            }
        }
        while(i < n)
        {
            ans.push_back(nums[i] * nums[i]);
            i++;
        }
        while(j >= 0)
        {
            ans.push_back(nums[j] * nums[j]);
            j--;
        }
        return ans;
    }
};