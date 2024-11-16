class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i + k <= n; i++)
        {
            bool check = true;
            for(int j = i+1; j < i + k; j++)
            {
                if(nums[j] != nums[j-1] + 1)
                {
                    check = false;
                    break;
                }
            }
            if(check)
                ans.push_back(nums[i+k-1]);
            else
                ans.push_back(-1);
        }
        return ans;
    }
};