class Solution {
public:
    
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n+1, 0);
        for(auto i : nums)
            v[i]++;
        int maxi = *max_element(v.begin(), v.end());
        vector<vector<int>> ans(maxi);
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j < v[i]; j++)
                ans[j].push_back(i);
        }
        return ans;
    }
};
    
//     Runtime: 27 ms, faster than 5.95% of C++ online submissions for Convert an Array Into a 2D Array With Conditions.
// Memory Usage: 29.9 MB, less than 70.96% of C++ online submissions for Convert an Array Into a 2D Array With Conditions.
    
//     vector<vector<int>> findMatrix(vector<int>& nums) {
//         int n = nums.size();
//         map<int,int> mp;
//         int maxi = 0;
//         for(int i = 0; i < n; i++)
//         {
//             mp[nums[i]]++;
//             maxi = max(maxi, mp[nums[i]]);
//         }
//         vector<vector<int>> ans(maxi);
//         for(auto i : mp)
//         {
//             for(int j = 0; j < i.second; j++)
//                 ans[j].push_back(i.first);
//         }
//         return ans;
//     }
// };