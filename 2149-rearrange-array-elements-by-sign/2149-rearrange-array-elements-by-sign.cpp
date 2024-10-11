class Solution {
public:
    
//     Runtime: 135 ms, faster than 91.67% of C++ online submissions for Rearrange Array Elements by Sign.
// Memory Usage: 143 MB, less than 5.30% of C++ online submissions for Rearrange Array Elements by Sign.
    
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos;
        vector<int> neg;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] < 0)
                neg.push_back(nums[i]);
            else
                pos.push_back(nums[i]);
        }
        
        int i = 0;
        vector<int> ans;
        while(i < pos.size())
        {
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
            i++;
        }
        return ans;        
    }
};