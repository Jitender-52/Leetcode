class Solution {
public:
    
//     Runtime: 161 ms, faster than 84.99% of C++ online submissions for Minimize the Maximum Difference of Pairs.
// Memory Usage: 81.1 MB, less than 82.46% of C++ online submissions for Minimize the Maximum Difference of Pairs.
    
    bool isFeasible(vector<int> &nums, int p, int mid)
    {
        int n = nums.size();
        int count = 0;
        for(int i = 1; i < n; i++)
        {
            if(nums[i] - nums[i-1] <= mid)
            {
                count++;
                i++;
            }
        }
        return count >= p;
    }
    
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int low = 0, high = 1e9;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(isFeasible(nums, p, mid))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return high + 1;
    }
};
    
//     bool isFeasible(int val, int p, vector<int> &nums)
//     {
//         int n = nums.size();
//         int count = 0;
//         for(int i = 1; i < n; i++)
//         {
//             if(nums[i] - nums[i-1] <= val)
//             {
//                 count++;
//                 i++;
//             }
//         }
//         // cout << count << endl;
//         return count >= p;
//     }
    
//     int minimizeMax(vector<int>& nums, int p) {
//         int n = nums.size();
//         // vector<int> v(n);
//         if(p == 0)
//             return 0;
//         sort(nums.begin(), nums.end());
//         // for(int i = 1; i < n; i++)
//         // {
//         //     v[i-1] = nums[i] - nums[i-1];
//         // }
//         // // v[0] = INT_MAX;
//         // sort(v.begin(), v.end());
//         // return v[p];
        
//         int low = 0;
//         int high = 1e9;
//         int ans = 1e9;
        
//         while(low <= high)
//         {
//             int mid = (low + high) / 2;
//             // cout << mid << " = " << endl;
//             if(isFeasible(mid, p, nums))
//             {
//                 ans = min(ans, mid);
//                 high = mid - 1;
//             }
//             else
//             {
//                 low = mid + 1;
//             }
            
//         }
//         return ans;
//     }
// };