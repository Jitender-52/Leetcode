class Solution {
public:
    
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        vector<pair<int,int>> v;
        for(int i = 0; i < n; i++)
        {
            v.push_back({nums[i], cost[i]});
        }
        
        int l = *min_element(nums.begin(), nums.end());
        int r = *max_element(nums.begin(), nums.end());
        
        auto find = [&](int mid)
        {
            long long sum = 0;
            for(int i = 0; i < n; i++)
            {
                sum += abs(mid - nums[i])* 1LL * cost[i];
            }
            return sum;
        };
        
        long long ans = 1e18;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            long long sum1 = find(mid);
            long long sum2 = find(mid+1);
            ans = min(sum1, sum2);
            if(sum1 > sum2)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return ans;
    }
};
    
    
    
//     long long minCost(vector<int>& nums, vector<int>& cost) {
//         int n = nums.size();
//         vector<pair<int,int>> v;
//         for(int i = 0; i < n; i++)
//         {
//             v.push_back({nums[i], cost[i]});
//         }
        
//         sort(v.begin(), v.end());
//         long long l = nums[0], r = nums[n-1];
        
//         long long ans = 1e18;
//         set<long long> st;
//         long long maxi = 0;
//         while(l < r)
//         {
//             long long mid = (l + r) / 2;
//             long long sum1 = 0, sum2 = 0;
//             for(int i = 0; i < n; i++)
//             {
//                 if(nums[i] < mid)
//                     sum1 += (mid - nums[i]) * 1LL * cost[i];
//                 else
//                     sum2 += (nums[i] - mid) * 1LL * cost[i];
//             }
            
// //             if(mid <= maxi)
// //                 break;
            
//             // if(st.find(mid) != st.end())
//             //     break;
//             // st.insert(mid);
            
//             ans = min(ans, sum1 + sum2);
//             if(sum1 <= sum2)
//             {
//                 l++;
//             }
//             else
//             {
//                 maxi = mid;
//                 r++;
//             }
//         }
//         return ans;
//     }
// };