class Solution {
public:
    
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            int x = abs(nums[i]);
            int idx = x-1;
            if(nums[idx] < 0)
                ans.push_back(x);
            nums[idx] *= -1;
        }
        return ans;
    }
};  
    
//     Runtime: 137 ms, faster than 5.17% of C++ online submissions for Find All Duplicates in an Array.
// Memory Usage: 49.1 MB, less than 8.67% of C++ online submissions for Find All Duplicates in an Array.

    
//     vector<int> findDuplicates(vector<int>& nums) {
//         map<int, int> mp;
//         vector<int> v;
//         for(int i = 0; i < nums.size(); i++)
//         {
//             mp[nums[i]]++;
//             if(mp[nums[i]] == 2)
//             {
//                 v.push_back(nums[i]);
//             }
//         }
        
//         return v;
//     }
// };