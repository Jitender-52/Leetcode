class Solution {
public:
    
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] % 2 == 0)
                ans.push_back(nums[i]);
        }
        for(int i = 0; i < n; i++)
        {
            if(nums[i] % 2 == 1)
                ans.push_back(nums[i]);
        }
        return ans;
    }
};
    
    
//     Runtime: 10 ms, faster than 32.57% of C++ online submissions for Sort Array By Parity.
// Memory Usage: 16.5 MB, less than 36.74% of C++ online submissions for Sort Array By Parity.
    
//     vector<int> sortArrayByParity(vector<int>& nums) {
//         sort(nums.begin(), nums.end(), [&](int a, int b){
//             return (a % 2 == 0 && b % 2 == 1);
//         });
//         return nums;
//     }
// };