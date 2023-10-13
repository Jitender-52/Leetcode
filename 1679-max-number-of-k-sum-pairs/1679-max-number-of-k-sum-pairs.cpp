class Solution {
public:
    
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0, j = n-1, ans = 0;
        while(i < j)
        {
            if(nums[i] + nums[j] == k)
            {
                ans++;
                i++;
                j--;
            }
            else if(nums[i] + nums[j] > k)
                j--;
            else
                i++;
        }
        return ans;
    }
};
    
//     Runtime: 175 ms, faster than 7.72% of C++ online submissions for Max Number of K-Sum Pairs.
// Memory Usage: 70.7 MB, less than 21.84% of C++ online submissions for Max Number of K-Sum Pairs.
    
//     int maxOperations(vector<int>& nums, int k) {
//         int n = nums.size();
//         map<int,int> mp;
//         int ans = 0;
//         for(int i = 0; i < n; i++)
//         {
//             if(mp.find(k - nums[i]) != mp.end())
//             {
//                 mp[k - nums[i]]--;
//                 if(mp[k-nums[i]] == 0)
//                     mp.erase(k - nums[i]);
//                 ans++;
//             }
//             else
//             {
//                 mp[nums[i]]++;
//             }
//         }
//         return ans;
//     }
// };