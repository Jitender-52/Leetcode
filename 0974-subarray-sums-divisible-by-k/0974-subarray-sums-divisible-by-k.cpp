class Solution {
public:
    
//     Just copy paste for the streak
    
    
//     Runtime: 45 ms, faster than 93.71% of C++ online submissions for Subarray Sums Divisible by K.
// Memory Usage: 30.1 MB, less than 94.47% of C++ online submissions for Subarray Sums Divisible by K.

    
    
       int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int prefixMod = 0, result = 0;

        // There are k mod groups 0...k-1.
        vector<int> modGroups(k);
        modGroups[0] = 1;

        for (int num : nums) {
            // Take modulo twice to avoid negative remainders.
            prefixMod = (prefixMod + num % k + k) % k;
            // Add the count of subarrays that have the same remainder as the current
            // one to cancel out the remainders.
            result += modGroups[prefixMod];
            modGroups[prefixMod]++;
        }

        return result;
    }
};
    
    
    
    
//     int subarraysDivByK(vector<int>& nums, int k) {
//         int n = nums.size();
//         int ans = 0;
//         for(int i = 0; i < n; i++)
//         {
//             int sum = 0;
//             for(int j = i; j < n; j++)
//             {
//                 sum += nums[j];
//                 if(sum % k == 0)
//                     ans++;
//             }
//         }
//         return ans;
        
        
//         // int sum = 0;
//         // map<int,int> mp;
//         // int ans = 0;
//         // for(int i = 0; i < n; i++)
//         // {
//         //     if(nums[i] > 0)
//         //         sum += nums[i];
//         //     else
//         //         sum += (k + (abs(nums[i]) % k));
//         //     sum = sum % k;
//         //     cout << i << " " << sum << " " << mp[sum] << endl;
//         //     ans += mp[sum];
//         //     cout << ans << endl;
//         //     mp[sum]++;
//         // }
//         // return ans;
//     }
// };