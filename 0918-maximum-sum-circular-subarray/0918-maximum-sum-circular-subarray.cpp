class Solution {
public:
    
    
    // copy paste for streak

//     Runtime: 75 ms, faster than 67.96% of C++ online submissions for Maximum Sum Circular Subarray.
// Memory Usage: 41.6 MB, less than 13.60% of C++ online submissions for Maximum Sum Circular Subarray.
    
    int maxSubarraySumCircular(vector<int>& nums) {
        const int n = nums.size();
        vector<int> right_max(n);
        right_max[n - 1] = nums[n - 1];
        for (int suffix_sum = nums[n - 1], i = n - 2; i >= 0; --i) {
            suffix_sum += nums[i];
            right_max[i] = max(right_max[i + 1], suffix_sum);
        }
        int max_sum = nums[0];
        int special_sum = nums[0];
        for (int i = 0, suffix_sum = 0, curMax = 0; i < n; ++i) {
            curMax = max(curMax, 0) + nums[i];
            // This is Kadane's algorithm.
            max_sum = max(max_sum, curMax);
            suffix_sum += nums[i];
            if (i + 1 < n) {
                special_sum = max(special_sum, suffix_sum + right_max[i + 1]);
            }
        }
        return max(max_sum, special_sum);
    }
};
    
    
//     int maxSubarraySumCircular(vector<int>& nums) {
//         int n = nums.size();
//         int sum = 0;
//         int last = -1;
//         int ans = INT_MIN;
//         for(int i = 0; i < n; i++)
//         {
//             sum += nums[i];
//             ans = max(ans, sum);
//             if(sum < 0)
//             {
//                 sum = 0;
//                 last = i;
//             }
//         }
        
//         cout << last << endl;
//         for(int i = 0; i < n; i++)
//         {
//             if(i == last+1)
//                 break;
//             sum += nums[i];
//             ans = max(ans, sum);
//             if(sum < 0)
//                 break;
//             if(i > 0)
//                 break;
//         }
//         return ans;
//     }
// };