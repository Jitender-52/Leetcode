class Solution {
public:
    
    int minSubArrayLen(int target, vector<int>& nums) {
     
         int n = nums.size();
         int sum = 0;
         int start = 0;
         int end = 0;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            // if(sum == target)
            // {
            //     return i + 1;
            // }
            if(sum >= target)
            {
                start = 0;
                end = i + 1;
                break;
            }
            if(i == n-1)
            {
                return 0;
            }
        }
         
         int ans = end;
         for(int i = end; i < n; i++)
         {
             sum = sum + nums[i] - nums[start];
             start++;
             if(sum >= target)
             {
                 while(sum - nums[start] >= target)
                 {
                     sum = sum - nums[start];
                     ans--;
                    start++;
                 }
             }
         }
         // cout << n << " " << sum << endl;
         while(sum - nums[start] >= target)
                 {
                     sum = sum - nums[start];
                     ans--;
                    start++;
                 }
         return ans;
     }    
};
    
    
//     int minSubArrayLen(int target, vector<int>& nums) {
//         int n = nums.size();
//         int ans = 1e6;
//         int sum = 0, i, j = 0;
//         for(i = 0; i < n; i++)
//         {
//             sum += nums[i];
//             if(sum >= target)
//             {
//                 ans = min(ans, i - j);
//             }
//             while(j < i && sum >= target)
//             {
//                 sum -= nums[j];
//                 j++;
//             }
//             if(sum >= target)
//             {
//                 ans = min(ans, i - j + 1);
//             }
//         }
//         return ans == 1e6 ? 0 : ans;
//     }
// };

// 11
// [1,2,3,4,5]