class Solution {
public:
    
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        set<int> st;
        for(auto i : nums)
            st.insert(i);
        vector<int> v;
        for(auto i : st)
        {
            // cout << i << " ";
            v.push_back(i);
        }
        // cout << endl;
        
        int m = v.size();
        
        int j = 0;
        int ans = 0;
        for(int i = 0; i < m; i++)
        {
            int l = v[i], r = v[i] + n;
            // cout << l << " " << r << endl;
            while(j < m && v[j] < r)
            {
                j++;
            }
            // cout << i << " " << j << endl;
            // if(j < n)
            //     cout << i << " " << j << " " << nums[i] << " " << nums[j] << endl;
            ans = max(ans, j - i);
        }
        return nums.size() - ans;
    }
};
    
//     int find(vector<int> &nums, int mid)
//     {
        
//     }
    
//     int minOperations(vector<int>& nums) {
//         int n = nums.size();
//         int l = *min_element(nums.begin(), nums.end());
//         int r = *max_element(nums.begin(), nums.end());
        
//         int ans = n;
//         while(l <= r)
//         {
//             int mid = (l + r) / 2;
//             int f = find(nums, mid);
//             if(f <= ans)
//             {
//                 ans = f;
//                 r = mid - 1;
//             }
//             else
//             {
//                 l = mid + 1;
//             }
//         }
//         return ans;
//     }
// };