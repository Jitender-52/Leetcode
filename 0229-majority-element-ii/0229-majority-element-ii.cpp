class Solution {
public:
    
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int y = INT_MIN, z = INT_MIN, cy = 0, cz = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == y)
                cy++;
            else if(nums[i] == z)
                cz++;
            else if(!cy)
                y = nums[i], cy = 1;
            else if(!cz)
                z = nums[i], cz = 1;
            else
                cy--, cz--;
        }
        
        cy = 0, cz = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == y)
                cy++;
            if(nums[i] == z)
                cz++;
        }
        
        vector<int> ans;
        if(cy > n/3)
            ans.push_back(y);
        if(cz > n/3)
            ans.push_back(z);
        return ans;
    }
};
    
    
//     Runtime: 7 ms, faster than 87.90% of C++ online submissions for Majority Element II.
// Memory Usage: 16.4 MB, less than 9.38% of C++ online submissions for Majority Element II.
    
//     vector<int> majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());
//         vector<int> ans;
//         for(int i = 0; i < n; i++)
//         {
//             int count = 0, a = nums[i];
//             while(i < n && nums[i] == a)
//             {
//                 count++;
//                 i++;
//             }
//             if(count > n/3)
//                 ans.push_back(nums[i-1]);
//             i--;
//         }
//         return ans;
//     }
// };