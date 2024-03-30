class Solution {
public:
    
    int solve(vector<int> &nums, int k)
    {
        int n = nums.size();
        map<int,int> mp;
        int ans = 0;
        int i = 0, j = 0;
        while(i < n && j < n)
        {
            mp[nums[i]]++;
            while(mp.size() > k)
            {
                mp[nums[j]]--;
                if(mp[nums[j]] == 0)
                    mp.erase(nums[j]);
                j++;
            }
            ans += i - j;
            i++;
        }
        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        return solve(nums, k) - solve(nums, k-1);
    }
};
    
    
//     int subarraysWithKDistinct(vector<int>& nums, int k) {
//         int n = nums.size();
//         int i = 0, j = 0, ans = 0;
//         map<int,int> mp;
//         while(i < n && j < n)
//         {
//             cout << i << " " << j << endl;
//             while(i < n && mp.size() < k)
//             {
//                 mp[nums[i]]++;
//                 i++;
//             }
//             int count1 = 0, count2 = 0;
//             while(i < n && mp.find(nums[i]) != mp.end())
//             {
//                 mp[nums[i]]++;
//                 count1++;
//                 i++;
//             }
//             while(j < n && mp[nums[j]] > 1)
//             {
//                 mp[nums[j]]--;
//                 count2++;
//                 j++;
//             }
            
//             while(j < n && mp.size() >= k)
//             {
//                 mp[nums[j]]--;
//                 if(mp[nums[j]] == 0)
//                     mp.erase(nums[j]);
//                 j++;
//             }
//             cout << i << " " << j << " " << count1 << " " << count2 << endl;
//             ans += count1 + 1 + count2 + 1;
//         }
//         return ans;
//     }
// };
    
    
//     int subarraysWithKDistinct(vector<int>& nums, int k) {
//         int n = nums.size();
//         int i = 0, j = 0;
//         map<int,int> mp;
        
//         for(int i = 0; i < k; i++)
//             mp[nums[i]]++;
        
//         int ans = 0;
//         // if(mp.size() == k)
//         //     ans++;
    
//         for(int i = k; i < n; i++)
//         {
//             mp[nums[i]]++;
//             j = i - k;
//             if(mp.size() == k)
//                 ans++;
//             while(j >= 0)
//             {
//                 mp[nums[j]]--;
//                 if(mp[nums[j]] == 0)
//                     mp.erase(nums[j]);
//                 if(mp.size() == k)
//                     ans++;
//                 j--;
//             }
//             for(int x = j+1; x <= i-k; x++)
//                 mp[nums[x]]++;
//         }
//         return ans;
        
//         // for(int i = 0; i < n; i++)
//         // {
//         //     mp[nums[i]];
//         //     if(mp.size() == k)
//         //     {
//         //         ans++;
//         //     }
//         //     int last = j;
//         //     if(mp.size() == k)
//         //         ans++;
//         //     while(mp.size() >= k)
//         //     {
//         //         mp[nums[j]]--;
//         //         if(mp[nums[j]] == 0)
//         //             mp.erase(nums[j]);
//         //         if(mp.size() == k)
//         //             ans++;
//         //         j++;
//         //     }
//         // }
//     }
// };