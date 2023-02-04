class Solution {
public:
    
    void permute(int idx, vector<int> &v, vector<vector<int>> &ans)
    {
        int n = v.size();
        if(idx >= n)
            return;
        
        // if(idx > 0 && v[idx] == v[idx-1])
        // {
        //     permute(idx+1, v, ans);
        //     return;
        // }
        
        ans.push_back(v);
        for(int i = 0; i < n; i++)
        {
            if(i > 0 && v[i] == v[i-1])
                continue;
            swap(v[idx], v[i]);
            permute(idx+1, v, ans);
            swap(v[idx], v[i]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        permute(0, nums, ans);
        sort(ans.begin(), ans.end());
         ans.erase(unique(ans.begin(), ans.end()), ans.end());
        // ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};

//   void nextPermutation(vector<int> &v)
// {
//     int n = v.size();
//     int idx = -1;
//     for (int i = n - 2; i >= 0; i--)
//     {
//         if (v[i] < v[i + 1])
//         {
//             idx = i;
//             break;
//         }
//     }
//     if (idx == -1)
//     {
//         sort(v.begin(), v.end());
//         return;
//     }
    
//     sort(v.begin() + idx + 1, v.end());

//     for (int i = idx; i < n; i++)
//     {
//         if (v[i] > v[idx])
//         {
//             swap(v[i], v[idx]);
//             return;
//         }
//     }
// }

// vector<vector<int>> permuteUnique(vector<int> &nums)
// {
//     sort(nums.begin(), nums.end());
//     vector<vector<int>> ans;
//     nextPermutation(nums);
//     ans.push_back(nums);

//     vector<int> v = nums;
//     do
//     {
//         nextPermutation(v);
//         ans.push_back(v);
//     } while (ans[0] != v);
//     ans.pop_back();
//     return ans;
// }
// };