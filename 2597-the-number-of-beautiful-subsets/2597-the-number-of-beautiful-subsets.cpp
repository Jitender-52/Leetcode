class Solution {
public:
    
    
//     Runtime: 252 ms, faster than 84.10% of C++ online submissions for The Number of Beautiful Subsets.
// Memory Usage: 32.4 MB, less than 83.39% of C++ online submissions for The Number of Beautiful Subsets.

    
        int subsets(int i, vector<int> &nums, int k, vector<int> &v)
    {
        int n = nums.size();
        if(i == n)
            return 1;
        int ans = 0;

        ans += subsets(i+1, nums, k, v);

        if(nums[i] - k > 0)
        { 
            if(v[nums[i] - k] == 0)
            {
                v[nums[i]] = 1;
                ans += subsets(i+1, nums, k, v);  
                v[nums[i]] = 0;
            }
        }
        else
        {
            v[nums[i]] = 1;
            ans += subsets(i+1, nums, k, v);
            v[nums[i]] = 0;
        }
        return ans;
    }
    
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> v(1002,0); 
        // int v[1002];
        // memset(v, 0, sizeof(v));
        for(int i = 0; i < 1002; i++)
        {
            v[i] = 0;
        }
        return subsets(0, nums, k, v) - 1;
    }
};
    
    
//     int subsets(int i, map<int,int> mp, vector<int> &nums, vector<int> &dp)
//     {
        
//     }
    
//     int beautifulSubsets(vector<int>& nums, int k) {
//         int n = nums.size();
        
//         // sort(v.begin(), v.end());
//         // vector<int> dp(n+1, -1);
        
//         vector<map<int,int>> v;
        
//         // vector<map<int,int>> v(1001);
        
//         for(int i = 0; i < n; i++)
//         {
//             for(int j = 0; j < v.size(); j++)
//             {
//                 auto mp = v[j];
//                 if(mp.find(nums[i] - k) == mp.end())
//                 {
//                     mp[nums[i]]++;
//                 }
//                 v[j] = mp;
//             }
//             map<int,int> mp;
//             mp[nums[i]]++;
//             v.push_back(mp);
//         }
        
// //          for(int i = 0; i < n; i++)
// //         {
             
// //              map<int,int> mp;
             
             
// //             // for(int j = 0; j < v.size(); j++)
// //             // {
// //             //     auto mp = v[j];
// //             //     if(mp.find(nums[i] - k) == mp.end())
// //             //     {
// //             //         mp[nums[i]]++;
// //             //     }
// //             // }
// //             // map<int,int> mp;
// //             // mp[nums[i]]++;
// //             // v.push_back(mp);
// //         }
        
//         int ans = 0;
        
//         vector<int> vis(1e3 + 5, 0);
        
//         for(int i = 0; i < v.size(); i++)
//         {
//             int count = 0;
//             auto mp = v[i];
//             for(auto i : mp)
//             {
//                 // if()
//                 // cout << i.first << " " << i.second << endl;
//                 count += i.second;
//             }
//             // cout << ans << endl;
//             ans += pow(2, count-1);
//         }
        
//         return ans;
        
// //         for(int i = 0; i < n ;i++)
// //         {
            
// //         }
//     }
// };