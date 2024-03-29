class Solution {
public:
    
//     Runtime: 122 ms, faster than 82.95% of C++ online submissions for Count Subarrays Where Max Element Appears at Least K Times.
// Memory Usage: 120.1 MB, less than 62.40% of C++ online submissions for Count Subarrays Where Max Element Appears at Least K Times.
    
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        int i = 0, j = 0;
        int maxi = *max_element(nums.begin(), nums.end());
        int count = 0;
        while(i < n && j < n)
        {
            if(nums[i] == maxi)
                count++;
            while(j < n && count >= k)
            {
                if(nums[j] == maxi)
                    count--;
                ans += 1LL * (n - i);
                j++;
            }
            i++;
        }
        return ans;
    }
};
    
//     long long countSubarrays(vector<int>& nums, int k) {
//         vector<int> v = nums;
//         // v.push_back(1e9);
//         int n = nums.size();
//         long long ans = 0;
        
//         int i = 0, j = 0;
//         map<int, int> mp;
//         int maxi = *max_element(v.begin(), v.end());
//         while(j < n && i < n)
//         {
//             mp[v[i]]++;
//             while(j < n && mp[maxi] >= k)
//             {
//                 ans += n - i;
//                 mp[v[j]]--;
//                 j++;
//             }
//             i++;
//         }
//         return ans;
//     }
// };