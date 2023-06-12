class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;
        if(n == 0)
            return ans;
        int start = nums[0];
        int end = start;
        for(int i = 1; i < n; i++)
        {
            if(nums[i] != end + 1)
            {
                if(start == end)
                    ans.push_back(to_string(start));
                else 
                    ans.push_back(to_string(start) + "->" + to_string(end));
                start = nums[i];
                end = nums[i];
            }
            else
            {
                end++;
            }
        }
        if(start == end)
            ans.push_back(to_string(start));
        else 
            ans.push_back(to_string(start) + "->" + to_string(end));
        return ans;
    }
};