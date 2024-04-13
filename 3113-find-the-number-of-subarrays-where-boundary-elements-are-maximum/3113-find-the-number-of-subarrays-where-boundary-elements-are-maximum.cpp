class Solution {
public:
    
//     Runtime: 146 ms, faster than 100.00% of C++ online submissions for Find the Number of Subarrays Where Boundary Elements Are Maximum.
// Memory Usage: 110.8 MB, less than 100.00% of C++ online submissions for Find the Number of Subarrays Where Boundary Elements Are Maximum.
    
    long long numberOfSubarrays(vector<int>& nums) {
        int n = nums.size();
        stack<pair<int,int>> st;
        long long ans = 0;
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && nums[i] > st.top().first)
                st.pop();
            if(!st.empty() && st.top().first == nums[i])
                st.top().second++;
            else
                st.push({nums[i], 1});
            ans += st.top().second;
        }
        return ans;
    }
};
    
    
//     long long numberOfSubarrays(vector<int>& nums) {
//         int n = nums.size();
//         long long ans = 0;
//         stack<int> st;
        
//         vector<int> v(n);
//         for(int i = 0; i < n; i++)
//         {
//             if(!st.empty())
//             {
//                 while(!st.empty() && nums[st.top()] <= nums[i])
//                     st.pop();
//                 if(st.empty())
//                     v[i] = -1;
//                 else
//                     v[i] = st.top();
//             }
//             st.push(i);
//         }
        
//         unordered_map<int, vector<int>> mp;
//         for (int i = 0; i < n; i++)
//         {
//             mp[nums[i]].push_back(i);
//         }

//         for (int i = 0; i < n; i++)
//         {
//             int ub = upper_bound(mp[nums[i]].begin(), mp[nums[i]].end(), i) - mp[nums[i]].begin();
//             int lb = lower_bound(mp[nums[i]].begin(), mp[nums[i]].end(), v[i]) - mp[nums[i]].begin();
//             ans += (ub - lb);
//         }

        
//         // for(int i = 0; i < n; i++)
//         // {
//         //     if(st.empty())
//         //     {
//         //         st.push(nums[i]);
//         //         continue;
//         //     }
//         //     int maxi = 0;
//         //     map<int,int> mp;
//         //     while(!st.empty() && st.top() < nums[i])
//         //     {
//         //         if(maxi == -1)
//         //         {
//         //             maxi = st.top();
//         //             st.pop();
//         //             mp.clear();
//         //             mp[maxi]++;
//         //             continue;
//         //         }
//         //         if(st.top() > maxi)
//         //         {
//         //             ans += (mp[maxi] * 1LL * (mp[maxi] + 1)) / 2;
//         //             maxi = nums[i];
//         //             mp.clear();
//         //             st.pop();
//         //         }
//         //         else
//         //         {
//         //             mp[st.top()]++;
//         //             st.pop();
//         //         }
//         //     }
//         //     st.push(nums[i]);
//         // }
//         return ans;
//     }
// };