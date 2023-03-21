class Solution {
public:
    
        long long zeroFilledSubarray(vector<int>& nums) {
            int n = nums.size();
            int count = 0;
            long long ans = 0;
            for(int i = 0; i < n; i++)
                nums[i] == 0 ? count++, ans += count : count = 0; 
            return ans;
        }
};
    
    
//     long long nC2(long long n)
//     {
//         return (n*(n+1))/2;
//     }
    
//     long long zeroFilledSubarray(vector<int>& nums) {
//         int n = nums.size();
//         bool check = false;
//         long long count = 0;
//         long long ans = 0;
//         for(int i = 0; i < n; i++)
//         {
//             if(nums[i] == 0 && !check)
//             {
//                 check = true;
//                 count = 0;
//             }
//             else if(nums[i] != 0 && check)
//             {
//                 check = false;
//                 ans += nC2(count);
//                 count = 0;
//             }
//             if(nums[i] == 0)
//             {
//                 count++;
//             }
//         }
//         ans += nC2(count);
//         return ans;
//     }
// };