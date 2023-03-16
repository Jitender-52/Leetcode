class Solution {
public:
    
    
    void subsets(int i, vector<int> &nums, vector<int> v, vector<vector<int>> &ans)
        {
            int n = nums.size();
            ans.push_back(v);
            if(i >= n)
                return;
            subsets(i+1, nums, v, ans);
            v.push_back(nums[i]);
            subsets(i+1, nums, v, ans);
        }
    
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            vector<vector<int>> ans;
            vector<int> v;
            subsets(0, nums, v, ans);
            
            sort(ans.begin(), ans.end());
            ans.erase(unique(ans.begin(), ans.end()), ans.end());
            return ans;
        }
};
    
    
//     Runtime: 14 ms, faster than 10.96% of C++ online submissions for Subsets II.
// Memory Usage: 17.3 MB, less than 11.66% of C++ online submissions for Subsets II.
     
//         void subsets(int i, vector<int> &nums, vector<int> v, set<vector<int>> &ans)
//         {
//             int n = nums.size();
//             ans.insert(v);
//             if(i >= n)
//                 return;
//             subsets(i+1, nums, v, ans);
//             v.push_back(nums[i]);
//             subsets(i+1, nums, v, ans);
//         }
    
//         vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//             int n = nums.size();
//             sort(nums.begin(), nums.end());
//             set<vector<int>> ans;
//             vector<int> v;
//             subsets(0, nums, v, ans);
            
//             vector<vector<int>> v1;
//             for(auto i : ans)
//             {
//                 v1.push_back(i);
//             }
//             return v1;
//         }
// };
    
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         int n = nums.size();
//         set<vector<int>> st;
//         vector<vector<int>> ans;
//         for(int i = 0; i < n; i++)
//         {
//             vector<int> v;
//             st.insert(v);
//             for(int j = i; j < n; j++)
//             {
//                 v.push_back(nums[j]);
//                 st.insert(v);
//             }
//         }
//         for(auto i : st)
//             ans.push_back(i);
//         return ans;
//     }
// };