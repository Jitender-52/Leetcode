class Solution {
public:
    
     vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        int a = 0;
        int b = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] < target)
                a++;
            else if(nums[i] == target)
                b++;
        }
        
        vector<int> ans;
        for(int i = 0; i < b; i++)
        {
            ans.push_back(a);
            a++;
        }
        return ans;
    }
};
    
    
//     Runtime: 8 ms, faster than 53.51% of C++ online submissions for Find Target Indices After Sorting Array.
// Memory Usage: 11.8 MB, less than 22.89% of C++ online submissions for Find Target Indices After Sorting Array.

    
    // vector<int> targetIndices(vector<int>& nums, int target) {
    //     int n = nums.size();
    //     sort(nums.begin(), nums.end());
    //     vector<int> ans;
    //     for(int i = 0; i < n; i++)
    //     {
    //         while(i < n && nums[i] == target)
    //             ans.push_back(i++);
    //     }
    //     return ans;
    // }
    
// };