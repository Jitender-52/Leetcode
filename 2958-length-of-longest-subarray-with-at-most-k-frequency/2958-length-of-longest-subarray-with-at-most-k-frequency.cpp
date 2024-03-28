class Solution {
public:
    
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        map<int,int> mp;
        int ans = 0;
        while(j < n && i < n)
        {
            mp[nums[i]]++;
            while(mp[nums[i]] > k)
            {
                mp[nums[j]]--;
                j++;
            }
            ans = max(ans, i - j + 1);
            i++;
        }
        return ans;
    }
};
    
    
//     Runtime: 379 ms, faster than 8.41% of C++ online submissions for Length of Longest Subarray With at Most K Frequency.
// Memory Usage: 148.5 MB, less than 33.73% of C++ online submissions for Length of Longest Subarray With at Most K Frequency.
    
//     int maxSubarrayLength(vector<int>& nums, int k) {
//         int n = nums.size();
//         int i = 0, j = 0;
//         int check = 0;
//         map<int,int> mp;
//         int ans = 0;
//         while(j < n && i < n)
//         {
//             mp[nums[i]]++;
//             if(mp[nums[i]] > k)
//                 check++;
//             while(check > 0 && j <= i)
//             {
//                 if(mp[nums[j]] == k+1)
//                     check--;
//                 mp[nums[j]]--;
//                 j++;
//             }
//             // cout << i << " " << j << endl;
//             ans = max(ans, i - j + 1);
//             i++;
//         }
//         // cout << endl;
//         return ans;
//     }
// };