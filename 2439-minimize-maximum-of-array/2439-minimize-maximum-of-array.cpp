class Solution {
public:
    
        int minimizeArrayValue(vector<int>& nums) {
            int n = nums.size();
            long long sum = 0;
            int ans = 0;
            for(int i = 0; i < n; i++)
            {
                sum += nums[i];
                ans = max(ans, (int)(ceil(double(sum) / (i+1))));
            }
            return ans;
        }
};
    
    
    
//     int minimizeArrayValue(vector<int>& nums) {
//         int n = nums.size();
//         double sum = 0;
//         double ans = 0;
        
//         for(int i = 0; i < n; i++)
//         {
//             sum += nums[i];
//             // int a = sum / ()
//             ans = max(ans, ceil(sum / (i+1)));
//         }
//         return ans;
//     }
// };