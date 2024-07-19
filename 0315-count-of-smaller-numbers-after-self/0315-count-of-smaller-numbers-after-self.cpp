class Solution {
public:
    
    int search(int key, vector<int> &v)
    {
        int low = 0, high = v.size() - 1;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(v[mid] >= key)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return high + 1;
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        vector<int> ans(n, 0);
        for(int i = n-1; i >= 0; i--)
        {
            int idx = search(nums[i], v);
            ans[i] = idx;
            v.insert(v.begin() + idx, nums[i]);
        }
        return ans;
    }
};
    
    
//     Runtime: 1420 ms, faster than 9.10% of C++ online submissions for Count of Smaller Numbers After Self.
// Memory Usage: 87.8 MB, less than 98.60% of C++ online submissions for Count of Smaller Numbers After Self.
    
//     vector<int> countSmaller(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> v = nums;
//         sort(v.begin(), v.end());
//         vector<int> ans(n, 0);
//         for(int i = 0; i < n; i++)
//         {
//             auto it = lower_bound(v.begin(), v.end(), nums[i]);
//             v.erase(it);
//             ans[i] = it - v.begin();
//         }
//         return ans;
//     }
// };